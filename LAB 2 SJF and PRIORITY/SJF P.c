#include<stdio.h>

int main(){
    int n,i,time=0,smallest,complete=0;
    int at[10],bt[10],rt[10],wt[10],tat[10],ct[10];
    int min,finish;
    float twt=0.0,ttat=0.0,awt,att;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(complete<n){
        min=999;
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min=rt[i];
                smallest=i;
            }
        }

        if(smallest==-1){
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0){
            complete++;
            finish=time;

            ct[smallest]=finish;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
        }
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],wt[i],tat[i]);

        twt += wt[i];
        ttat += tat[i];
    }

    awt = twt/n;
    att = ttat/n;

    printf("\nAverage Waiting Time = %.2f",awt);
    printf("\nAverage Turnaround Time = %.2f",att);

    return 0;
}
