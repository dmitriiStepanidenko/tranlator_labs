#include "lib.h"
#include "symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // current_stream = stdin;
  char input[] =
      "for(i=0;i<10;i++) for(j=0;j<10;j++) for(k=i; k<j; k++) print(j);";
  current_stream = fmemopen(input, strlen(input), "r+");
  printf("%s\n", input);

  ht = ht_create();

  tStatementData data;
  symbol = scan();
  statement(&data);
  if (!(symbol == EOF ||
        strlen(input) ==
            ftell(current_stream))) // fmemopen не возвращает в конце потока EOF
    error("Still some input exists");
  exec_statement(&data);
  printf("\n");
  return 0;
}
