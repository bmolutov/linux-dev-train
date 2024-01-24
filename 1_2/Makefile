# all: exe
#
# exe: solution.h main.c lib
# 	gcc main.c -fPIC -L. -lsolution -o solution
#
# lib: solution.h solution.c
# 	gcc -shared solution.c -fPIC -o libsolution.so
#
# clean:
# 	-rm solution libsolution.so 2>/dev/null

CC=gcc
FO=-Wall -c -fPIC
FSO=-Wall -shared

all: libsolution.so

libsolution.so: solution.o
	$(CC) $(FSO) solution.o -o libsolution.so

solution.o: solution.c
	$(CC) $(FO) solution.c

