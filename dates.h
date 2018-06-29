#ifndef DATES__H
#define DATES__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "date_formats.h"
#include "types.h"

#define MAX_DATE_FORMAT_LENGHT 20

status_t get_sysdate(time_t * time);
status_t format_date_as_DDMMAAAA(time_t time, char ** time_formatted);
status_t format_date_as_AAAADDD(time_t time, char ** time_formatted);
status_t format_date_as_AAAAMMDD(time_t time, char ** time_formatted);
status_t format_date_as_AAAAMMDDHHmmSS(time_t time, char ** time_formatted);
status_t format_date_as_AAAADDDHHmmSS(time_t time, char ** time_formatted);

#endif
