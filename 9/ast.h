#pragma once
#include "hashtable.h"
#include <stdio.h>
#include <string.h>

typedef struct {
  int value;
} Symbol;

typedef struct OptPlusData {
  enum type_t_opt_plus {
    empty,
    increment,
  } type;
} tOptPlusData;

typedef struct IdenNumconstData {
  enum type_t_iden_numconst {
    numconst,
    identifier,
  } type;
  int numconst;
  char *identifier;
  struct OptPlusData *opt_plus;
} tIdenNumconstData;

typedef struct FunctionData {
  char *identifier;
  struct IdenNumconstData *iden_numconst_start;
  struct IdenNumconstData *iden_numconst_end;
} tFunctionData;

typedef struct StatementData {
  enum type_t_statement { print, function_t } type;
  struct FunctionData *function;
  struct IdenNumconstData *iden_numconst_print;
  struct StatementData *statement;
} tStatementData;

void exec_function(HashTable *, struct FunctionData *, tStatementData *);

void exec_statement(HashTable *ht, tStatementData *data) {
  if (data->type == print) {
    int *value;
    if (data->iden_numconst_print->type == numconst) {
      value = &data->iden_numconst_print->numconst;
    } else {
      value =
          &((Symbol *)ht_get(ht, data->iden_numconst_print->identifier))->value;
    }
    printf("%d;", *value);
    if (data->iden_numconst_print->opt_plus->type == increment)
      (*value)++;
  } else {
    exec_function(ht, data->function, data->statement);
  }
}

void exec_function(HashTable *ht, struct FunctionData *function_data,
                   tStatementData *statement_data) {
  int *value = &((Symbol *)ht_get(ht, function_data->identifier))->value;
  int end_val;
  if (function_data->iden_numconst_start->type == numconst) {
    *value = function_data->iden_numconst_start->numconst;
  } else {
    int *start_val_ptr =
        &((Symbol *)ht_get(ht, function_data->iden_numconst_start->identifier))
             ->value;
    *value = *start_val_ptr;
    if (function_data->iden_numconst_start->opt_plus->type == increment)
      (*start_val_ptr)++;
  }
  if (function_data->iden_numconst_end->type == numconst) {
    end_val = function_data->iden_numconst_end->numconst;
  } else {
    int *end_val_ptr =
        &((Symbol *)ht_get(ht, function_data->iden_numconst_end->identifier))
             ->value;
    end_val = *end_val_ptr;
    if (function_data->iden_numconst_end->opt_plus->type == increment)
      (*end_val_ptr)++;
  }
  while (*value < end_val) {
    if (function_data->iden_numconst_end->type == numconst) {
      end_val = function_data->iden_numconst_end->numconst;
    } else {
      int *end_val_ptr =
          &((Symbol *)ht_get(ht, function_data->iden_numconst_end->identifier))
               ->value;
      end_val = *end_val_ptr;
      if (function_data->iden_numconst_end->opt_plus->type == increment)
        (*end_val_ptr)++;
    }
    exec_statement(ht, statement_data);
    (*value)++;
  }
}
