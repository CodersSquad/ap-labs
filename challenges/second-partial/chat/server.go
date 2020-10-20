// Copyright © 2016 Alan A. A. Donovan & Brian W. Kernighan.
// License: https://creativecommons.org/licenses/by-nc-sa/4.0/

// See page 254.
//!+

// Chat is a server that lets clients chat with each other.
package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
	"strings"
	"time"
)

//!+broadcaster
type client struct {
	ch       chan<- string
	username string
	conn     net.Conn
}

type command struct {
	cli client
	cmd []string
}

var (
	entering = make(chan client)
	leaving  = make(chan client)
	messages = make(chan string) // all incoming client messages
	commands = make(chan command)
)

func broadcaster() {
	clients := make(map[client]string) // all connected clients
	users := make(map[string]client)
	admins := make(map[string]client)
	for {
		select {
		case msg := <-messages:
			// Broadcast incoming message to all
			// clients' outgoing message channels.
			for cli := range clients {
				cli.ch <- msg
			}

		case cli := <-entering:
			if len(admins) == 0 && len(users) == 0 {
				admins[cli.username] = cli
				cli.ch <- "irc-server > Congrats, you were the first user."
				cli.ch <- "irc-server > You're the new IRC Server ADMIN"
				fmt.Println("irc-server > [" + cli.username + "] was promoted as the channel ADMIN")
			}
			clients[cli] = cli.username
			users[cli.username] = cli

		case cli := <-leaving:
			_, notKicked := users[cli.username]
			if notKicked {
				fmt.Println("irc-server > [" + cli.username + "] left")
				for cl := range clients {
					cl.ch <- "irc-server > [" + cli.username + "] left channel"
				}

				_, isAnAdmin := admins[cli.username]
				if isAnAdmin {
					delete(admins, cli.username)
				}

				delete(clients, cli)
				delete(users, cli.username)
				close(cli.ch)

				if len(admins) == 0 && len(users) > 0 {
					for cli := range clients {
						admins[cli.username] = cli
						fmt.Println("irc-server > [" + cli.username + "] was promoted to admin")
						cli.ch <- "irc-server > You're the new IRC Server admin."
						break
					}
				}
			}

		case entry := <-commands:
			if entry.cmd[0] == "users" {
				usersTxt := ""
				for user := range users {
					usersTxt = usersTxt + user + ", "
				}
				entry.cli.ch <- "irc-server > " + usersTxt[:len(usersTxt)-2]

			} else if entry.cmd[0] == "time" {
				entry.cli.ch <- "irc-server > Local Time: America/Mexico_City " + time.Now().Format("15:04")

			} else if entry.cmd[0] == "user" && len(entry.cmd) == 2 {
				user, isIn := users[entry.cmd[1]]
				if isIn {
					entry.cli.ch <- "irc-server > username: " + user.username + ", IP: " + user.conn.RemoteAddr().String()
				} else {
					entry.cli.ch <- "irc-server > User not found"
				}

			} else if entry.cmd[0] == "kick" && len(entry.cmd) == 2 {
				_, isAdmin := admins[entry.cli.username]
				if isAdmin {
					userToKick, exists := users[entry.cmd[1]]
					if exists {

						userToKick.ch <- "irc-server > You were kicked"

						time.Sleep(1 * time.Second)

						_, isAnAdmin := admins[userToKick.username]
						if isAnAdmin {
							delete(admins, userToKick.username)
						}

						delete(clients, userToKick)
						delete(users, userToKick.username)
						close(userToKick.ch)
						userToKick.conn.Close()

						fmt.Println("irc-server > [" + userToKick.username + "] was kicked")

						for cli := range clients {
							cli.ch <- "irc-server > [" + userToKick.username + "] was kicked"
						}

						if len(admins) == 0 && len(users) > 0 {
							for cli := range clients {
								admins[cli.username] = cli
								fmt.Println("irc-server > [" + cli.username + "] was promoted to admin")
								cli.ch <- "irc-server > You're the new IRC Server admin."
								break
							}
						}
					} else {
						entry.cli.ch <- "irc-server > User not found"
					}
				} else {
					entry.cli.ch <- "irc-server > You don't have permission to use this commmand"
				}

			} else if entry.cmd[0] == "msg" && len(entry.cmd) >= 3 {
				userToMsg, exists := users[entry.cmd[1]]
				if exists {
					userToMsg.ch <- "DM: " + entry.cli.username + " > " + strings.Join(entry.cmd[2:], " ")
					entry.cli.ch <- "DM: " + entry.cli.username + " > " + strings.Join(entry.cmd[2:], " ")
				} else {
					entry.cli.ch <- "irc-server > User not found"
				}
			} else if true {
				entry.cli.ch <- "irc-server > Wrong command or usage"
			}
		}
	}
}

//!-broadcaster

//!+handleConn
func handleConn(conn net.Conn) {
	ch := make(chan string) // outgoing client messages
	go clientWriter(conn, ch)

	data := make([]byte, 512)
	n, _ := conn.Read(data)
	username := string(data[:n])

	fmt.Println("irc-server > New connected user [" + username + "]")

	ch <- "irc-server > Welcome to the Simple IRC Server"
	ch <- "irc-server > Your user [" + username + "] was successfully logged"
	messages <- "irc-server > New connected user [" + username + "]"

	clientConnected := client{ch, username, conn}

	entering <- clientConnected

	input := bufio.NewScanner(conn)
	for input.Scan() {
		msg := input.Text()
		if msg[:1] == "/" {
			commands <- command{clientConnected, strings.Split(msg[1:], " ")}
		} else {
			messages <- username + " > " + msg
		}
	}
	// NOTE: ignoring potential errors from input.Err()

	leaving <- clientConnected
	conn.Close()
}

func clientWriter(conn net.Conn, ch <-chan string) {
	for msg := range ch {
		fmt.Fprintln(conn, msg) // NOTE: ignoring network errors
	}
}

//!-handleConn

//!+main
func main() {
	if len(os.Args) != 5 {
		fmt.Println("Error: Info Missing")
		return
	}
	serverIP := os.Args[2]
	port := os.Args[4]
	listener, err := net.Listen("tcp", serverIP+":"+port)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("irc-server > Simple IRC Server started at " + serverIP + ":" + port)

	go broadcaster()

	fmt.Println("irc-server > Ready for receiving new clients")

	for {
		conn, err := listener.Accept()
		if err != nil {
			log.Print(err)
			continue
		}
		go handleConn(conn)
	}
}

//!-main
