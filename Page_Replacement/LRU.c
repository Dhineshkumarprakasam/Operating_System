#include <stdio.h>
#include <limits.h>

int isin(int arr[],int n,int element)
{

    for(int i=0;i<=n;i++)
        if(arr[i]==element)
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
    int n;
    printf("Enter n : ");
    scanf("%d",&n);

    int rs[n],hm[n],queue[3],indexes[3],idx=-1,rear=-1;

    printf("Enter rs : ");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);

    for(int i=0;i<n;i++)
    {

        int exist = isin(queue,rear,rs[i]);

        if(exist==0 && rear<=1)
        {
            queue[++rear]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);
        }
        else if(exist==1)
        {
            hm[i]=1;
            printf("Hit  : ");
            display(queue,rear);
        }

        else
        {
            for(int j=0;j<3;j++)
            {
                int found=0;
                for(int k=i;k>0;k--)
                {
                    if(rs[k]==queue[j])
                    {
                        indexes[j]=k;
                        found=1;
                        break;
                    }
                }

                if(found==0)
                    indexes[j]=-1;
            }

            int min=0;
            for(int j=0;j<3;j++)
                if(indexes[j]<indexes[min])
                    min=j;

            queue[min]=rs[i];
            hm[i]=0;
            printf("Miss : ");
            display(queue,rear);
        }
    }

    int hit=0,miss=0;
    for(int i=0;i<n;i++)
    {
        if(hm[i]==1)
            hit++;
        else
            miss++;
    }

    float hratio=(float)hit/n;
    float mratio=(float)miss/n;

    printf("No of hit  : %d\n",hit);
    printf("No of miss : %d\n",miss);
    printf("Hit ratio  : %f\n",hratio);
    printf("Miss ratio : %f\n",mratio);
}
