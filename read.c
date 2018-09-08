#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define BUFF_UNIT 64

char *main_read(void){

	// counter for position in array
	register int position = 0;

	// size for dynamically buffering of input
	auto int buffer_size = BUFF_UNIT;

	// set buffer-size
	auto char *user_input = malloc(sizeof(*user_input) * buffer_size);

	// store as int to check for EOF, which can not be used with char
	auto int c;

	// check allocation
	if (!user_input) {
		fprintf(stderr, "zosh: allocation failed.");
		exit(-1);
	}

	// -> while true
	while (1){

		// read one character
		c = getchar();

		// on EOF or linebreak append NULL
		if ( c == EOF || c == '\n'){

			user_input[position] = '\0';
			return user_input;

		}else{

			// if not EOF write char to buffered user_input
			user_input[position] = c;

		}
		
		// increase counting var by one
		position++;

		// make sure that next char will not be outside of buffer-size
		if (position >= buffer_size){

			// increase buffer_size var by one BUFF_UNIT
			buffer_size += BUFF_UNIT;

			// reallocate buffered var
			user_input = realloc(user_input, sizeof(char) * buffer_size);

				// Check if buffer successfully allocated
				if (!user_input) {
					fprintf(stderr, "zosh: allocation failed.");
					exit(-1);
				}

		}
	}
}
