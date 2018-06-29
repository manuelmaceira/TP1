#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "setup.h"
#include "errors.h"
#include "dates.h"
#include "date_formats.h"

#define FORMAT_FLAG "-fmt"
#define CMD_ARGS_NUMBER 3

status_t validate_args(int argc, char *argv[], setup_t * setup);
status_t get_format_index(int argc, char *argv[], size_t * index);
status_t set_date_format(char * format_arg, setup_t * setup);

#endif