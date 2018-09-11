#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// token-buffer size
#define TOKEN_BUFFER_UNIT 64

// tokens delimiter
#define TOKEN_DEL " \t\r\n\a"

char **main_parse(char *line){

	// pretty similar deklaration as in main_read()
	register int position = 0;	
	auto int buffer_size = TOKEN_BUFFER_UNIT;
	auto char **tokens = malloc(buffer_size * sizeof(**tokens));
	auto char *token;

	// check allocation
	if (!tokens) {
		fprintf(stderr, "zosh: cant allocate memory.");
		exit(-1);
	}

	// pastes \0 at end of each token
	token = strtok(line, TOKEN_DEL);

	// while strtok() do not returns NULL (the str is not fully tokenized)
	while (token != NULL) {

		// write token to pointer array tokens
		tokens[position] = token;
		position++;

		// check if tokens-array has enough space to store next token
		if (position >= buffer_size){

			// reallocate tokens space 
			buffer_size += TOKEN_BUFFER_UNIT;
			tokens = realloc(tokens, buffer_size * sizeof(char));

			// check allocation
			if (!tokens) {
				fprintf(stderr, "zosh: cant allocate memory.");
				exit(-1);
			}

		}

		// token points to next string-part
		token = strtok(NULL, TOKEN_DEL);

	}

	// write at last position NULL to signalize end of input and return
	tokens[position] = NULL;
	return tokens;

}
