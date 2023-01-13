// Perform wait command using C program.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int id;
    id = fork();

    if (id == 0) {
        printf("Child process, PID: %d\n", getpid());
        return 0;
    } else if (id > 0) {
        int status;
        wait(&status);
        printf("Parent process, PID: %d\n", getpid());
        printf(" Its Child process PID:%d terminated with status %d\n", id, status);
    } else {
        printf("fork() failed.\n");
    }
    return 0;
}

// Parent process calls wait() to wait for the child process to terminate. The child process simply prints its pid and exits with status 0. The parent process then prints the pid of the child process and its exit status.