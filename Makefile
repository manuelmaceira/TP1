###Se definen los flags a utilizar y el compilador respectivamente###
CFLAGS = -Wall -Werror -std=c89 -pedantic -O2
CC = gcc

##Se define el make all##
all : timeformatter

##Se define el script de compilación final junto con los distintos##
##scripts de compilación para los distintos archivos .c##
timeformatter : main.o format.o errors.o time_formatter.o setup.o
	$(CC) $(CFLAGS) -o timeformatter main.o format.o errors.o time_formatter.o setup.o

setup.o : setup.c setup.h
	$(CC) $(CFLAGS) -o setup.o -c setup.c

main.o : main.c main.h format.h types.h errors.h time_formatter.h setup.h
	$(CC) $(CFLAGS) -o main.o -c main.c

format.o : format.c format.h
	$(CC) $(CFLAGS) -o format.o -c format.c

errors.o : errors.c errors.h format.h main.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c

time_formatter.o : time_formatter.c time_formatter.h types.h format.h
	$(CC) $(CFLAGS) -o time_formatter.o -c time_formatter.c

clean :
	rm *.o