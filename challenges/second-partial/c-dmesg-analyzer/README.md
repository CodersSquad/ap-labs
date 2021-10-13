DMESG Analyzer
==============

Implement a system log analyzer and classifier for GNU/Linux. In this particular case, a sample log output file is provided.
It's highly recommended to implement this challenge in a Linux-based operating system. This challenge involves a proper struct design choice for the logs classification and storing.


Requirements
------------
- The program must be implemented in C programming language.
- You program will classify log entries by the `<log_type>:` prefix
- Those log entries that don't follow the `<log_type>:` convention will go to the `General` classification.
- Repeated log classes are not allowed.
- Use the `dmesg-analyzer.c` template
- The solution must use at least 3 of the following system calls:
  - `open()`
  - `read()`
  - `write()`
  - `lseek()`
  - `close()`
- Don't forget to handle errors properly
- You need to follow the output format guidelines.
- [Coding best practices](https://softfire-143705.appspot.com/programming-art/00-names.slide#1) that we learned in class will be reviewed.
- Before submitting you code, make sure it's compiling and running correctly.


Sample Execution
----------------
```
./dmesg-analizer dmesg.txt
```


Sample Expected output file `dmesg_report.txt`
----------------------------------------------
```
General:
  [    0.000000] Linux version 4.15.0-45-generic (buildd@lgw01-amd64-031) (gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3)) #48-Ubuntu SMP Tue Jan 29 16:28:13 UTC 2$
Command line:
  [    0.000000] BOOT_IMAGE=/boot/vmlinuz-4.15.0-45-generic root=UUID=d67ab183-f0e2-4bb6-8270-ad35088cef7a ro splash quiet
KERNEL supported cpus:
  [    0.000000]   Intel GenuineIntel
  [    0.000000]   AMD AuthenticAMD
  [    0.000000]   Centaur CentaurHauls
x86/fpu:
  [    0.000000] Supporting XSAVE feature 0x001: 'x87 floating point registers'
  [    0.000000] Supporting XSAVE feature 0x002: 'SSE registers'
  [    0.000000] Supporting XSAVE feature 0x004: 'AVX registers'
  [    0.000000] xstate_offset[2]:  576, xstate_sizes[2]:  256
  [    0.000000] Enabled xstate features 0x7, context size is 832 bytes, using 'standard' format.
pci_bus 0000:00:
  [    0.032806] root bus resource [io  0x0000-0x0cf7 window]
  [    0.032808] root bus resource [io  0x0d00-0xffff window]
  [    0.032809] root bus resource [mem 0x000a0000-0x000bffff window]
  [    0.032810] root bus resource [mem 0x80000000-0xfdffffff window]
  [    0.032812] root bus resource [bus 00-ff]
Zone ranges:
  [    0.000000]   DMA      [mem 0x0000000000001000-0x0000000000ffffff]
  [    0.000000]   DMA32    [mem 0x0000000001000000-0x000000007ffeffff]
  [    0.000000]   Normal   empty
  [    0.000000]   Device   empty
```


Test Cases
----------

The program will be tested with the following cases:

1. [dmesg.txt](./dmesg.txt)
```
./dmesg-analyzer.o dmesg.txt
```
