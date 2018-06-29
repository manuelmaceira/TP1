#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "main.h"
#include "date_printer.h"

extern char * formats_dictionary[MAX_DATE_FORMATS];
extern char * errors_dictionary[MAX_ERRORS];
extern setup_t setup;

int	main(int argc, char *argv[]) {
	time_t now;
	status_t st;

	st = validate_args(argc, argv, &setup);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		show_usage();
		return st;
	}

	st = get_sysdate(&now);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		show_usage();
		return st;
	}

	st = print_date(now, &setup);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		show_usage();
		return st;
	}

	return OK;
}

/***********FUNCIONES**************/
status_t validate_args(int argc, char *argv[], setup_t * setup) {
	size_t fmt_index;
	status_t st;

	if (argc != CMD_ARGS_NUMBER) {
		return ERR_INVALID_INVOCATION;
	}
	st = get_format_index(argc, argv, &fmt_index);
	if (st != OK) {
		return st;
	}
	if(!argv[fmt_index]) {
		return ERR_INVALID_INVOCATION;
	}
	st = set_date_format(argv[fmt_index], setup);
	if (st != OK) {
		return st;
	}

	return OK;
}

status_t get_format_index(int argc, char *argv[], size_t * index) {
	size_t i;

	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], FORMAT_FLAG) == 0) {
			*index = i + 1;
			return OK;
		}
	}
	return ERR_INVALID_INVOCATION;
}

status_t set_date_format(char * format, setup_t * setup) {
	size_t i;

	for (i=0; i < MAX_DATE_FORMATS; i++) {
		if (strcmp(format, formats_dictionary[i]) == 0) {
			setup->date_format = i;
			return OK;
		}
	}
	return ERR_INVALID_DATE_FORMAT;
}