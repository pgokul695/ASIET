#include <stdio.h>
#include <stdlib.h>

void wait(int *s) {
    (*s)--; 
}


void signal(int *s) {
    (*s)++;
}


void consumer(int *mutex, int buff[3], int *full, int *empty) {
    if (*mutex && (*full > 0)) {
        wait(full); 
        wait(mutex); 
        printf("Consumer consumed an item\n");

        for (int i = 0; i < 3 - 1; i++) {
            buff[i] = buff[i + 1];
        }
        buff[3 - 1] = 0; 

        signal(empty); 
        signal(mutex); 
    } else if (!*mutex) {
        printf("Mutex Lock cannot be acquired\n");
    } else {
        printf("The buffer is empty, nothing to consume\n");
    }
    printf("Current Buffer: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");
}


void producer(int *mutex, int buff[3], int *full, int *empty) {
    if (*mutex && (*empty > 0)) {
        wait(empty); 
        wait(mutex); 
        printf("Producer produced an item\n");

        
        for (int i = 0; i < 3; i++) {
            if (buff[i] == 0) {
                buff[i] = 1;
                break;
            }
        }

        signal(full); 
        signal(mutex); 
    } else if (!*mutex) {
        printf("Mutex Lock cannot be acquired\n");
    } else {
        printf("The buffer is full, cannot add the item to buffer\n");
    }

    printf("Current Buffer: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");
}

int main() {
    int mutex = 1, full = 0, empty = 3;
    int buff[3] = {0}; 
    int choice;
    printf("Producer Consumer Problem\n");
    while (1) {
        printf("MENU\n");
        printf("1. Consumer\n");
        printf("2. Producer\n");
        printf("3. Exit\n");
        printf("Choose an option [1-3]: ");
        scanf("%d", &choice);

        if (choice == 1) {
            consumer(&mutex, buff, &full, &empty);
        } else if (choice == 2) {
            producer(&mutex, buff, &full, &empty);
        } else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice, enter an option from [1-3]\n");
        }
    }

    return 0;
}

