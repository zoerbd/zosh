CC = gcc
CFLAGS = -Wall -g
BIN = zosh
MAIN = main.c read.c parse.c exec.c conf_handling.c

install: $(MAIN) func.h
	$(CC) $(CFLAGS) -o $(BIN) $(MAIN)

clean:
	rm -f $(BIN)
