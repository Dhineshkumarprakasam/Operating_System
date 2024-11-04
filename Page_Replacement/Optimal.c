#include <stdio.h>
#include <limits.h>

int isin(int queue[],int rear,int element)
{
    for(int i=0;i<=rear;i++)
        if(queue[i]==element)
            return 1;
    return 0;
}

void display(int queue[],int rear)
{
    for(int i=0;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
int main()
{

    int n=20;
    int frame=3;
    int rs[]={6,1,1,2,0,3,4,6,0,2,1,2,1,2,0,3,2,1,2,0};

    int queue[frame],rear=-1,next[frame],hm[n];

    for(int i=0;i<n;i++)
    {
        if(rear==-1)
        {
            queue[++rear]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);

        }
        else if(isin(queue,rear,rs[i])==1)
        {
            hm[i]=1;
            printf("Hit  : ");
            display(queue,rear);
        }

        else if(rear<frame-1)
        {
            queue[++rear]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);
        }

        else
        {
            int max=0;
            for(int j=0;j<frame;j++)
            {
                int found=0;
                for(int k=i+1;k<n;k++)
                {
                    if(queue[j]==rs[k])
                    {
                        next[j]=k;
                        found=1;
                        break;
                    }
                }

                if(found==0)
                    next[j]=INT_MAX;
            }

            for(int j=1;j<frame;j++)
            {
                if(next[j]>=next[max])
                    max=j;
            }
            queue[max]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);
        }
    }

    int miss=0,hit=0;
    for(int i=0;i<n;i++)
    {
        if(hm[i]==1)
            hit++;
        else
            miss++;
    }

    printf("\nMiss : %d",miss);
    printf("\nHit  : %d",hit);

}
