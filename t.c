#include <stdio.h>

int main() {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = i; k < j; k++)
        printf("%d;", j);

  printf("\n");
  return 0;
}
