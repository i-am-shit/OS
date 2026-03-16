#include <stdio.h>

int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20], ct[20];
    int temp;
    int i, j, time = 0, remain;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d Arrival Time and Burst Time: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }


    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = rt[i];
                rt[i] = rt[j];
                rt[j] = temp;
            }
        }
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    while(remain != 0)
    {
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avg_tat += tat[i];
                    avg_wt += wt[i];

                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                           i+1, at[i], bt[i], ct[i], tat[i], wt[i]);

                    remain--;
                }
                else
                {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt/n);

    return 0;
}
