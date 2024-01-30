#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int c;

  char input_buff[100];
  sprintf(input_buff, "%s %s\n", argv[1], argv[2]);

  // Open a process by running the 'ls' command
  fp = popen(input_buff, "r");

  if (fp == NULL) {
      perror("popen() failed");
      return -1;
  }

  int terminators = 0;

  // Read and print each character of the output
  while ((c = fgetc(fp)) != EOF) {
    if (c == '0') 
      ++terminators;
  }
  printf("%d\n", terminators);

  // Close the pipe
  pclose(fp);

  return 0;
}
