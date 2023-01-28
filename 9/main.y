%{
#include "ast.h"
#include "hashtable.h"
#include <stdio.h>
#include "main.tab.h"

HashTable* ht;
int yylex();
int yyerror(const char *);
%}
//%glr-parser
%define lr.type canonical-lr
%define parse.error verbose

%token  END 0
%token  FOR_START END_BRACK 
%token  PRINTF_START 
%token  EQUAL LESS INCREMENT SEMICOLON
%token  IDENTIFIER NUMCONST

%union{
  // 
  char* identifier_name;
  int number;
  //
  struct OptPlusData* opt_plus;
  struct IdenNumconstData* iden_numconst;
  struct FunctionData* function_data;
  struct StatementData* statement_data;
  }

%type <identifier_name> IDENTIFIER
%type <number> NUMCONST

%type <opt_plus> opt_plus;
%type <iden_numconst> iden_numconst;
%type <function_data> function;
%type <statement_data> statement;


%%

start:  statement {
     exec_statement(ht, $1);
     //exit(0);
     };
statement:  function statement {
         struct StatementData* statement_data = malloc( sizeof( struct StatementData ) );
          
         statement_data->type = function_t;
         statement_data->function = $1;
         statement_data->statement = $2;
        
         $$ = statement_data;
}; 
function:   FOR_START IDENTIFIER EQUAL iden_numconst SEMICOLON IDENTIFIER LESS iden_numconst SEMICOLON IDENTIFIER INCREMENT END_BRACK 
        //    1           2       3         4           5          6        7       8           9          10         11       12
        {
        struct FunctionData* function = malloc(sizeof( struct FunctionData));
        if( ht_get(ht, $2) != NULL ) {
          yyerror("Повторное определение переменной");
        }
        function->identifier = strdup($2); 
        Symbol* s = malloc(sizeof(Symbol));
        ht_set(ht,strdup($2), s);

        if ( strcmp($2, $6)!=0 || strcmp($2, $10)!=0 ){
          yyerror("Different IDENTIFIERs in for loop");
        }

        function->iden_numconst_start = $4;
        function->iden_numconst_end = $8;
        $$ = function;
        };
statement:  PRINTF_START iden_numconst END_BRACK SEMICOLON {
         struct StatementData* statement_data = malloc( sizeof( struct StatementData ) );
          
         statement_data->type = print;
         statement_data->iden_numconst_print = $2;
        
         $$ = statement_data;
         };
iden_numconst: NUMCONST {
             struct IdenNumconstData* iden_numconst = malloc(sizeof( struct IdenNumconstData ));
             iden_numconst->type = numconst;
             printf("numconst:%d\n", $1);
             iden_numconst->numconst = $1; 
             printf("numconst:%d\n", iden_numconst->numconst);
             $$ = iden_numconst;
};
iden_numconst: IDENTIFIER opt_plus {
             struct IdenNumconstData* iden_numconst = malloc(sizeof( struct IdenNumconstData ));
             iden_numconst->type = identifier;
             iden_numconst->opt_plus = $2;
             iden_numconst->identifier = strdup($1); 
             if( ht_get(ht, iden_numconst->identifier) == NULL ){
                yyerror("Unknown identifier");
                exit(-1);
             }
             $$ = iden_numconst;
             };
opt_plus: %empty { 
        struct OptPlusData* opt_plus = malloc(sizeof(struct OptPlusData)); 
        opt_plus->type = empty; $$ = opt_plus; };
opt_plus: INCREMENT { 
        struct OptPlusData* opt_plus = malloc(sizeof(struct OptPlusData)); 
        opt_plus->type = increment; $$ = opt_plus; };


%%


int main()
{
  ht = ht_create();
  printf("> "); 
  yyparse();
  printf("\n"); 
  return 0;
}

int yyerror(const char *s)
{
  fprintf(stderr, "error: %s\n", s);
  return -1;
}
