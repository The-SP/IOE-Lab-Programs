// Create a process in UNIX.
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int id;
    printf("Before fork: Process id: %d\n", getpid());

    // Create a new process
    id = fork();
    if (id == 0) {
        printf("Child process, PID: %d\n", getpid());
    } else if (id > 0) {
        printf("Parent process, PID: %d\n", getpid());
    } else {
        printf("fork() failed.\n");
    }
    return 0;
}

// The fork() function creates a new process by duplicating the calling process. The new process, called the child, is an exact copy of the calling process, called the parent. The fork() function returns a value of 0 to the child process and returns the child's process ID to the parent process. In the example, the program uses the return value of fork() to determine whether it is running in the child or parent process and prints an appropriate message.