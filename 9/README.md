- В файл testfile.test ввести тестируемое предложение
- В файле t.c ввести его аналог на языке Си
- Выполнить команду make


```
<START> ::= <statement>
<statement> ::= <function><statement>
<statement> ::= printf( <iden_numconst> );
<function> ::= for( IDENTIFIER = <iden_numconst>; IDENTIFIER <  <iden_numconst>  ; IDENTIFIER ++) 
<iden_numconst> ::= NUMCONST
<iden_numconst> ::= IDENTIFIER <opt_plus>
<opt_plus> ::= e
<opt_plus> ::= ++
```
