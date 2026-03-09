#include<stdio.h>

int main(){
    int n,i,time=0,complete=0,highest;
    int at[10],bt[10],rt[10],pr[10];
    int ct[10],wt[10],tat[10];
    int min;
    float twt=0,ttat=0,awt,att;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(complete<n){
        min=999;
        highest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && pr[i]<min){
                min=pr[i];
                highest=i;
            }
        }

        if(highest==-1){
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0){
            complete++;

            ct[highest]=time;
            tat[highest]=ct[highest]-at[highest];
            wt[highest]=tat[highest]-bt[highest];

            twt+=wt[highest];
            ttat+=tat[highest];
        }
    }

    printf("\nP\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }

    awt=twt/n;
    att=ttat/n;

    printf("\nAverage Waiting Time = %.2f",awt);
    printf("\nAverage Turnaround Time = %.2f",att);

    return 0;
}
