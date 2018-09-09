CC = gcc
#CFLAGS = -Wall -g -v -o
CFLAGS = -g -o
PROG = zosh
MAIN = main.c read.c parse.c exec.c conf_handling.c

install: $(MAIN) func.h
	$(CC) $(CFLAGS) $(PROG) $(MAIN)

clean:
	rm -f $(PROG)
