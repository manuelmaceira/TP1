###Se definen los flags a utilizar y el compilador respectivamente###
CFLAGS = -Wall -Werror -std=c89 -pedantic -O2
CC = gcc

##Se define el make all##
all : timeformatter

##Se define el script de compilación final junto con los distintos##
##scripts de compilación para los distintos archivos .c##
timeformatter : main.o date_formats.o errors.o dates.o setup.o date_printer.o
	$(CC) $(CFLAGS) -o timeformatter main.o date_formats.o errors.o dates.o setup.o date_printer.o

main.o : main.c main.h
	$(CC) $(CFLAGS) -o main.o -c main.c

setup.o : setup.c setup.h
	$(CC) $(CFLAGS) -o setup.o -c setup.c

errors.o : errors.c errors.h
	$(CC) $(CFLAGS) -o errors.o -c errors.c

dates.o : dates.c dates.h
	$(CC) $(CFLAGS) -o dates.o -c dates.c

date_formats.o : date_formats.c date_formats.h
	$(CC) $(CFLAGS) -o date_formats.o -c date_formats.c

date_printer.o : date_printer.c date_printer.h
	$(CC) $(CFLAGS) -o date_printer.o -c date_printer.c

clean :
	rm *.o