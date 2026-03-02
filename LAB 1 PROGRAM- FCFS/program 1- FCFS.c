#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20], temp;
    float awt, att, twt = 0, ttat = 0;

    printf("Enter number of processes (max 20): ");
    scanf("%d", &n);

    if(n > 20){
        printf("Maximum processes allowed = 20\n");
        return 0;
    }

    for(i = 0; i < n; i++){
        printf("\nProcess %d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }

    /* Sort by Arrival Time */
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(at[i] > at[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++){
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt / n;
    att = ttat / n;

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");

    for(i = 0; i < n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f", att);

    return 0;
}
