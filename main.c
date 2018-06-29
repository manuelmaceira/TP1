#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "setup.h"
#include "main.h"
#include "format.h"
#include "types.h"
#include "errors.h"
#include "time_formatter.h"

/****DICCIONARIOS****/
extern char * formats_dictionary[MAX_FORMATS];
extern char * errors_dictionary[MAX_ERRORS];
/*******ARREGLO DE PUNTEROS A FUNCIÓN*********/
extern status_t (*format_date[MAX_FORMATS]) (time_t time_now, char ** time_str, setup_t setup);
/**VARIABLE SETUP**/
extern setup_t setup;

int	main(int argc, char *argv[]) {
	char * time_str;
	time_t time_now;
	size_t fmt_index;
	status_t st;

	st = validate_args(argc, argv, &fmt_index);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		print_info(argv[PROGRAM_NAME_INDEX]);
		return st;
	}

	st = get_sysdate(&time_now);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		print_info(argv[PROGRAM_NAME_INDEX]);
		return st;
	}

	st = set_format(argv[fmt_index], &setup);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		print_info(argv[PROGRAM_NAME_INDEX]);
		return st;
	}

	st = format_date[setup.format](time_now, &time_str, setup);
	if (st != OK) {
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		print_info(argv[PROGRAM_NAME_INDEX]);
		return st;
	}

	fprintf(stdout, "%s\n", time_str);
	free(time_str);

	return OK;
}

/***********VALIDACIONES**************/
status_t validate_args(int argc, char *argv[], size_t *index) {
	status_t st;

	if (argc != CMD_ARGS_NUMBER) {
		return ERR_INVALID_ARGS;
	}
	st = get_format_index(argc, argv, index);
	if (st != OK) {
		return st;
	}
	if(!argv[*index]) {
		return ERR_NO_FORMAT_ARGUMENT;
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
	return ERR_NO_FORMAT_FLAG;
}

status_t set_format(char * format_arg, setup_t * setup) {
	size_t i;

	for (i=0; i < MAX_FORMATS; i++) {
		if (strcmp(format_arg, formats_dictionary[i]) == 0) {
			setup->format = i;
			return OK;
		}
	}
	return ERR_INVALID_FORMAT;
}