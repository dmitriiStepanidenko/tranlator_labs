# Задание # 6
- **main.c** - Файл, в котором указывается исходный тест 
- **t.c** - Тестовый файл, в котором указывается аналогичный тест на языке СИ

make - компилирует оба файла и запускает их поочереди. Удобно сравнивать эталонный вывод с полученным.

- **lib.h** - содержит все служебные функции, касающиеся парсера/сканера и пр.
- **symbol.h** - содержит все касающееся хэш-таблиц
- **test.c** - содержит немного тестов. использует заголовчный файл **miniunit.h**

<START> ::= <statement>
<statement> ::= <function><statement>
<statement> ::= printf( <iden_numconst> );
<function> ::= for( IDENTIFIER = <iden_numconst>; IDENTIFIER <  <iden_numconst>  ; IDENTIFIER ++) 
<iden_numconst> ::= NUMCONST
<iden_numconst> ::= IDENTIFIER <opt_plus>
<opt_plus> ::= e
<opt_plus> ::= ++
