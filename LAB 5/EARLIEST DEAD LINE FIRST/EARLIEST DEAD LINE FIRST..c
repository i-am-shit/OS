#include <stdio.h>

#define MAX 20

int main() {
    int n, i, t = 0, completed = 0;
    
    int at[MAX], bt[MAX], rt[MAX], dl[MAX];
    float U = 0;

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Execution Time: ");
        scanf("%d", &bt[i]);
        printf("Deadline: ");
        scanf("%d", &dl[i]);

        rt[i] = bt[i]; 

        
        U += (float)bt[i] / dl[i];
    }

    
    printf("\nCPU Utilization (U) = %.4f\n", U);

    if(U > 1)
        printf("Scheduling not feasible (deadlines may be missed)\n");
    else
        printf("Scheduling feasible\n");

    printf("\nEDF Scheduling Execution:\n");

    
    while(completed < n) {
        int idx = -1;
        int min_deadline = 9999;

      
        for(i = 0; i < n; i++) {
            if(at[i] <= t && rt[i] > 0) {
                if(dl[i] < min_deadline) {
                    min_deadline = dl[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            printf("Time %d: CPU Idle\n", t);
            t++;
            continue;
        }

      
        printf("Time %d: Executing Process P%d\n", t, idx + 1);
        rt[idx]--;

       
        if(rt[idx] == 0) {
            completed++;
            printf("Process P%d completed at time %d\n", idx + 1, t + 1);
        }

        t++;
    }

    return 0;
}