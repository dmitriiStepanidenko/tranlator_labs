#pragma once

#include "symbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR_START 256   // for(
#define PRINT_START 257 // printf(
#define END_BRACK 258   // )
#define INCREMENT 259   // ++
#define SEMICOLON 260   //;
#define NUMCONST 261
#define IDENTIFIER 262
#define LESS 263
#define EQUAL 264

//<statement> ::= <function><statement>
//<statement> ::= printf( <iden_numconst> );
//<function> ::= for( IDENTIFIER = <iden_numconst>; IDENTIFIER <
//<iden_numconst>; IDENTIFIER ++)
//
//<iden_numconst> ::= NUMCONST
//<iden_numconst> ::= IDENTIFIER <opt_plus>
//
//<opt_plus> ::= e
//<opt_plus> ::= ++
//
//
int error(char *msg) {
  printf("%s\n", msg);
  exit(1);
}

char *token_to_string(int token_number) {
  switch (token_number) {
  case FOR_START: {
    char *p = "FOR_START";
    return strdup(p);
  }
  case PRINT_START: {
    char *p = "PRINT_START";
    return strdup(p);
  }
  case END_BRACK: {
    char *p = "END_BRACK";
    return strdup(p);
  }
  case INCREMENT: {
    char *p = "INCREMENT";
    return strdup(p);
  }

  case SEMICOLON: {
    char *p = "SEMICOLON";
    return strdup(p);
  }
  case NUMCONST: {
    char *p = "NUMCONST";
    return strdup(p);
  }
  case IDENTIFIER: {
    char *p = "IDENTIFIER";
    return strdup(p);
  }
  case LESS: {
    char *p = "LESS";
    return strdup(p);
  }
  case EQUAL: {
    char *p = "EQUAL";
    return strdup(p);
  }
  }
  error("Unknown token number");
}

int symbol;
int value;
char buf[256];
int size = -1;
FILE *current_stream;
HashTable *ht;

int is_print_start() {
  if (size == 6 || size == 7) {
    if (buf[0] == 'p' && buf[1] == 'r' && buf[2] == 'i' && buf[3] == 'n' &&
        buf[4] == 't' && buf[5] == 'f' && buf[6] == '(')
      return 1;
    if (buf[0] == 'p' && buf[1] == 'r' && buf[2] == 'i' && buf[3] == 'n' &&
        buf[4] == 't' && buf[5] == '(')
      return 1;
  }
  return 0;
}
int is_for_start() {
  if (size == 4) {
    if (buf[0] == 'f' && buf[1] == 'o' && buf[2] == 'r' && buf[3] == '(')
      return 1;
  }

  return 0;
}

int is_any_separator(char t) {
  if (t == ' ' || t == '\t' || t == '\n' || t == '\r' || t == EOF)
    return 1;
  return 0;
}

int is_any_token(char t) {
  if (t == '+' || t == ';' || t == '<' || t == '=' || t == ')')
    return 1;
  return 0;
}

int return_token(char t) {
  switch (t) {
  case ')':
    return END_BRACK;
  case '=':
    return EQUAL;
  case '<':
    return LESS;
  case ';':
    return SEMICOLON;
  case '+': {
    t = getc(current_stream);
    if (t == '+')
      return INCREMENT;
    error("Expected +");
  }
  }
  error("Internal error");
}

int t;
int scan() {
  for (int i = 0; i < 255; i++)
    buf[i] = '\0';
  size = -1;
  while (1) {
    t = getc(current_stream);
    if (is_any_separator(t)) {
    } else if (is_any_token(t)) {
      return return_token(t);
    } else if (t >= '0' && t <= '9') {
      value = t - '0';
      t = getc(current_stream);
      while (t >= '0' && t <= '9') {
        value = value * 10 + t - '0';
        t = getc(current_stream);
      }
      if (is_any_token(t))
        ungetc(t, current_stream);
      return NUMCONST;
    } else if (t == EOF)
      return EOF;
    else {
      size = 0;
      buf[size] = t;
      size = size + 1;
      while (1) {
        if (is_for_start())
          return FOR_START;
        if (is_print_start())
          return PRINT_START;
        if (size + 1 > 255)
          error("Exceed size of IDENTIFIER (256)");
        t = getc(current_stream);
        if (is_any_token(t) || is_any_separator(t)) {
          if (is_any_token(t)) {
            ungetc(t, current_stream);
          }
          break;
        }
        buf[size] = t;
        size = size + 1;
      }
      buf[size] = '\0';
      return IDENTIFIER;
    }
  }
  // return NUMCONST, IDENTIFIER, ...
}

