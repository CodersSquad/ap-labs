CC       = gcc
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = logger.o base64.o
TARGET   = base64

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
