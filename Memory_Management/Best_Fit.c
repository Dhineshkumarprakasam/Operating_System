#include <stdio.h>

int findidx(int arr[], int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(element==arr[i])
            return i;
    }
    return -1;
}

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%dkb ",arr[i]);
    printf("\n");
}

int main()
{

    int n=6;
    int not[n],idx=-1;

    int part[]={350,650,400,250,750,225};
    int process[]={200,425,545,275,660};
    int dup[]={350,650,400,250,750,225};

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dup[i]>dup[j])
            {
                int temp=dup[i];
                dup[i]=dup[j];
                dup[j]=temp;
            }
        }
    }

    for(int i=0;i<n-1;i++)
    {
        int found=0;
        for(int j=0;j<n;j++)
        {
            if(dup[j]>=process[i])
            {
                int index = findidx(part,n,dup[j]);
                part[index]=(part[index]-process[i]);
                dup[j]=(dup[j]-process[i]);
                found=1;
                display(part,n);
                break;
            }
        }

        if(found==0)
            not[++idx]=process[i];
    }

    if(idx>=0)
    {
        printf("Cannot be allocated :-\n");
        for(int i=0;i<=idx;i++)
            printf("%dkb ",not[i]);
        printf("\n\n");
    }

    int free=0;
    for(int i=0;i<n;i++)
        free+=part[i];
    printf("Total free space after allocation :  %d\n",free);
}
