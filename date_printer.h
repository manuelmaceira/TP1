#ifndef DATE_PRINTER__H
#define DATE_PRINTER__H

#include <stdio.h>
#include "types.h"
#include "setup.h"
#include "date_formats.h"
#include "dates.h"

status_t print_date (time_t now, setup_t * setup);

#endif