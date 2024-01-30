#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
  int in1 = open("in1", O_RDONLY | O_NONBLOCK);
  int in2 = open("in2", O_RDONLY | O_NONBLOCK);

  if (in1 == -1 || in2 == -1)
    return 0;

  fd_set readSet;
  int ans = 0;
  struct timeval timeout;

  while (1) {
    FD_ZERO(&readSet);
    FD_SET(in1, &readSet);
    FD_SET(in2, &readSet);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    int ready = select(in1 + 1, &readSet, NULL, NULL, NULL);
    if (ready == -1) {
      break;
    }

    if (ready > 0) {
      if (FD_ISSET(in1, &readSet)) {
        int val;
        if (fscanf(in1, "%d", &val) == 1)
          ans += val;
      }

      if (FD_ISSET(in2, &readSet)) {
        int val;
        if (fscanf(in2, "%d", &val) == 1)
          ans += val;
      }
    }
  }

  printf("%d\n", ans);

  return EXIT_SUCCESS;
}
