CXX = gcc
PROG = zosh

install: main.c
	$(CXX) -o $(PROG) main.c read.c parse.c exec.c conf_handling.c 

clean:
	rm -f $(PROG)
