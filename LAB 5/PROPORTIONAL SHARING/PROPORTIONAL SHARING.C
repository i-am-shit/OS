#include <stdio.h>

#define MAX 20
#define TIME_QUANTUM 10   

int main() {
    int n, i;
    int bt[MAX], rt[MAX], weight[MAX];
    int completed = 0;
    float total_weight = 0;

   
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Weight: ");
        scanf("%d", &weight[i]);

        rt[i] = bt[i];
        total_weight += weight[i];
    }

    printf("\nScheduling Execution:\n");

    while(completed < n) {
        for(i = 0; i < n; i++) {

            if(rt[i] > 0) { 

               
                float time_slice = (weight[i] / total_weight) * TIME_QUANTUM;

              
                int exec_time = (int)time_slice;
                if(exec_time <= 0) exec_time = 1;

                printf("Process P%d runs for %d units\n", i + 1, exec_time);

                
                rt[i] -= exec_time;

               
                if(rt[i] <= 0) {
                    printf("Process P%d completed\n", i + 1);
                    completed++;
                    total_weight -= weight[i];
                }
            }
        }
    }

    return 0;
}