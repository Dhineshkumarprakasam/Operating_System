#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int findMin(int arr[],int n)
{
    int min=0;
    for(int i=1;i<n;i++)
        if(arr[i]<arr[min])
            min=i;
    return min;
}

bool allDone(int arr[],int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]>0)
            return false;
    return true;
}

int main()
{
    int n;
    printf("Enter no.of Process : ");
    scanf("%d",&n);

    int at[n],bt[n],ct[n],tat[n],wt[n],gc[100],done[n],dat[n],idx=0;
    printf("Enter Arrival Time : ");
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        dat[i]=data;
        at[i]=data;
    }
        

    printf("Enter Burst Time : ");
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        bt[i]=data;
        done[i]=data;
    }
        

    while(!allDone(done,n))
    {
        int first=findMin(dat,n);
        gc[idx]=first;
        dat[first]=INT_MAX;
        done[first]=0;
        idx++;
    }

    ct[0]=bt[gc[0]];
    for(int i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[gc[i]];
    }

    //tat = ct - at
    for(int i=0;i<n;i++)
    {
        tat[gc[i]]=ct[gc[i]]-at[gc[i]];
    }

    //wt = tat - bt
    for(int i=0;i<n;i++)
    {
        wt[gc[i]]=tat[gc[i]]-bt[gc[i]];
    }

    // displaying 

    printf("Gannt Chart:\n");

    for(int i=0;i<n;i++)
        printf("|----");
    printf("|\n");

    for(int i=0;i<n;i++)
        printf("| p%d ",gc[i]);
    printf("|\n");

    for(int i=0;i<n;i++)
        printf("|----");
    printf("|\n");

    printf("%d    ",0);
    for(int i=0;i<n;i++)
        printf("%d    ",ct[gc[i]]);
    printf("\n");



    printf("\n\n");
    printf("|\tPid\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t\n");
    printf("------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",gc[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n");
}
