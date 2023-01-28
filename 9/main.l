%{
  #include "main.tab.h"
  //enum yytokentype {
  //  FOR_START = 258,
  //  EQUAL = 259,
  //  SEMICOLON = 260,
  //  NUMCONST = 261,
  //  FOR_END = 262,
  //  INCREMENT = 263,
  //  PRINTF_START = 264,
  //  PRINTF_END = 265,
  //  LESS = 266,
  //  IDENTIFIER
  //};
  //int yylval;
//(\+\+)[[:space:]]*\) { printf("FOR_END:%s\n", yytext); return FOR_END; }
%}

%%

(for)[[:space:]]*\( { printf("FOR_START:%s\n", yytext); return FOR_START; }
"=" { printf("EQUAL:%s\n", yytext); return EQUAL; }
"<" { printf("LESS:%s\n", yytext); return LESS; }
";" { printf("SEMICOLON:%s\n", yytext); return SEMICOLON; }
"++" { printf("INCREMENT:%s\n", yytext); return INCREMENT; }
")" { printf("END_BRACK:%s\n", yytext); return END_BRACK; }
[0-9]+	{ yylval = atoi(yytext); printf("NUMCONST:%s\n", yytext); return NUMCONST; }
(print)[[:space:]]*\( { printf("PRINTF_START:%s\n", yytext); return PRINTF_START; }
(\))[[:space:]]*; { printf("PRINTF_END:%s\n", yytext); return PRINTF_END; }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(yylval, yytext); printf("IDENTIFIER:%s\n", yytext); return IDENTIFIER; }


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
