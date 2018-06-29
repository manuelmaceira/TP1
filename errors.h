#ifndef ERRORS__H
#define ERRORS__H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "date_formats.h"

#define MAX_ERRORS 6

#define MSG_ERROR_INVALID_DATE_FORMAT "Error, formato de fecha inválido."
#define MSG_ERROR_INVALID_PROGRAM_INVOCATION "Error en la invocación del programa."
#define MSG_ERROR_NULL_POINTER "Error, puntero nulo."
#define MSG_ERROR_SYSTEM_DATE "Error al recuperar la fecha del sistema."
#define MSG_ERROR_OUT_OF_MEMORY "Error, memoria insuficiente."

#define INFO_FILE_PATH "info.txt"
#define MSG_INFO_FILE_NOT_FOUND "Imposible abrir el archivo de información."

void show_usage(void);

#endif