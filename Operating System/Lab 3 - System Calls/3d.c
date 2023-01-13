// Create a child with sleep command using getpid.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void display_pid() {
    printf("\n PID: %d\n Its Parent process PID:%d\n\n", getpid(), getppid());
}

int main() {
    int id;
    id = fork();

    if (id == 0) {
        printf("Child process:");
        display_pid();
        sleep(5);
        printf("Child process after sleep=5");
        display_pid();
    } else if (id > 0) {
        printf("Parent process\n\n");
        sleep(10);
        printf("Parent process after sleep=10");
        display_pid();
        wait(NULL);
    } else {
        printf("fork() failed.\n");
    }
    return 0;
}