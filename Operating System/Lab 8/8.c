// Producer Consumer Problem using Semaphore

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
int buffer[MAX_ITEMS];
int empty, full = 0, mutex = 1; // Semaphores
int item, itemC, n;
int in = 0, out = 0;

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void producer() {
    mutex = wait(mutex);
    empty = wait(empty);
    full = signal(full);
    printf("Enter an item: ");
    scanf("%d", &item);
    buffer[in] = item;
    in = (in + 1) % n;
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    itemC = buffer[out];
    printf("Consumed item = %d \n", itemC);
    out = (out + 1) % n;
    mutex = signal(mutex);
}

void main() {
    printf("Enter the value of n: ");
    scanf("%d", &n);
    empty = n;

    int choice;
    printf("\nChoices: \n1. Producer \n2. Consumer \n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is full \n");
            break;
        case 2:
            if (mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is empty \n");
            break;
        default:
            exit(0);
            break;
        }
    }
}

/*
The producer-consumer problem is a classic synchronization problem that deals with the coordination of two or more concurrent processes. In this code, the producer process produces items and the consumer process consumes them. The buffer is used to store the items that are produced by the producer and consumed by the consumer.

The code uses two semaphores, "empty" and "full", to represent the number of empty and full buffer slots, respectively. The semaphore "mutex" is used to ensure mutual exclusion when accessing the shared buffer.

The wait() function is used to decrement the value of the semaphore, and the signal() function is used to increment the value of the semaphore. The wait() function ensures that the critical section of the code is executed by only one process at a time.

The producer() function adds an item to the buffer and increments the value of the "in" variable. The consumer() function retrieves an item from the buffer and increments the value of the "out" variable.

The main() function initializes the value of "n" and "empty". The producer and consumer processes run in a loop until the value of "in" becomes equal to the value of "n".
*/