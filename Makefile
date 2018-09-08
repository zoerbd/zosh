install:
	gcc -o z main.c read.c parse.c exec.c read_rc.c 

clean:
	rm ./z
