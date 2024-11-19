#include <stdio.h>

int hasnonzero(int arr[],int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]>0)
            return 1;
    return 0;
}

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int bt[n],x[n],ct[n],tat[n],wt[n];

    printf("Enter bt : ");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    for(int i=0;i<n;i++)
        x[i]=bt[i];

    int qt;
    printf("Enter qt : ");
    scanf("%d",&qt);

    int time=0;

    while(hasnonzero(x,n))
    {
        for(int i=0;i<n;i++)
        {
            int finished=0;
            if(x[i]!=0)
            {
                if(x[i]-qt >=0)
                {
                    x[i]-=qt;
                    time+=qt;
                }
                else
                {
                    time+=x[i];
                    x[i]=0;
                }
                finished=1;
            }

            if(x[i]==0 && finished==1)
            {
                ct[i]=time;
                tat[i]=time;
                wt[i]=tat[i]-bt[i];
            }
        }
    }


    printf("\t pid \t at \t bt \t ct \t tat \t wt");
    printf("\n-----------------------------------------------------------------");

    for(int i=0;i<n;i++)
    {
        printf("\n\t %d \t %d \t %d \t %d \t %d \t %d",i+1,0,bt[i],ct[i],tat[i],wt[i]);
    }

}
