#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>

#include "types.h"

#define FORMAT_FLAG "-fmt"
#define CMD_ARGS_NUMBER 3

status_t validate_args(int argc, char *argv[], size_t * index);
status_t get_format_index(int argc, char *argv[], size_t * index);

#endif