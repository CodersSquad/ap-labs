CC       = gcc
CFLAGS   = -Wall
LDFLAGS  = -lm -lpthread
OBJFILES = arrayloops.o bug1.o bug1fix.o bug4.o bug4fix.o bug6.o bug6fix.o condvar.o dotprod_mutex.o dotprod_serial.o logger.o
TARGET   = arrayloops bug1 bug1fix bug4 bug4fix bug6 bug6fix condvar dotprod_mutex dotprod_serial

all: $(TARGET)

logger:
	$(CC) $(CFLAGS) -c -o logger.o logger.c $(LDFLAGS)

$(TARGET):  %: %.c logger
	$(CC) $(CFLAGS) logger.o -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
include ../common.mk
