#ifndef TYPES__H
#define TYPES__H

#include <stdio.h>

/*****TIPOS*****/
typedef enum{
	OK = 0,
	ERR_INVALID_FORMAT = 1,
	ERR_INVALID_ARGS = 2,
	ERR_NO_FORMAT_FLAG = 3,
	ERR_NO_FORMAT_ARGUMENT = 4,
	ERR_NULL_POINTER = 5,
	ERR_SYSTEM_DATE = 6,
	ERR_OUT_OF_MEMORY = 7
}status_t;

typedef enum{
	DDMMAAAA = 0,
	AAAADDD = 1,
	AAAAMMDD = 2,
	AAAAMMDDHHmmSS = 3,
	AAAADDDHHmmSS = 4
}format_t;

#endif