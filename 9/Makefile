all: my ref

ref: t.c
	gcc t.c
	./a.out

my: main.l main.y ast.h hashtable.h
	bison -t -d main.y
	flex --debug main.l
	cc lex.yy.c main.tab.c -lfl -g 
	./a.out < testfile.test

