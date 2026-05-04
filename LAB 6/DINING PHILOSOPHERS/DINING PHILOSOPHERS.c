#include <stdio.h>
#include <stdlib.h>

#define N 5

int chopstick[N] = {1,1,1,1,1};
int room = N - 1;


void wait(int *s) {
    while(*s <= 0);  
    (*s)--;
}


void signal(int *s) {
    (*s)++;
}

void philosopher(int i) {
    printf("Philosopher %d is thinking\n", i);

    wait(&room);

    wait(&chopstick[i]);                
    printf("Philosopher %d picked LEFT chopstick %d\n", i, i);

    wait(&chopstick[(i+1)%N]);       
    printf("Philosopher %d picked RIGHT chopstick %d\n", i, (i+1)%N);

    printf("Philosopher %d is EATING\n", i);

    signal(&chopstick[i]);
    signal(&chopstick[(i+1)%N]);

    printf("Philosopher %d has finished eating\n", i);

    signal(&room);
}

int main() {
    int i;

    for(i = 0; i < N; i++) {
        philosopher(i);
    }

    return 0;
}