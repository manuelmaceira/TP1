#include <stdio.h>
#include <stdlib.h>

#include "format.h"
#include "errors.h"

extern char * formats_dictionary[MAX_FORMATS];

char * errors_dictionary[MAX_ERRORS] = {
	"",
	MSG_ERROR_INVALID_FORMAT,
	MSG_ERROR_INVALID_ARGS,
	MSG_ERROR_NO_FORMAT_FLAG,
	MSG_ERROR_FORMAT_ARGUMENT,
	MSG_ERROR_NULL_POINTER,
	MSG_ERROR_SYSTEM_DATE,
	MSG_ERROR_OUT_OF_MEMORY
};

void show_usage(void) {
	file * info_file;
	unsigned int c;

	if ((info_file = fopen(INFO_FILE_PATH)) == NULL) {
		fprintf(stderr, "%s\n", MSG_INFO_FILE_NOT_FOUND);
	}

	while ((c = fgetc(info_file)) != EOF) {
		putc(c);
	}

	fclose(info_file);
}.