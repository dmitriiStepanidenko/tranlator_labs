#include "lib.h"
#include "miniunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_setup(void) {
  current_stream = NULL;
  ht = ht_create();
}

void test_teardown(void) {
  fseek(current_stream, 0, SEEK_END);
  ht_destroy(ht);
}

void write_string_to_stdin(char *str) {
  current_stream = fmemopen(str, strlen(str), "r+");
}

MU_TEST(test_scaner_identifier) {
  char input[] = "i";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp(input, buf) == 0);
}

MU_TEST(test_scaner_equal_after_identifier) {
  char input[] = "i=";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp("i", buf) == 0);

  symbol = scan();
  mu_check(symbol == EQUAL);
}

void test_scan_for(char *identifier, char *start_identifier, int start_numconst,
                   char *end_identifier, int end_numconst) {
  // Передаем идентификатор, стартовое значение (NULL, -1), конечное значение
  symbol = scan();
  mu_check(symbol == FOR_START);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp(identifier, buf) == 0);

  symbol = scan();
  mu_check(symbol == EQUAL);

  symbol = scan();
  if (start_identifier != NULL) {
    mu_check(symbol == IDENTIFIER);
    mu_check(strcmp(start_identifier, buf) == 0);
  } else {
    mu_check(symbol == NUMCONST);
    mu_check(value == start_numconst);
  }

  symbol = scan();
  mu_check(symbol == SEMICOLON);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp(identifier, buf) == 0);

  symbol = scan();
  mu_check(symbol == LESS);

  symbol = scan();
  if (end_identifier != NULL) {
    mu_check(symbol == IDENTIFIER);
    mu_check(strcmp(end_identifier, buf) == 0);
  } else {
    mu_check(symbol == NUMCONST);
    mu_check(value == end_numconst);
  }

  symbol = scan();
  mu_check(symbol == SEMICOLON);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp(identifier, buf) == 0);

  symbol = scan();
  mu_check(symbol == INCREMENT);

  symbol = scan();
  mu_check(symbol == END_BRACK);
}

void test_scan_print(char *identifier, int is_increment) {

  symbol = scan();
  mu_check(symbol == PRINT_START);

  symbol = scan();
  mu_check(symbol == IDENTIFIER);
  mu_check(strcmp(identifier, buf) == 0);

  if (is_increment) {
    symbol = scan();
    mu_check(symbol == INCREMENT);
  }

  symbol = scan();
  mu_check(symbol == END_BRACK);

  symbol = scan();
  mu_check(symbol == SEMICOLON);
}

MU_TEST(test_scaner) {
  char input[] = "for(i=0;i<10;i++) for(j=0;j<i;j++) print(j++);";
  write_string_to_stdin(&input[0]);

  test_scan_for("i", NULL, 0, NULL, 10);
  test_scan_for("j", NULL, 0, "i", -1);
  test_scan_print("j", 1);
}

MU_TEST(test_opt_plus_increment) {
  char input[] = "++";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  OptPlusData data;
  opt_plus(&data);
  mu_check(data.type == increment);
}

MU_TEST(test_opt_plus_empty) {
  char input[] = ")";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  OptPlusData data;
  opt_plus(&data);
  mu_check(data.type == empty);
}

MU_TEST(test_iden_numconst_numconst) {
  char input[] = "123";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  IdenNumconstData data;
  iden_numconst(&data);
  mu_check(data.type == numconst);
  mu_check(data.numconst == 123);
}

MU_TEST(test_iden_numconst_identifier) {
  char input[] = "name)";
  write_string_to_stdin(&input[0]);

  printf("test");
  symbol = scan();
  printf("test");
  IdenNumconstData data;
  iden_numconst(&data);
  mu_check(data.type == identifier);
  mu_check(strcmp(data.identifier, "name") == 0);
  mu_check(data.opt_plus.type == empty);
}

MU_TEST(test_iden_numconst_identifier_increment) {
  char input[] = "name++";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  IdenNumconstData data;
  iden_numconst(&data);
  mu_check(data.type == identifier);
  mu_check(strcmp(data.identifier, "name") == 0);
  mu_check(data.opt_plus.type == increment);
}

MU_TEST(test_function) {
  char input[] = "for(i=0;i<10;i++)";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  FunctionData data;
  function(&data, 0);
  mu_check(strcmp(data.identifier, "i") == 0);

  mu_check(data.iden_numconst_start.type == numconst);
  mu_check(data.iden_numconst_start.numconst == 0);

  mu_check(data.iden_numconst_end.type == numconst);
  mu_check(data.iden_numconst_end.numconst == 10);
}

MU_TEST(test_statement) {
  char input[] = "printf(0);";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  tStatementData data;
  statement(&data, 0);

  mu_check(data.type == print);
  mu_check(data.iden_numconst_print.type == numconst);
  mu_check(data.iden_numconst_print.numconst == 0);
  // mu_check(strcmp(data.iden_numconst.identifier, "i") == 0);
  // mu_check(data.iden_numconst.opt_plus.type == increment);
}

MU_TEST(full_example) {
  char input[] = "for(i=0;i<10;i++) for(j=0;j<i;j++) print(j++);";
  write_string_to_stdin(&input[0]);

  symbol = scan();
  tStatementData data;
  statement(&data, 0);

  mu_check(data.type == function_t);

  mu_check(strcmp(data.function.identifier, "i") == 0);
  mu_check(data.function.iden_numconst_start.numconst == 0);
  mu_check(data.function.iden_numconst_end.type == numconst);
  mu_check(data.function.iden_numconst_end.numconst == 10);

  mu_check(data.statement->type == function_t);
  mu_check(strcmp(data.statement->function.identifier, "j") == 0);
  mu_check(data.statement->function.iden_numconst_start.numconst == 0);
  mu_check(data.statement->function.iden_numconst_end.type == identifier);
  mu_check(strcmp(data.statement->function.iden_numconst_end.identifier, "i") ==
           0);
  mu_check(data.statement->function.iden_numconst_end.opt_plus.type == empty);

  mu_check(data.statement->statement->type == print);
  mu_check(strcmp(data.statement->statement->iden_numconst_print.identifier,
                  "j") == 0);
  mu_check(data.statement->statement->iden_numconst_print.opt_plus.type ==
           increment);

  mu_check(strlen(input) ==
           ftell(current_stream)); // fmemopen не возвращает EOF
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
  MU_RUN_TEST(test_scaner_identifier);
  MU_RUN_TEST(test_scaner_equal_after_identifier);
  MU_RUN_TEST(test_scaner);
  MU_RUN_TEST(test_opt_plus_increment);
  MU_RUN_TEST(test_opt_plus_empty);
  MU_RUN_TEST(test_iden_numconst_numconst);
  MU_RUN_TEST(test_iden_numconst_identifier);
  MU_RUN_TEST(test_iden_numconst_identifier_increment);
  MU_RUN_TEST(test_function);
  MU_RUN_TEST(test_statement);
  MU_RUN_TEST(full_example);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
