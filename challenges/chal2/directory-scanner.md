Directory Scanner
=================
Implement a directory scanner tool for any given path. It's highly recommended to implement it for a UNIX-based machine.
This challenge requires a proper error handling in order to avoid program's crashes due `permission denied` errors.

Requirements
------------
- The program must be implemented in Golang programming language.
- Given one path, the program must count the following file's types:
  - Directories
  - Permission Denied files
  - Symbolic Links
  - Others
- Use the provided template `dir-scan.go`
- Repeated log classes are not allowed.
- You need to follow the output format guidelines.
- Coding best practices that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample Execution
----------------
```
./directory-scanner /tmp
```

Sample Expected output
----------------------
```
Directory Scanner Tool
+-------------------------+------+
| Path                    | /tmp |
+-------------------------+------+
| Directories             | 10   |
| Permission denied files | 145  |
| Symbolic Links          | 5    |
| Other files             | 50   |
+-------------------------+------+
```

Test Cases
----------
The program will be tested with the following cases:

1. `/tmp` directory
```
./directory-scanner /tmp
```

2. `/etc` directory
```
./directory-scanner /etc
```

2. `/usr/lib` directory
```
./directory-scanner /usr/lib
```

Useful links
------------
- https://golang.org/pkg/os/#Lstat
- https://golang.org/pkg/path/filepath/#Walk