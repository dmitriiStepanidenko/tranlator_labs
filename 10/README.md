# Грамматика
```
<STATEMENT> ::= <function><STATEMENT>
<function> ::= for( IDENTIFIER= <IDEN_NUMCONST>; IDENTIFIER <  <IDEN_NUMCONST>  ; IDENTIFIER ++) 
<STATEMENT> ::= printf( <IDEN_NUMCONST>  );
<IDEN_NUMCONST> ::= NUMCONST |  IDENTIFIER <OPT_PLUS>
<OPT_PLUS> ::= e | ++
```

# Запуск и работа
1. Записать в файл testfile.test предложение написанное в грамматике задания
2. Записать в файл t.c аналог на языке С
3. Выполнить make 
4. Сравнить вывод
