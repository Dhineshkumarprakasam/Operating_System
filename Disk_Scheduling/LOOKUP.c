#include <stdio.h>
#include <limits.h>

int main()
{
    int head,n;

    printf("Enter head pointer : ");
    scanf("%d",&head);

    printf("Enter no. of elements in request queue : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter request queue elements :-\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int ans=0;

    //find max
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    ans+=abs(max-head);

    //find min
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }

    ans+=abs(max-min);

    printf("\n\nSeek time : %d",ans);

}

