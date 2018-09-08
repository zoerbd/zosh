#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"

#define BUFF_SIZE 64

char *shell_options[] = {

	"prompt",
	"alias"

};

int num_options(void){

	return sizeof(shell_options) / sizeof(char*);

}

/*
int (*rc_func[]) = {

	&rc_prompt,
	&rc_alias

};
*/

int write_hist(char *user, char *user_input){

	FILE *histfile;
	char *path;

	if((path = make_path(user, "hist")) == NULL)
		return -1;

	histfile = fopen(path, "a");

	if((fprintf(histfile, "%s\n", user_input)) > 0)
		return -1;

	return 0;

	fclose(histfile);

}

int read_rc(char *user){

	FILE *rcfile;
	char *path;
	char *line;
	char *status;
	char *username = malloc(BUFF_SIZE * sizeof(char));
	size_t len = 0;
	ssize_t read;

	path = make_path(user, "rc");

	rcfile = fopen(path, "r");

    if (!rcfile)
        return -1;

	while ((read = getline(&line, &len, rcfile)) != -1){

		status = interp(line);

	}

	return 0;
}

char *interp(char *line){

	auto char **rclist;
	register unsigned int i = 0;
	auto char *rvalue = malloc(BUFF_SIZE / 4 * sizeof(char));

	rclist = main_parse(line);

	while(i < num_options()){

		if(strcmp(rclist[0], shell_options[i]))
			//rvalue = rc_func[i];
			rvalue = "lalala";
			return 0;

		i++;
	}

	return 0;	

}

char *make_path(char *user, char *type){

	char *path = malloc(BUFF_SIZE * sizeof(char));
	char *dir = "/etc/zosh/";

	// apend username, type of file and extension to complete path
	path[0] = '\0';
	strcat(path, dir);
	strcat(path, user);
	strcat(path, type);
	strcat(path, ".zosh");

	// check if file exists and is writable, readable for user
	if(access(path, F_OK|R_OK|W_OK) != 0)
		return NULL;

	return path;


}

int *rc_alias(void){

	return 0;

}

int *rc_prompt(void){

	return 0;

}