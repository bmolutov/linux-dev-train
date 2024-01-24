# all: exe
#
# exe: solution.h main.c lib
# 	gcc main.c -fPIC -L. -ldl -o solution
#
# lib: solution.h solution.c
# 	gcc -shared solution.c -fPIC -o libsolution.so
#
# clean:
# 	-rm solution libsolution.so 2>/dev/null

all:
	gcc solution.c -o solution -fPIC -ldl -Wl,-rpath=.
