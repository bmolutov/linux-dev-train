#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// traverse process tree from the current one
int get_parent_pid(int cur_pid) {
  char path[256];
  snprintf(path, sizeof(path), "/proc/%d/stat", cur_pid);

  FILE * stat_file = fopen(path, "r");

  if (stat_file == NULL) {
    perror("error");
    exit(EXIT_FAILURE);
  }

  int pid, ppid;
  char comm[256];
  fscanf(stat_file, "%d %s %*c %d", &pid, comm, &ppid);

  fclose(stat_file);
  return ppid;
}

int main(int argc, char *argv[])
{
  int pid = atoi(argv[1]);
  printf("%d\n", pid);

  while (pid != 1) {
    pid = get_parent_pid(pid);
    printf("%d\n", pid);
  }

  return EXIT_SUCCESS;
}
