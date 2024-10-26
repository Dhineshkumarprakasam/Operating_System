#include <stdio.h>

int isin(int queue[],int n,int element)
{
    for(int i=0;i<n;i++)
        if(queue[i]==element)
            return 1;
    return 0;
}

void display(int arr[],int n)
{
    for(int i=0;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}


int main()
{
    int n,frame;

    printf("Enter no. of Reference characters : ");
    scanf("%d",&n);

    printf("Enter no. of Frames : ");
    scanf("%d",&frame);

    int rs[n],queue[frame],rear=-1,hm[n];

    printf("Enter Reference String : ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);

    //0 for miss and 1 for hit
    for(int i=0;i<n;i++)
    {
        if(rear==-1)
        {
            queue[++rear]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);
        }
        else if(rear<frame-1)
        {
            if(isin(queue,frame,rs[i]))
            {
                hm[i]=1;
                printf("Hit  : ");
                display(queue,rear);
            }
            else
            {
                queue[++rear]=rs[i];
                hm[i]=0;
                printf("Miss : ");
                display(queue,rear);
            }
        }
        else
        {
            if(isin(queue,frame,rs[i]))
            {
                hm[i]=1;
                printf("Hit  : ");
                display(queue,rear);
            }
            else
            {
                for(int i=0;i<frame-1;i++)
                    queue[i]=queue[i+1];
                queue[frame-1]=rs[i];
                hm[i]=0;
                printf("Miss : ");
                display(queue,rear);
            }
        }
    }

    int hit=0,miss=0;
    for(int i=0;i<n;i++)
    {
        if(hm[i]==0)
            miss++;
        else
            hit++;
    }

    printf("\nHit  : %d\n",hit);
    printf("Miss : %d\n",miss);
}
