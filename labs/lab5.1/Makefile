CC       = gcc-8
CFLAGS   = -Wall
LDFLAGS  = -lm -fopenmp
OBJFILES = hello.o pi.o pi_mc.o matmul.o prod_cons.o logger.o random.o hello_par.o pi_par.o pi_mc_par.o matmul_par.o prod_cons_par.o
TARGET   = hello pi pi_mc matmul prod_cons hello_par pi_par pi_mc_par matmul_par prod_cons_par

all: $(TARGET)

logger:
	$(CC) $(CFLAGS) -c -o logger.o logger.c $(LDFLAGS)

random:
	$(CC) $(CFLAGS) -c -o random.o random.c $(LDFLAGS)

$(TARGET):  %: %.c logger random
	$(CC) $(CFLAGS) logger.o random.o -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