typedef struct {
  int value;
} Symbol;

typedef struct {
  enum type_t_opt_plus {
    empty,
    increment,
  } type;
} OptPlusData;

typedef struct {
  enum type_t_iden_numconst {
    numconst,
    identifier,
  } type;
  int numconst;
  char identifier[256];
  OptPlusData opt_plus;

} IdenNumconstData;

typedef struct {
  char identifier[256];
  IdenNumconstData iden_numconst_start;
  IdenNumconstData iden_numconst_end;
} FunctionData;

typedef struct StatementData {
  enum type_t_statement { print, function_t } type;
  FunctionData function;
  IdenNumconstData iden_numconst_print;
  struct StatementData *statement;
} tStatementData;

void exec_statement(tStatementData *data);
void exec_function(FunctionData *function_data, tStatementData *statement_data);

void opt_plus(OptPlusData *data) {
  //<opt_plus> ::= e
  //<opt_plus> ::= ++
  if (symbol == INCREMENT) {
    data->type = increment;
  } else {
    data->type = empty;
    ungetc(t, current_stream); // Т.к. правило может быть пусто, то нужно
                               // вернуть символ
  }
}

void iden_numconst(IdenNumconstData *data) {
  //<iden_numconst> ::= NUMCONST
  //<iden_numconst> ::= IDENTIFIER <opt_plus>
  if (symbol == NUMCONST) {
    data->type = numconst;
    data->numconst = value;

  } else if (symbol == IDENTIFIER) {
    data->type = identifier;
    for (int i = 0; i < size; i++) {
      data->identifier[i] = buf[i];
    }
    data->identifier[size] = '\0';

    symbol = scan();
    opt_plus(&data->opt_plus);
  } else
    error("Wrong input iden_numconst");
}

void function(FunctionData *data) {
  //<function> ::= for( IDENTIFIER = <iden_numconst>; IDENTIFIER <
  //<iden_numconst>; IDENTIFIER ++)

  if (symbol != FOR_START) {
    error("Wrong input. Expected for(");
  }

  // scan IDENTIFIER declaration
  symbol = scan();
  if (symbol != IDENTIFIER && size > 0)
    error("Expected IDENTIFIER\n");
  strcpy(data->identifier, buf);
  if (ht_get(ht, data->identifier) != NULL)
    error("Redeclaration of variable");
  Entry *new_entry = malloc(sizeof(Entry));
  Symbol *new_symbol = malloc(sizeof(Symbol));
  new_entry->value = new_symbol;
  ht_set(ht, data->identifier, new_entry);

  // scan =
  symbol = scan();
  if (symbol != EQUAL)
    error("Expected =\n");

  // scan iden_numconst
  symbol = scan();
  iden_numconst(&data->iden_numconst_start);
  if (data->iden_numconst_start.type == numconst) {
    new_symbol->value = data->iden_numconst_start.numconst;
  } else {
    Symbol *start_symbol = ht_get(ht, data->iden_numconst_start.identifier);
    if (start_symbol == NULL) {
      error("Unknown variable\n");
    } else {
      new_symbol->value = start_symbol->value;
    }
  }

  // scan ;
  symbol = scan();
  if (symbol != SEMICOLON)
    error("Expected ; after for( IDENTIFIER = <iden_numconst>\n");

  // scan IDENTIFIER
  symbol = scan();
  if (symbol != IDENTIFIER && size > 0)
    error("Expected IDENTIFIER\n");
  if (strcmp(data->identifier, buf) != 0)
    error("Different IDENTIFIER\n");

  // scan LESS
  symbol = scan();
  if (symbol != LESS)
    error("Expected <\n");

  // scan iden_numconst
  symbol = scan();
  iden_numconst(&data->iden_numconst_end);
  if (data->iden_numconst_end.type == identifier) {
    Symbol *end_symbol = ht_get(ht, data->iden_numconst_end.identifier);
    if (end_symbol == NULL) {
      error("Unknown variable\n");
    }
  }

  // scan ;
  symbol = scan();
  if (symbol != SEMICOLON)
    error("Expected ; after for( IDENTIFIER = <iden_numconst> ; IDENTIFIER < "
          "<iden_numconst> \n");

  // scan IDENTIFIER
  symbol = scan();
  if (symbol != IDENTIFIER && size > 0)
    error("Expected IDENTIFIER\n");
  if (strcmp(data->identifier, buf) != 0)
    error("Different IDENTIFIER\n");

  // scan INCREMENT
  symbol = scan();
  if (symbol != INCREMENT)
    error("Expected ++ at the end of for\n");

  // scan )
  symbol = scan();
  if (symbol != END_BRACK)
    error("Expected ) at the end of for\n");
}

