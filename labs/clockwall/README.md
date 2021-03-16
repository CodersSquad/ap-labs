Lab - ClockWall
===================

Modify the [clock2.go](./clock2.go) to accept the `-port` parameter and write a program [clockWall.go](clockWall.go)
that acts as a client of several clock servers at once.

It will read  the times from each one and displaying the results in a table.
If you have access to geographically distributed computers, run instances remotely; otherwise run local instances on different ports with fake time zones.


How to run your program
-----------------------

In order to run your clock servers and client you will need to open different terminals.

- **Terminal 1** (Clock Server 1)
```
$ TZ=US/Eastern    go run serverClock.go -port 8010
```

- **Terminal 2** (Clock Server 2)
```
$ TZ=Asia/Tokyo    go run serverClock.go -port 8020
```

- **Terminal 3** (Clock Server 4)
```
$ TZ=Europe/London go run serverClock.go -port 8030
```

- **Terminal 4** (Single Clock Wall Client)
```
$ go run clockWall.go NewYork=localhost:8010 Tokyo=localhost:8020 London=localhost:8030
US/Eastern    : 12:00:00
Asia/Tokyo    : 17:00:00
Europe/London : 02:00:00
```

General Requirements and Considerations
---------------------------------------
- Use the `clockServer.go` and `clockWall.go` files for your implementation.
- **You must use unbuffered and buffered channels**
- Follow the command-line arguments convention
- Don't forget to handle errors properly
- Coding best practices implementation will be also considered

Useful links
------------
- https://yourbasic.org/golang/time-change-convert-location-timezone/
- https://golang.org/pkg/flag/


Test Suite
----------

Since it's a multi-process execution, it will be manually executed
with the steps provided in the [How to run your
program](#how-to-run-your-program) section.


How to submit your work
=======================
```
make submit
```
More details at: [Classify API](../../classify.md)
