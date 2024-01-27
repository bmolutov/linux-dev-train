#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// search parent pid of current process
int get_parent_pid() {
  FILE * stat_file = fopen("/proc/self/stat", "r");
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
  pid_t parent_pid = get_parent_pid();
  printf("%d\n", parent_pid);

  return EXIT_SUCCESS;
}
