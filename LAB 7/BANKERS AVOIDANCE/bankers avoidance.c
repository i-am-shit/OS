#include<stdio.h>

int main()
{
    int n, m, i, j, k;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10];
    int finish[10] = {0};
    int safeSeq[10];
    int work[10];

    int pid, request[10];

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &m);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

        printf("Enter Max -- ");
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
                           
    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
        scanf("%d", &available[i]);


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter New Request Details --\n");

    printf("Enter pid -- ");
    scanf("%d", &pid);

    printf("Enter Request for Resources -- ");
    for(i = 0; i < m; i++)
        scanf("%d", &request[i]);

    for(i = 0; i < m; i++)
    {
        if(request[i] > need[pid][i])
        {
            printf("ERROR: Process exceeded maximum claim\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("Resources not available\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    for(i = 0; i < m; i++)
        work[i] = available[i];

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    printf("P%d is visited(", i);

                    for(k = 0; k < m; k++)
                        printf("%d ", work[k]);

                    printf(")\n");

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
    {
        printf("\nSYSTEM IS IN SAFE STATE\n");

        printf("The Safe Sequence is -- (");

        for(i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);

            if(i != n-1)
                printf(" ");
        }

        printf(")\n");
    }
    else
    {
        printf("\nSYSTEM IS NOT IN SAFE STATE\n");
    }

    printf("\nProcess\tAllocation\tMax\t\tNeed\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);

        for(j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);

        printf("\t\t");

        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);

        printf("\t\t");

        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    return 0;
}