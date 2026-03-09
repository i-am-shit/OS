#include<stdio.h>

int main() {
    int n,i,j;
    int at[10],bt[10],ct[10],wt[10],tat[10];
    float twt=0, ttat=0, awt, att;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i] > bt[j]){
                int temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];

    for(i=1;i<n;i++){
        ct[i] = ct[i-1] + bt[i];
    }

    for(i=0;i<n;i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    awt = twt/n;
    att = ttat/n;

    printf("\nAverage Waiting Time = %.2f",awt);
    printf("\nAverage Turnaround Time = %.2f",att);

    return 0;
}
