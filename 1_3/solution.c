// #include <stddef.h>
// #include <string.h>
// #include <stddef.h>
// #include "solution.h"
//
// int stringStat(const char *string, size_t multiplier, int *count) {
//   (*count)++;
//   return strlen(string) * multiplier;
// }
//

#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stdlib.h>

int (*ptr)(int val);

int main(int argc, char *argv[])
{
  void * hdl = dlopen(argv[1], RTLD_LAZY);
  ptr = (int (*)(int val))(dlsym(hdl, argv[2]));
  printf("%d\n", ptr(atoi(argv[3])));

  return 0;
}
