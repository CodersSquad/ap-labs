CC       = gcc
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = logger.o testLogger.o
TARGET   = testLogger

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
