#ifndef ERRORS__H
#define ERRORS__H

#include <stdio.h>

#define MAX_ERRORS 8

#define MSG_ERROR_INVALID_FORMAT "Error en el formato."
#define MSG_ERROR_INVALID_ARGS "Error, argumentos invalidos."
#define MSG_ERROR_NO_FORMAT_FLAG "Error, no hay bandera de formato."
#define MSG_ERROR_FORMAT_ARGUMENT "Error, no hay argumento de formato."
#define MSG_ERROR_NULL_POINTER "Error, puntero nulo."
#define MSG_ERROR_SYSTEM_DATE "Error al recuperar la fecha del sistema."
#define MSG_ERROR_OUT_OF_MEMORY "Error, memoria insuficiente."

#define INFO_FILE_PATH "info.txt"
#define MSG_INFO_FILE_NOT_FOUND "Imposible abrir el archivo de información."

void show_usage(void);

#endif