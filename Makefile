CC = gcc
CFLAGS = -Wall -g
CFLAGS = -g
BIN = zosh
IPATH = /usr/local/bin/
MAIN = main.c read.c parse.c exec.c conf_handling.c
CONF = /etc/zosh

install: $(MAIN) func.h
	$(CC) $(CFLAGS) -o $(BIN) $(MAIN)
	mv $(BIN) $(IPATH)
	mkdir $(CONF)

clean:
	rm -f $(IPATH)$(BIN)
	rm -rf $(CONF)
