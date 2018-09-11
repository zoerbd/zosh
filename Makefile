CC = gcc
CFLAGS = -Wall -g -o
BIN = zosh
MAIN = main.c read.c parse.c exec.c conf_handling.c

install: $(MAIN) func.h
	$(CC) $(CFLAGS) $(BIN) $(MAIN)

clean:
	rm -f $(BIN)
