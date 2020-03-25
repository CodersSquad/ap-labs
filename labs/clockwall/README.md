Lab - ClockWall
===================

Modify the [clock2.go](./clock2.go) to accept a port number, and write a program `clockWall.go`, that acts as a client of several clock servers at once, reading the times from each one and displaying the results in a table, akin to the wall of clocks seen in some business offices. If you have access to geographically distributed computers, run instances remotely; otherwise run local instances on different ports with fake time zones.

```
# Clock Servers initialization
# The following 3 commands are setting up 3 clock2 processes in the same terminal.
$ TZ=US/Eastern    go run clock2.go -port 8010 &
$ TZ=Asia/Tokyo    go run clock2.go -port 8020 &
$ TZ=Europe/London go run clock2.go -port 8030 &

# Starting clockWall client
$ go run clockWall.go NewYork=localhost:8010 Tokyo=localhost:8020 London=localhost:8030
US/Eastern    : 12:00:00
Asia/Tokyo    : 17:00:00
Europe/London : 02:00:00
.
.
.
```

General Requirements and Considerations
---------------------------------------
- Use the `clock2.go` and `clockWall.go` files for your implementation.
- Follow the command-line arguments convention.
- Don't forget to handle errors properly.
- Coding best practices implementation will be also considered.

How to submit your work
=======================
```
GITHUB_USER=<your_github_user>  make submit
```
More details at: [Classify API](../../classify.md)
