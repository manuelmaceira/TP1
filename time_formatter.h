#ifndef TIME_FORMATTER__H
#define TIME_FORMATTER__H

#include <stdio.h>
#include <time.h>

#include "types.h"

status_t format_date_as_DDMMAAAA(time_t time, char ** time_formatted);
status_t format_date_as_AAAADDD(time_t time, char ** time_formatted);
status_t format_date_as_AAAAMMDD(time_t time, char ** time_formatted);
status_t format_date_as_AAAAMMDDHHmmSS(time_t time, char ** time_formatted);
status_t format_date_as_AAAADDDHHmmSS(time_t time, char ** time_formatted);
status_t set_format(char * format_arg, setup_t * setup);
status_t get_sysdate(time_t * time);

#endif