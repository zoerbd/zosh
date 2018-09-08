install:
	gcc -o z main.c read.c parse.c exec.c conf_handling.c 

clean:
	rm ./z
