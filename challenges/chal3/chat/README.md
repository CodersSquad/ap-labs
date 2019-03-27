Simple IRC Server
=================
Implement a simple [IRC](https://en.wikipedia.org/wiki/Internet_Relay_Chat) server with a client-server architecture.

It will be based on the Go Programming Language book's chapter 8th examples. [Chat Server](https://github.com/adonovan/gopl.io/tree/master/ch8/chat) and [netcat client](https://github.com/adonovan/gopl.io/tree/master/ch8/netcat3). Below you can see the specific requirements for this.

Requirements
------------
- The program must be implemented in Golang programming language.
- Use the provided base source code from `server.go` and `client.go` files.
- Add support for usernames. Instead of identifying users by their `ip:port`, they will be identified with their usernames.
- Add support for IRC sub-commands in the `client.go`

| Sub-command         | description                                             |
|---------------------|---------------------------------------------------------|
| `/users`            | To list all connected users                             |
| `/msg <user> <msg>` | To send a direct message to the specified `user`        |
| `/time`             | Get IRC Server's localtime                              |
| `/user <user>`      | Get more details about `user` (Username and IP address) |

- You need to follow the output format guidelines.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample IRC Server output
------------------------


```
# go run server.go -host localhost -port 9000
irc-server > Simple IRC Server started at localhost:9000
irc-server > Ready for receiving new clients
irc-server > New connected user [user1]
irc-server > New connected user [user2]
irc-server > [user1] left

```

Sample 2 IRC clients output
---------------------------
```
# go run client.go -user user1 -server localhost:9000
irc-server > Welcome to the Simple IRC Server
irc-server > Your user [user1] is successfully logged
user1 > Hi
^C
```

```
# go run client.go -user user2 -server localhost:9000
irc-server > Welcome to the Simple IRC Server
irc-server > Your user [user2] is successfully logged
user2 >
user1 > Hi
user2 >
irc-server > [user1] left
```

Sample Sub-Commands output
--------------------------
```
user1 > /users
irc-server > user1, user2
user1 > /msg user2 message to user2    # user2 should receive the direct message "message to user2"
user1> /time
irc-server > Local Time: America/Mexico_City 16:53
user1 > /user user2
irc-server > username: user2, IP: 192.168.1.22
```

Grading
-------
| Requirement            |      |
|------------------------|------|
| /users                 | 20%  |
| /msg <user> <msg>      | 20%  |
| /time                  | 20%  |
| /user <user>           | 20%  |
| Conding best practices | 20%  |
| TOTAL                  | 100% |

Useful links
------------
- https://github.com/adonovan/gopl.io/tree/master/ch8/chat
- https://github.com/adonovan/gopl.io/tree/master/ch8/netcat3
- https://golang.org/pkg/flag/