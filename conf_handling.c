#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "func.h"

#define BUFF_SIZE 64

int write_hist(char *user, char *user_input){

	FILE *histfile;
	char *path;

	if(!(path = make_path(user, "hist")))
		return -1;

	if(!(histfile = fopen(path, "a+")))
		return -1;

	if((fprintf(histfile, "%s\n", user_input)) > 0)
		return -1;

	return 0;

	fclose(histfile);

}

int read_rc(char *user){

	// vars for getline()
	FILE *rcfile;
	char *line;
	size_t len;
	
	char *path = malloc(BUFF_SIZE / 4 * sizeof(char));

	// vars for return values from parse, exec
	auto char **rclist;
	auto int rvalue;

	if(!(path = make_path(user, "rc")))
		return -1;

	if(!(rcfile = fopen(path, "a+")))
        return -1;

	while((getline(&line, &len, rcfile)) != -1){
		rclist = main_parse(line);
		rvalue = main_exec(rclist);
	}

	return 0;
}

char *make_path(char *user, char *type){

	char *path = malloc(BUFF_SIZE * sizeof(char));
	char *dir = "/etc/zosh/";
	FILE *fp;
	struct stat st = {0};

	if((stat(dir, &st)) == -1)
		mkdir(dir, 0666);

	// apend username, type of file and extension to complete path
	path[0] = '\0';
	strcat(path, dir);
	strcat(path, user);
	strcat(path, type);
	strcat(path, ".zosh");

	// check if file exists and is writable, readable for user
	if((access(path, F_OK|R_OK|W_OK)) != 0){
		fp = fopen(path ,"a");
		fclose(fp);
	}

	return path;

}
