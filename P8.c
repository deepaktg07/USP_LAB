#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_zombie_process() {
    if (fork() == 0) {
        printf("Zombie process created (PID: %d)\n", getpid());
        exit(0);
    }
    printf("Parent process created a zombie process\n");
}

void prevent_zombie_processes() {
    if (fork() == 0) {
        if (fork() == 0) {
            printf("Grandchild process (PID: %d)\n", getpid());
            sleep(5);
            printf("Grandchild process completed\n");
            exit(0);
        }
        exit(0);
    }
    printf("Parent process created a child process\n");
    sleep(2);
}

void create_orphan_process() {
    if (fork() == 0) {
        printf("Orphan process created (PID: %d)\n", getpid());
        sleep(5);
        printf("Orphan process completed\n");
        exit(0);
    }
    printf("Parent process\n");
    sleep(2);
}

void parent_child_scenario() {
    if (fork() == 0) {
        printf("Child process (PID: %d)\n", getpid());
        exit(0);
    }
    printf("Parent process (PID: %d)\n", getpid());
    wait(NULL);
}

int main() {
    printf("Demonstrating Zombie process:\n");
    create_zombie_process();
    sleep(5);
    printf("\nPreventing Zombie processes:\n");
    prevent_zombie_processes();
    sleep(7);
    printf("\nCreating an Orphan process:\n");
    create_orphan_process();
    printf("\nParent-Child scenario:\n");
    parent_child_scenario();
    return 0;
}
