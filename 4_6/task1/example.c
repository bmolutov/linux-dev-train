#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *fp;
    int c;

    // Open a process by running the 'ls' command
    fp = popen("ls", "r");

    if (fp == NULL) {
        perror("popen() failed");
        return -1;
    }

    // Read and print each character of the output
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    sleep(999);

    // Close the pipe
    pclose(fp);

    return 0;
}
