SHELL    = /bin/bash
CC       = gcc
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = cat2.o
TARGET   = mycat

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

include ../common.mk
