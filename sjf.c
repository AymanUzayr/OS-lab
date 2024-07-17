#include<stdio.h>
#include<string.h>

int main()
{
    int i=0,pno[10],bt[10],n,wt[10],temp=0,j,tat[10];
    float sum=0,ttat=0;

    printf("\n Enter the no of process ");
    scanf("%d",&n);

    printf("\n Enter the burst time of each process");
    for(i=0;i<n;i++)
    {
        printf("\n p%d",i);
        scanf("%d",&bt[i]);
        pno[i]=i; // Assigning process numbers
    }

    // Sorting processes based on burst time using Bubble Sort
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pno[i];
                pno[i]=pno[j];
                pno[j]=temp;
            }
        }
    }

    // Calculating waiting time for each process
    wt[0]=0; // First process has 0 waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1]; // Waiting time is cumulative burst time of previous processes
        sum+=wt[i]; // Sum of waiting times
    }

    // Calculating turnaround time and average turnaround time
    printf("\n process no \t burst time\t waiting time \t turn around time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; // Turnaround time = Burst time + Waiting time
        ttat+=tat[i]; // Sum of turnaround times
        printf("\n p%d\t\t%d\t\t%d\t\t%d",pno[i],bt[i],wt[i],tat[i]);
    }

    // Printing average waiting time and average turnaround time
    printf("\n\n\t Average waiting time: %f", sum/n);
    printf("\n\t Average turn around time: %f\n", ttat/n);

    return 0;
}
