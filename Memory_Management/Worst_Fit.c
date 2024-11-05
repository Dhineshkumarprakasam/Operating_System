#include <stdio.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n=6;
    int not[n],idx=-1;

    int part[]={350,650,400,250,750,225};
    int process[]={200,425,545,275,660};

    for(int i=0;i<n;i++)
    {
        //find max
        int max=0;
        for(int j=0;j<n;j++)
        {
            if(part[j]>part[max])
                max=j;
        }

        if(part[max]>=process[i])
        {
            part[max]=(part[max]-process[i]);
            printf("Free : ");
            display(part,n);
        }

        else
            not[++idx]=process[i];
    }

    if(idx>=0)
    {
        printf("\nCannot be allocated :-\n");
        for(int i=0;i<=idx;i++)
        {
            printf("%dkb ",not[i]);
        }
        printf("\n\n");
    }

    int free=0;
    for(int i=0;i<n;i++)
        free+=part[i];
    printf("Total free space after allocation :  %d\n",free);
}
