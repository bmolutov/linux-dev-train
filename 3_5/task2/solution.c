#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define STATUS_FILE "status"
#define MAX_BUF_SIZE 512

// search and count number of processes with name "genenv"
void solve() {
  DIR * dir;
  struct dirent * entry;
  FILE * status_file;
  char path[MAX_BUF_SIZE];
  char line[MAX_BUF_SIZE];
  char name[MAX_BUF_SIZE];

  // open the /proc
  dir = opendir("/proc");
  if (dir == NULL) {
    perror("perror: opening /proc");
    exit(EXIT_FAILURE);
  }

  // store result
  int cnt = 0;

  // read each entry in /proc
  while ((entry = readdir(dir)) != NULL) {
    // check if the entry is a directory and contains only digits
    if (entry->d_type == DT_DIR && atoi(entry->d_name) > 0) {
      snprintf(path, sizeof(path), "/proc/%s/%s", entry->d_name, STATUS_FILE);

      // open the status file
      status_file = fopen(path, "r");
      if (status_file == NULL) {
        continue;
      }

      // read the process name
      while (fgets(line, sizeof(line), status_file) != NULL) {
        if (sscanf(line, "Name: %s", name) == 1) {
          if (strstr(name, "genenv") != NULL) {
            ++cnt;
          }
        }
      }

      fclose(status_file);
    }
  }

  closedir(dir);

  // print result
  printf("%d\n", cnt);
}

int main(int argc, char *argv[])
{
  solve();

  return EXIT_SUCCESS;
}
