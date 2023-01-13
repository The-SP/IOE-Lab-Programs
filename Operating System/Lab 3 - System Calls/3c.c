// Create a child with sleep command.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int id;
    id = fork();

    if (id == 0) {
        sleep(3);
        printf("Child process, PID: %d\n", getpid());
    } else if (id > 0) {
        printf("Parent process, PID: %d\n", getpid());
        wait(NULL);
    } else {
        printf("fork() failed.\n");
    }
    return 0;
}