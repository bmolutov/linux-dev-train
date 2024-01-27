#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// we are given pid, we need to count all children in tree
int traverse_children(int pid) {
  char path[256];
  snprintf(path, sizeof(path), "/proc/%d/task/%d/children", pid, pid);

  FILE * children_file = fopen(path, "r");
  if (children_file == NULL) {
    perror("error while opening children_file");
    exit(EXIT_FAILURE);
  }

  int ans = 0;

  char line[256];
  if (fgets(line, sizeof(line), children_file) != NULL) {
    char * token = strtok(line, " ");
    while (token != NULL) {
      // printf("child pid: %s\n", token);
      ans += traverse_children(atoi(token));

      token = strtok(NULL, " ");
      ++ans;
    }
  }

  fclose(children_file);
  return ans;
}

int main(int argc, char *argv[])
{
  int pid = atoi(argv[1]);
  int ans = traverse_children(pid);
  ++ans; // + current process
  printf("%d\n", ans);

  return EXIT_SUCCESS;
}
