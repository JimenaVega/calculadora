CC=gcc
CFLAGS=-I.

calc: clean calc.o
	$(CC) -o calc calc.o 
calc.o:
	$(CC) -c calc.c -o calc.o
clean:
	rm *.o calc
