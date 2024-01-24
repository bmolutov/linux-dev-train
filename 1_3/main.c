#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
// #include "solution.h"

int (*stringStat)(const char *string, size_t multiplier, int *count);

bool init_library() {
  void * hdl = dlopen("./libsolution.so", RTLD_LAZY);
  if (NULL == hdl)
    return false;

  stringStat = (int (*)(const char *string, size_t multiplier, int *count))dlsym(hdl, "stringStat");
  if (NULL == stringStat)
    return false;

  return true;
}

int main(int argc, char *argv[])
{
  if (init_library()) {
    char * string = "abc";
    int count = 0;

    int res = stringStat(string, 3, &count);
    printf("%d", res);
  } else {
    printf("Error occured!\n");
  }

  return 0;
}
