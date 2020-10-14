Simple IRC Server
=================
Implement a simple [IRC](https://en.wikipedia.org/wiki/Internet_Relay_Chat) server with a client-server architecture.

It will be based on the Go Programming Language book's chapter 8th examples. [Chat Server](https://github.com/adonovan/gopl.io/tree/master/ch8/chat) and [netcat client](https://github.com/adonovan/gopl.io/tree/master/ch8/netcat3). Below you can see the specific requirements for this.

Requirements
------------
- The program must be implemented in Golang programming language.
- Use the provided base source code from `server.go` and `client.go` files.
- Add support for usernames. Instead of identifying users by their `ip:port`, they will be identified with their usernames.
- Add support for the following IRC sub-commands

| Sub-command         | description                                                                  |
|---------------------|------------------------------------------------------------------------------|
| `/users`            | To list all connected users and their logging time                           |
| `/msg <user> <msg>` | To send a direct message to the specified `user`                             |
| `/time`             | Get IRC Server's localtime                                                   |
| `/user <user>`      | Get more details about `user` (Username and IP address)                      |
| `/kick <user>`      | To kick (remove) an `user` from the channel (only channel ADMIN can do this) |

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
irc-server > [user1] was promoted as the channel ADMIN
irc-server > New connected user [user2]
irc-server > New connected user [user3]
irc-server > [user2] was kicked
irc-server > [user3] left
```

Sample 3 IRC clients test scenario
----------------------------------
- `user1` session
```
# go run client.go -user user1 -server localhost:9000
irc-server > Welcome to the Simple IRC Server
irc-server > Your user [user1] is successfully logged
irc-server > Congrats, you were the first user.
irc-server > You're the new IRC Server ADMIN
irc-server > New connected user [user2]
irc-server > New connected user [user3]
user1 > Hi all
user2 > &@*^
user1 > /kick user2
irc-server > [user2] was kicked from channel for bad language policy violation
user1 >
irc-server > [user3] left channel
user1 >
```

- `user2` session
```
# go run client.go -user user2 -server localhost:9000
irc-server > Welcome to the Simple IRC Server
irc-server > Your user [user2] is successfully logged
user2 >
irc-server > New connected user [user3]
user1 > Hi all
user2 > &@*^
irc-server > You're kicked from this channel
irc-server > Bad language is not allowed on this channel

```

- `user3` session
```
# go run client.go -user user3 -server localhost:9000
irc-server > Welcome to the Simple IRC Server
irc-server > Your user [user3] is successfully logged
user3 >
user1 > Hi all
irc-server > New connected user [user2]
user2 > &@*^
irc-server > [user2] was kicked from channel for bad language policy violation
^C
```

Sample Sub-Commands output
--------------------------
```
user1 > /users
irc-server > user1 - connected since 2020-10-13 10:10:22
irc-server > user2 - connected since 2020-10-13 10:12:12
irc-server > user3 - connected since 2020-10-13 10:15:43
user1 > /msg user2 message to user2    # user2 should receive the direct message "message to user2"
user1> /time
irc-server > Local Time: America/Mexico_City 16:53
user1 > /user user2
irc-server > username: user2, IP: 192.168.1.22 Connected since: 2020-10-13 10:12:12
```

Grading
-------
| Requirement            |      |
|------------------------|------|
| /users                 | 20%  |
| /msg <user> <msg>      | 20%  |
| /time                  | 20%  |
| /user <user>           | 20%  |
| /kick <user>           | 20%  |
| TOTAL                  | 100% |

Useful links
------------
- https://github.com/adonovan/gopl.io/tree/master/ch8/chat
- https://github.com/adonovan/gopl.io/tree/master/ch8/netcat3
- https://golang.org/pkg/flag/