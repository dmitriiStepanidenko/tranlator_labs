all: main t 

main: main.c lib.h  symbol.h
	gcc main.c && ./a.out 

t: t.c lib.h  symbol.h
	gcc t.c && ./a.out

test: test.c lib.h miniunit.h symbol.h
	gcc -lc test.c && ./a.out
