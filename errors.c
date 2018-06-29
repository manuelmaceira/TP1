#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

extern char * formats_dictionary[MAX_DATE_FORMATS];

char * errors_dictionary[MAX_ERRORS] = {
	"",
	MSG_ERROR_INVALID_DATE_FORMAT,
	MSG_ERROR_INVALID_PROGRAM_INVOCATION,
	MSG_ERROR_NULL_POINTER,
	MSG_ERROR_SYSTEM_DATE,
	MSG_ERROR_OUT_OF_MEMORY
};

void show_usage(void) {
	FILE * info_file;
	unsigned int c;

	if ((info_file = fopen(INFO_FILE_PATH, "rt")) == NULL) {
		fprintf(stderr, "%s\n", MSG_INFO_FILE_NOT_FOUND);
	}

	while ((c = fgetc(info_file)) != EOF) {
		putc(c, stdout);
	}

	fclose(info_file);
}