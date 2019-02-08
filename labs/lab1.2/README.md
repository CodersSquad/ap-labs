Lab 1.2 - PTY/TTY Broadcaster
=============================

Develop a program in C that will serve as a Broadcaster of custom messages for all connected users in your Linux machine.
For example, if you have 5 ssh-connected users, you should be able to send a message to all users' terminals with a single command.

General requirements and cosiderations
--------------------------------------
- You will be implementing an alternative to the [wall](http://man7.org/linux/man-pages/man1/wall.1.html) command
- For this lab, you will need to run it in a Linux machine, you can use the Virtual Machine we set in class.
- The common case is that all users will be connected with `ssh`, so each connected user will have a `pty` which has its own `/dev/pts/<id>` file. So, you can send a message to an specific `pts` with:
```
echo HELLO > /dev/pts/1
```
- The implementation needs to be done with the usage of one or more of the following system calls:
  - open
  - read
  - open
  - write
  - close
- It's not allowed to use the `wall` or `echo` commands.
- The program should allow custom messages as follows:
```
./broadcaster.c HELLO, this is an EXAMPLE MESSAGE
```
- The execution of the above command will send the full message `HELLO, this is an EXAMPLE MESSAGE` to all connected users.