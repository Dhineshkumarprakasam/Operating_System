
#include <stdio.h>

int main()
{
    int n,at[10],bt[10],x[10],ct[10],tat[10],wt[10],pr[10],count=0,time=0,end=0,highest;

    printf("Enter n : ");
    scanf("%d",&n);

    printf("Enter at : ");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter bt : ");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter pr : ");
    for(int i=0;i<n;i++)
        scanf("%d",&pr[i]);

    for(int i=0;i<n;i++)
        x[i]=bt[i];

    for(time=0;count!=n;time++)
    {
        highest=-1;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && (highest==-1 || pr[i]>pr[highest]) && bt[i]>0)
                highest=i;
        }

        if(highest!=-1)
        {
            time+=bt[highest]-1;
            bt[highest]=0;
        }

        if(bt[highest]==0)
        {
            count++;
            end=time+1;
            ct[highest]=end;
            tat[highest]=end-at[highest];
            wt[highest]=end-at[highest]-x[highest];
        }
    }

    printf("\t pid \t at \t bt \t ct \t tat \t wt");
    printf("\n-----------------------------------------------------------------");

    for(int i=0;i<n;i++)
    {
        printf("\n\t %d \t %d \t %d \t %d \t %d \t %d",i+1,at[i],x[i],ct[i],tat[i],wt[i]);
    }

}
