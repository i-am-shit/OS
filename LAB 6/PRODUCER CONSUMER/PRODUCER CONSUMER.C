#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;  
int x=0;

void wait(int *s) {
    (*s)--;
}


void signal(int *s) {
    (*s)++;
}


void producer() {
    wait(&empty);
    wait(&mutex);

    x++;
    printf("Producer has produced item %d\n", x);

    signal(&mutex);
    signal(&full);
}

 
void consumer() {
    wait(&full);
    wait(&mutex);

    printf("Consumer has consumed item %d\n", x);
    x--;

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full!\n");
                break;

            case 2:
                if(mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;

            case 3:
                exit(0);
        }
    }

    return 0;
}