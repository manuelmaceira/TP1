#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dates.h"

/**********PUNTEROS A FUNCION PARA CADA FORMATO************/
status_t (*format_date[MAX_DATE_FORMATS]) (time_t now, char * time_str[]) = {
	format_date_as_DDMMAAAA,
	format_date_as_AAAADDD,
	format_date_as_AAAAMMDD,
	format_date_as_AAAAMMDDHHmmSS,
	format_date_as_AAAADDDHHmmSS
};

/*********FUNCIONES***********/
status_t get_sysdate(time_t * now) {
	if(now == NULL) 
		return ERR_NULL_POINTER;

	if((*now = time(NULL)) == -1) 
		return ERR_SYSTEM_DATE;
	
	return OK;
}

/********FUNCIONES PARA CADA FORMATO**********/
status_t format_date_as_DDMMAAAA(time_t now, char * time_str[]) {
	struct tm * time_struct;

	if (time_str == NULL)
		return ERR_NULL_POINTER;

	time_struct = localtime(&now);

	sprintf(*time_str, "%02d%02d%04d", time_struct->tm_mday, time_struct->tm_mon + 1, time_struct->tm_year + 1900);
	return OK;
}

status_t format_date_as_AAAADDD(time_t now, char * time_str[]) {
	struct tm * time_struct;

	if (time_str == NULL)
		return ERR_NULL_POINTER;

	time_struct = localtime(&now);
	
	sprintf(*time_str, "%04d%03d", time_struct->tm_year + 1900, time_struct->tm_yday + 1);
	return OK;
}

status_t format_date_as_AAAAMMDD(time_t now, char * time_str[]) {
	struct tm * time_struct;

	if (time_str == NULL)
		return ERR_NULL_POINTER;

	time_struct = localtime(&now);
	
	sprintf(*time_str, "%04d%02d%02d", time_struct->tm_year + 1900, time_struct->tm_mon + 1, time_struct->tm_mday);
	return OK;
}

status_t format_date_as_AAAAMMDDHHmmSS(time_t now, char * time_str[]) {
	struct tm * time_struct;

	if (time_str == NULL)
		return ERR_NULL_POINTER;

	time_struct = localtime(&now);
	
	sprintf(*time_str, "%04d%02d%02d%02d%02d%02d", time_struct->tm_year + 1900, time_struct->tm_mon + 1, time_struct->tm_mday, time_struct->tm_hour, time_struct->tm_min, time_struct->tm_sec);
	return OK;
}

status_t format_date_as_AAAADDDHHmmSS(time_t now, char * time_str[]) {
	struct tm * time_struct;

	if (time_str == NULL)
		return ERR_NULL_POINTER;

	time_struct = localtime(&now);
	
	sprintf(*time_str, "%04d%03d%02d%02d%02d", time_struct->tm_year + 1900, time_struct->tm_yday + 1, time_struct->tm_hour, time_struct->tm_min, time_struct->tm_sec);
	return OK;
}