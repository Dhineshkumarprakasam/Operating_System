#include <stdio.h>

int main()
{
    int n,at[10],bt[10],x[10],ct[10],tat[10],wt[10],count=0,time=0,end=0,smallest;

    printf("Enter n : ");
    scanf("%d",&n);

    printf("Enter at : ");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter bt : ");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    for(int i=0;i<n;i++)
        x[i]=bt[i];

    bt[9]=9999;
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
                smallest=i;
        }

        if(smallest!=9)
        {
            time+=bt[smallest]-1;
            bt[smallest]=0;
        }

        if(bt[smallest]==0)
        {
            count++;
            end=time+1;
            ct[smallest]=end;
            tat[smallest]=end-at[smallest];
            wt[smallest]=end-at[smallest]-x[smallest];
        }
    }

    printf("\t pid \t at \t bt \t ct \t tat \t wt");
    printf("\n-----------------------------------------------------------------");

    for(int i=0;i<n;i++)
    {
        printf("\n\t %d \t %d \t %d \t %d \t %d \t %d",i+1,at[i],x[i],ct[i],tat[i],wt[i]);
    }

}
