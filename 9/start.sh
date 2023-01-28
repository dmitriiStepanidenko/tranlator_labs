#bison -d main.y --verbose && \
#  lex main.l && \
#  cc  lex.yy.c main.tab.c -o parser 
  #&& \
  #gcc -o parser lex.yy.o main.tab.o -ll -ly
  #
bison -d main.y --verbose && \
flex main.l && \
  cc lex.yy.c -lfl
