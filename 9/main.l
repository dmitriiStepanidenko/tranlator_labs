%{
  #include "main.tab.h"
  #include <stdio.h>
  #include <string.h>
  //enum yytokentype {
  //  FOR_START = 258,
  //  EQUAL = 259,
  //  SEMICOLON = 260,
  //  NUMCONST = 261,
  //  FOR_END = 262,
  //  INCREMENT = 263,
  //  PRINTF_START = 264,
  //  LESS = 266,
  //  IDENTIFIER
  //};
  //int yylval;
//(\+\+)[[:space:]]*\) { printf("FOR_END:%s\n", yytext); return FOR_END; }
  int yywrap();
%}

for_start (for)[[:space:]]*\(
numconst  [0-9]+
print_start (print)[[:space:]]*\( 
identifier [a-zA-Z_][a-zA-Z0-9_]*
%%

{for_start} {  return FOR_START; }
"=" { return EQUAL; }
"<" { return LESS; }
";" {  return SEMICOLON; }
"++" { return INCREMENT; }
")" {  return END_BRACK; }
{identifier} { 
  size_t len = strlen(yytext);
  yylval.identifier_name = malloc(len+1);
  sscanf(yytext, "%s", yylval.identifier_name);  
  return IDENTIFIER; }
{numconst}	{ 
  printf("NUMCONST:%d\n", atoi(yytext)); 
  yylval.number = atoi(yytext);  
  printf("NUMCONST:%d\n", yylval.number); 
  return NUMCONST; }
{print_start} {  return PRINTF_START; }


%%
//main()
//{
//  int tok;
//
//  while(tok = yylex()) {
//    printf("%d\n", tok);
//    //else printf("\n");
//  }
//}
int yywrap(){
  return 1;
}
