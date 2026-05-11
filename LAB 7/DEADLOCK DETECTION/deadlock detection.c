#include<stdio.h>

int main()
{
    int n, m, i, j, k;

    int allocation[10][10];
    int request[10][10];
    int available[10];

    int work[10];
    int finish[10] = {0};
    int safeSeq[10];

    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Request Matrix
    printf("\nEnter Request Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Available Vector
    printf("\nEnter Available Resources:\n");

    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    // Initialize Finish
    for(i = 0; i < n; i++)
    {
        int flag = 0;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            finish[i] = 0;
        else
            finish[i] = 1;
    }

    // Detection Algorithm
    while(1)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    safeSeq[count++] = i;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    // Check Deadlock
    int deadlock = 0;

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            break;
        }
    }

    if(deadlock)
    {
        printf("\nSYSTEM IS IN DEADLOCK\n");

        printf("Deadlocked Processes:\n");

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }
    else
    {
        printf("\nSYSTEM IS NOT IN DEADLOCK\n");

        printf("Sequence: ");

        for(i = 0; i < count; i++)
        {
            printf("P%d ", safeSeq[i]);
        }

        printf("\n");
    }

    return 0;
}