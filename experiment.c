#include "lib.h"
#include "symbol.h"
#include <string.h>

void set() {
  ht = ht_create();
  Entry *new_entry = malloc(sizeof(Entry));
  Symbol *symbol = malloc(sizeof(Symbol));
  new_entry->value = symbol;
  char *name1 = "dkfjd1";
  char *name2 = "dkfjd2";
  ht_set(ht, name1, new_entry);
  ht_set(ht, name2, new_entry);
}

int main() {
  set();
  char *name1 = "dkfjd1";
  char *name2 = "dkfjd2";

  if (ht_get(ht, name1) == NULL)
    printf("name1=NULL\n");
  if (ht_get(ht, name2) == NULL)
    printf("name2=NULL\n");

  return 0;
}
