all: main.l
	bison -d main.y
	flex main.l
	cc lex.yy.c main.tab.c -lfl

