CC = gcc
CFLAGS = -Wall -g
CFLAGS = -g
BIN = zosh
IPATH = /usr/local/bin/
MAIN = main.c read.c parse.c exec.c conf_handling.c

install: $(MAIN) func.h
	$(CC) $(CFLAGS) -o $(BIN) $(MAIN)
	mv $(BIN) $(IPATH)

clean:
	rm -f $(IPATH)$(BIN)
