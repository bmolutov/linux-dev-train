#include <stdio.h>
#include "solution.h"

int main(int argc, char *argv[])
{
  char * string = "abc";
  int count = 0;

  int res = stringStat(string, 3, &count);
  printf("%d", res);

  return 0;
}
