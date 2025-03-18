#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

char buff[SIZE];
int in = 0, out = 0;
int empty = SIZE; // Initially, all slots are empty
int full = 0;     // Initially, no slots are full
int mutex = 1;    // Mutex is initially unlocked

void wait(int *s) {
    while (*s <= 0)
        ; // Busy-wait until the semaphore is positive
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    if (empty == 0) {
        printf("\nBuffer is full. Cannot produce.\n");
        return;
    }

    wait(&empty); // Wait if there are no empty slots
    wait(&mutex); // Enter critical section                                                                                                  

    // Produce an item
    char item;
    printf("Enter the value to produce: ");
    scanf(" %c", &item);
    buff[in] = item;
    printf("Produced: %c\n", item);
    in = (in + 1) % SIZE;

    signal(&mutex); // Exit critical section
    signal(&full);  // Signal that there is a new full slot
}

void consumer() {
    if (full == 0) {
        printf("\nBuffer is empty. Cannot consume.\n");
        return;
    }

    wait(&full); // Wait if there are no full slots
    wait(&mutex); // Enter critical section

    // Consume an item
    char item = buff[out];
    printf("Consumed: %c\n", item);
    out = (out + 1) % SIZE;

    signal(&mutex); // Exit critical section
    signal(&empty); // Signal that there is a new empty slot
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Produce \t 2. Consume \t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}
