#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "func.h"

#define BUFF_SIZE 64

int main_read_rc_(char *user){

	char path[] = "/etc/zosh/";
	strcat(path, user);
	strcat(path,".rc");

	if(access(path, F_OK|R_OK) != 0){

		perror("zosh");
		return -1;

	}

	FILE *rcfile;
	char *line;
	char *status;
	unsigned int i;
	char *username = malloc(BUFF_SIZE * sizeof(char));
	size_t len = 0;
	ssize_t read;

	rcfile = fopen(path, "r");

    if (rcfile == NULL)
        return -1;

	while ((read = getline(&line, &len, rcfile)) != -1){

		status = interp(line);
		i++;

	}

	return 0;
}

char *interp(char *line){

	return 0;	

}
