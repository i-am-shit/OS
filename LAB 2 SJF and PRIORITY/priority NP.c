#include<stdio.h>

int main(){
    int n,i,j;
    int at[10],bt[10],pr[10],ct[10],wt[10],tat[10],p[10];
    float twt=0,ttat=0,awt,att;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pr[i] > pr[j]){
                int temp;

                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=p[i];  p[i]=p[j];  p[j]=temp;
            }
        }
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        twt+=wt[i];
        ttat+=tat[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }

    awt=twt/n;
    att=ttat/n;

    printf("\nAverage Waiting Time = %.2f",awt);
    printf("\nAverage Turnaround Time = %.2f",att);

    return 0;
}