void statement(tStatementData *data) {
  //<statement> ::= <function><statement>
  //<statement> ::= printf( <iden_numconst> );
  if (symbol == FOR_START) {
    data->type = function_t;
    function(&data->function);

    symbol = scan();
    data->statement = malloc(sizeof(tStatementData));
    statement(data->statement);
  } else if (symbol == PRINT_START) {
    data->type = print;

    symbol = scan();
    iden_numconst(&data->iden_numconst_print);
    if (data->iden_numconst_print.type == identifier) {
      Symbol *symbol = ht_get(ht, data->iden_numconst_print.identifier);
      if (symbol == NULL) {
        error("Unknown variable\n");
      }
    }

    symbol = scan();
    if (symbol != END_BRACK)
      error("Expected )");
    symbol = scan();
    if (symbol != SEMICOLON)
      error("Expected ;");
  } else if (symbol != EOF) {
    error("Wrong input. Expected FOR_START or PRINT_START");
  } else if (symbol == EOF) {
    printf("\nEOF!!\n");
  }
}

void exec_function(FunctionData *function_data,
                   tStatementData *statement_data) {
  int *value = &((Symbol *)ht_get(ht, function_data->identifier))->value;
  int end_val;
  if (function_data->iden_numconst_start.type == numconst) {
    *value = function_data->iden_numconst_start.numconst;
  } else {
    int *start_val_ptr =
        &((Symbol *)ht_get(ht, function_data->iden_numconst_start.identifier))
             ->value;
    *value = *start_val_ptr;
    if (function_data->iden_numconst_start.opt_plus.type == increment)
      (*start_val_ptr)++;
  }
  if (function_data->iden_numconst_end.type == numconst) {
    end_val = function_data->iden_numconst_end.numconst;
  } else {
    int *end_val_ptr =
        &((Symbol *)ht_get(ht, function_data->iden_numconst_end.identifier))
             ->value;
    end_val = *end_val_ptr;
    if (function_data->iden_numconst_end.opt_plus.type == increment)
      (*end_val_ptr)++;
  }
  while (*value < end_val) {
    if (function_data->iden_numconst_end.type == numconst) {
      end_val = function_data->iden_numconst_end.numconst;
    } else {
      int *end_val_ptr =
          &((Symbol *)ht_get(ht, function_data->iden_numconst_end.identifier))
               ->value;
      end_val = *end_val_ptr;
      if (function_data->iden_numconst_end.opt_plus.type == increment)
        (*end_val_ptr)++;
    }
    exec_statement(statement_data);
    (*value)++;
  }
}

void exec_statement(tStatementData *data) {
  if (data->type == print) {
    int *value;
    if (data->iden_numconst_print.type == numconst) {
      value = &data->iden_numconst_print.numconst;
    } else {
      value =
          &((Symbol *)ht_get(ht, data->iden_numconst_print.identifier))->value;
    }
    printf("%d;", *value);
    if (data->iden_numconst_print.opt_plus.type == increment)
      (*value)++;
  } else {
    exec_function(&data->function, data->statement);
  }
}
