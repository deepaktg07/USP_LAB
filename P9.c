#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Signal handler registered for SIGINT (Ctrl+C)\n");

    sigset_t sigset;
    sigemptyset(&sigset);
    sigprocmask(SIG_BLOCK, NULL, &sigset);

    if (!sigismember(&sigset, SIGINT)) {
        sigaddset(&sigset, SIGINT);
        sigprocmask(SIG_BLOCK, &sigset, NULL);
        printf("Added SIGINT to the signal mask\n");
    }

    while (1) pause(); // Wait for signals

    return 0;
}
