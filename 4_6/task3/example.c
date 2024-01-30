#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile int counter1 = 0;  // A volatile counter to be modified by signal handlers
volatile int counter2 = 0;  // A volatile counter to be modified by signal handlers

// Signal handler function for SIGUSR1
void sigusr1Handler(int signum) {
    counter1++;
}

// Signal handler function for SIGUSR2
void sigusr2Handler(int signum) {
    counter2++;
}

// Signal handler function for SIGTERM
void sigtermHandler(int signum) {
    printf("%d %d\n", counter1, counter2);
    exit(signum);
}

int main() {

    // Register the signal handler for SIGUSR1 using signal
    signal(SIGUSR1, sigusr1Handler);

    // Register the signal handler for SIGUSR2 using signal
    signal(SIGUSR2, sigusr2Handler);

    // Register the signal handler for SIGTERM using signal
    signal(SIGTERM, sigtermHandler);

    // Your main program logic goes here

    // Infinite loop to keep the program running
    while (1) {}

    return 0;
}
