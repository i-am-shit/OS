#include <stdio.h>
int main() {
    int n, i, j, time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], type[n];
    int ct[n], tat[n], wt[n];
    int sys[n], user[n];
    int sysCount = 0, userCount = 0;
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nEnter AT, BT and Type (0=System, 1=User) for P%d: ", pid[i]);
        scanf("%d %d %d", &at[i], &bt[i], &type[i]);

        if(type[i] == 0)
            sys[sysCount++] = i;
        else
            user[userCount++] = i;
    }
    for(i = 0; i < sysCount - 1; i++) {
        for(j = i + 1; j < sysCount; j++) {
            if(at[sys[i]] > at[sys[j]]) {
                int temp = sys[i];
                sys[i] = sys[j];
                sys[j] = temp;
            }
        }
    }
    for(i = 0; i < userCount - 1; i++) {
        for(j = i + 1; j < userCount; j++) {
            if(at[user[i]] > at[user[j]]) {
                int temp = user[i];
                user[i] = user[j];
                user[j] = temp;
            }
        }
    }
    for(i = 0; i < sysCount; i++) {
        int idx = sys[i];

        if(time < at[idx])
            time = at[idx];

        time += bt[idx];
        ct[idx] = time;

        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
    }
    for(i = 0; i < userCount; i++) {
        int idx = user[i];

        if(time < at[idx])
            time = at[idx];

        time += bt[idx];
        ct[idx] = time;

        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
    }
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], type[i],
               ct[i], tat[i], wt[i]);
    }
    return 0;
}
