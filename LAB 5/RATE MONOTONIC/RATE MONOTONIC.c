#include <stdio.h>
#include <math.h>

#define MAX 20

int main() {
    int n, i, j;
    float Ci[MAX], Ti[MAX];
    float U = 0, bound;

    
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    
    for(i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        printf("Execution Time (C%d): ", i + 1);
        scanf("%f", &Ci[i]);
        printf("Period (T%d): ", i + 1);
        scanf("%f", &Ti[i]);
    }

 
    for(i = 0; i < n; i++) {
        U += (Ci[i] / Ti[i]);
    }

    printf("\nCPU Utilization (U) = %.4f\n", U);


    bound = n * (pow(2, 1.0/n) - 1);
    printf("RMS Bound = %.4f\n", bound);

   
    if(U <= bound) {
        printf("Schedulable using RMS\n");
    } else {
        printf("Not guaranteed schedulable (need further analysis)\n");
    }

   
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(Ti[i] > Ti[j]) {
                
                float temp = Ti[i];
                Ti[i] = Ti[j];
                Ti[j] = temp;

             
                temp = Ci[i];
                Ci[i] = Ci[j];
                Ci[j] = temp;
            }
        }
    }

    printf("\nTasks after priority assignment (Lower T = Higher Priority):\n");
    printf("Priority\tExecution Time\tPeriod\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%.2f\t\t%.2f\n", i + 1, Ci[i], Ti[i]);
    }


    int time = 0, limit = 20; 
    printf("\nScheduling (Time vs Task Executed):\n");

    while(time < limit) {
        int executed = 0;

        for(i = 0; i < n; i++) {
          
            if(time % (int)Ti[i] == 0) {
                printf("Time %d: Task %d is READY\n", time, i + 1);
                printf("Executing Task %d\n", i + 1);
                executed = 1;
                break; 
            }
        }

        if(!executed) {
            printf("Time %d: CPU Idle\n", time);
        }

        time++;
    }

    return 0;
}