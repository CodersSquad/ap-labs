CC       = gcc
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = logger.o monitor.o
TARGET   = monitor

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

include ../common.mk
