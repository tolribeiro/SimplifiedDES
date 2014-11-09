all: functions
functions: functions.o sdes.o 

functions.o: functions.c
		gcc -o functions.o -c functions.c -W -Wall -ansi -pedantic
sdes.o: sdes.c functions.h
		gcc -o sdes.o -c sdes.c -W -Wall -ansi -pedantic
clean:
		rm -rf *.o
mrproper: clean
		rm -rf functions