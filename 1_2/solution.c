#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include "solution.h"

int stringStat(const char *string, size_t multiplier, int *count) {
  (*count)++;
  return strlen(string) * multiplier;
}

