#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include "func.h"
#include <stdarg.h>
#define BUFF_SIZE 8


int main(int argc, char *argv[]){

	char *version = "0.1.3";

	if(argc > 1){

	if(strcmp(argv[1], "-v")){

		printf("start_in_debug() is coming soon!\n");
		return 0;

	} else if(strcmp(argv[1], "-d")){

		printf("%s\n", version);
		return 0;
	}

	}


	// colored printing
	static const char red[] = "\033[0;31m";
	static const char blue[] = "\033[0;34m";
	static const char green[] = "\033[0;32m";
	static const char magenta[] = "\033[0;35m";
	static const char lblue[] = "\034[0;36m";
	static const char defaultc[]= "\033[0m";

	// return vars for main functions
	char *line;
	char **args;
	int status;

	// buffer and prompt stuff
	int buffer = BUFF_SIZE;	
	char *name = malloc(buffer * sizeof(char));

	// get path and username for prompt
	name = getname();

	char pwd[256];
	struct passwd *userpw = getpwuid(getuid());
	const char *homedir = userpw->pw_dir;
		

	do {

		//if getcwd does not return path
		if(getcwd(pwd, sizeof(pwd)) != NULL){
			
			// if current dir is home
			if(!strcmp(pwd, homedir))
				strcpy(pwd,"~");

		}

		// print prompt
		printf("%s----------%s%s%s%s%s%s%s%s%s%s", blue, "$", red, name, blue, "@", green, pwd, blue, "> ", defaultc);

		// read rc-file
		// status = zosh_read_rc_(name);

		// read input
		line = zosh_read();

		// parse input
		args = zosh_parse(line);

		// execute parsed input
		status = zosh_exec(args);

		// delete pointer line, args

	// execute while zosh_exec() returns 1
	} while(status);


	return 0;
}


char *getname(void){
	
	// declarations for getname
	FILE *passwdf;
	char *username = malloc(BUFF_SIZE * sizeof(char));
	char line[255];
	char *uid = malloc((BUFF_SIZE / 2) * sizeof(char));
	size_t len;
	ssize_t read;

	// if writing uid to string uid returns 1, root is current user
	if((sprintf(uid, "%d", getuid())) == 1)
		return "root";

	// open passwd for reading
	passwdf = fopen("/etc/passwd", "r");

	// return unkown on err
	if (passwdf == NULL)
		return "unkown";

	// read file line by line
	while(fgets(line, 255, (FILE*) passwdf)){

		// check if uid in line
		username = if_user_in(line, uid); 

		// if username is returned, return
		if(username)
			return username;

	}

	// close passwd and return
	fclose(passwdf);
	return "unkown";

}

// check if uid in line and return username
char *if_user_in(char *line, char *uid){

	// declarations for getname
	char *correct_line = malloc(6 * BUFF_SIZE * sizeof(char));
	char *c = malloc(BUFF_SIZE * sizeof(char));
	register unsigned int counti = 0;

	//locates first occurrence of uid in line, returns pointer to beginning of first occ.
	if((correct_line = strstr(line, uid)) != NULL){

		// while name is not too large for c-var
		while(counti < 8){

			// return on ':' in line
			if(line[counti] == ':')
				return c;

			// write char of line to c and count up
			c[counti] = line[counti];
			counti++;

		}
	}

	// return NULL if nothing found
	return NULL;

}

// int delete
char idel(int *pointer,...){

	register int i;
	va_list valist;
	int varg;

	va_start(valist, pointer);

	while(va_arg(valist,int) && i < *pointer){

		varg = va_arg(valist, int);
		//free(.........);
		i++;
	}

	va_end(valist);

	return 1;
}

/*
// char delete
char cdel(char *pointer,...){

        register int i;
        va_list valist;
        int varg;

        va_start(valist, pointer);

        while(va_arg(valist,char) && i < *pointer){

                varg = va_arg(valist, char);
                //free(.........);
                i++;
        }

        va_end(valist);

        return 1;
}
*/
