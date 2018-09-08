#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

// array of strings with builtin-names
char *builtin_str[] = {

	"cd",
	"exit",
	"help"

};

// pointer array that is pointing to each builtin-func
int (*builtin_func[]) (char **) = {

	&main_cd,
	&main_exit,
	&main_help

};

// get num of builtins
int num_builtins(){

	return sizeof(builtin_str) / sizeof(char*);

}


// execute specific program by giving prog-name and list of additional args
int main_exec_prog(char **args){

	auto pid_t pid, wpid;
	auto int status;

	// fork process from shells 
	pid = fork();

	/* Child: 
	if fork() returns 0, it has forked successfully */
	if (pid == 0){

		// try to exec users tokenized input in child; error if -1 is returned (execvp(program name, string-array)) 
		if ( execvp(args[0], args) == -1 ){

			//print error on failure
			perror("zosh");

		}

		exit(-1);	

	// if exec returned num < 0, an error occurred
	} else if (pid < 0){

		perror("zosh");

	// Parent: 
	} else{

		do{

			// wait for feedback from child
			wpid = waitpid(pid, &status, WUNTRACED);

		// while child is not exited or killed by signal
		} while(!WIFEXITED(status) && !WIFSIGNALED(status));

	}

	// signal to print prompt again
	return 1;

}


// main cd functionality
int main_cd(char **args){

		// make sure directory to cd is given
	if(args[1] == NULL){

		fprintf(stderr, "zosh: expected argument to \"cd\"\n");

	}else{

		// change dir, if value != 0 returned, an error occurred
		if(chdir(args[1]) != 0){

			if(strcmp(args[1],"~")){

	/*			if(chdir(homedir) != 0)
					perror("zosh");
									*/
				printf("coming soon!\n");

			}else{
			perror("zosh");
			}

		}

	}

	return 1;

}


// main help functionality
int main_help(char **args){

	/* Print help and shell builtins*/
	printf("Made by the best of all Pokemon-Trainer.\nJust type in program-name and hit return.\nTo get more information to a specific program, you should take a look at the man-page.\nFollowing shell-builtins are implemented:\n");
	register unsigned char counti;

	while(counti < num_builtins()){

		printf("   %s\n", builtin_str[counti]);
		counti++;

	}

	return 1;

}


// exit functionallity
int main_exit(char **args){

	// exit and do not prompt again
	return 0;

}

// Start execute user input
int main_exec(char **args){

	register unsigned int i = 0;

	// check for empty input
	if(args[0] == NULL){

		return 1;

	}

	// check if input is a builtin; if not execute program + parameter list (main_exec_prog(args))
	while(i < num_builtins()){


		// string comparison
		if (strcmp(args[0], builtin_str[i]) == 0){

			// exec builtin and return status
			return (*builtin_func[i])(args);

		}

		i++;

	}

	// exec program and return status
	return main_exec_prog(args);

}

//main-source: https://brennan.io/2015/01/16/write-a-shell-in-c/
