%{
#include <stdio.h>
#include "main.tab.h"
typedef struct Node Node;
struct Node {
  Node* childs;
  char* value;
  };
%}

%token  END 0
%token  FOR_START END_BRACK 
%token  PRINTF_START PRINTF_END
%token  EQUAL LESS INCREMENT SEMICOLON
%token  IDENTIFIER NUMCONST
//%glr-parser
%define lr.type canonical-lr
%define parse.trace true
%define parse.error verbose
%%

start:  statement;
statement:  function statement {printf("statement:fuction statement\n %s", $1);};
function:   FOR_START IDENTIFIER EQUAL iden_numconst SEMICOLON IDENTIFIER LESS iden_numconst SEMICOLON IDENTIFIER INCREMENT END_BRACK {
        printf("function: for( IDENTIFIER = iden_numconst ; IDENTIFIER < iden_numconst ; IDENTIFIER ++ )\n");
        //printf("%s %s\n", $2);
        };
statement:  PRINTF_START iden_numconst PRINTF_END;
iden_numconst: NUMCONST;
iden_numconst: IDENTIFIER opt_plus;
opt_plus: %empty;
opt_plus: INCREMENT;

//start:  statement;
//statement:  function statement {printf("statement: %s %s", $1, $2);};
//function:   "for(" IDENTIFIER '=' iden_numconst ';' IDENTIFIER '<' iden_numconst ';' IDENTIFIER "++)";
//statement:  "printf(" iden_numconst ")";
//iden_numconst: NUMCONST;
//iden_numconst: IDENTIFIER opt_plus;
//opt_plus: %empty;
//opt_plus: "++";




//<STATEMENT> ::= <function><STATEMENT>
//<function> ::= for( IDENTIFIER= <IDEN_NUMCONST>; IDENTIFIER <  <IDEN_NUMCONST> ; IDENTIFIER <END_BRACK>
//<STATEMENT> ::= printf( IDENTIFIER <END_BRACK>;
//<IDEN_NUMCONST> ::= NUMCONST |  IDENTIFIER
//<END_BRACK> ::= ++) | )

%%


int main()
{
  printf("> "); 
  yyparse();
  return 0;
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
  return -1;
}
