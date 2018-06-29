#include <stdio.h>
#include "date_printer.h"

extern status_t (*format_date[MAX_DATE_FORMATS]) (time_t now, char * time_str[]);

/* Se puso la función print_date() en otro archivo para que la biblioteca 
dates sea independiente del setup, ya que print_date depende de este. */
status_t print_date (time_t now, setup_t * setup) {
	char time_str[MAX_DATE_FORMAT_LENGHT];
	status_t st;

	st = format_date[setup->date_format](now, &time_str);
	if (st != OK) {
		return st;
	}
	fprintf(stdout, "%s\n", time_str);

	return OK;
}