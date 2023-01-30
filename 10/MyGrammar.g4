/** Grammars always start with a grammar header. This grammar is called
* ArrayInit and must match the filename: ArrayInit.g4
*/

grammar MyGrammar;
statement: 
          function statement | 
          PRINT_START iden_numconst END_BRACK SEMICOLON;
function: FOR_START IDENTIFIER EQUAL iden_numconst SEMICOLON IDENTIFIER LESS iden_numconst SEMICOLON IDENTIFIER INCREMENT END_BRACK;
iden_numconst: NUMCONST | IDENTIFIER opt_plus;
opt_plus: INCREMENT | ;

WHITESPACE: [' '\r\t\n] -> skip;
EQUAL: '=';
LESS: '<';
SEMICOLON: ';';
INCREMENT: '++';
END_BRACK: ')';
FOR_START: 'for'[\t\r\n\f' ']*'(';
NUMCONST: [0-9]+;
PRINT_START: 'print'[\t\r\n\f]*'(';
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;

