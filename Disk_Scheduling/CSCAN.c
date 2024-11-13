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

    int disk_size;
    printf("Enter disk size : ");
    scanf("%d",&disk_size);

    disk_size--;

    int ans=0;

    ans+=abs(disk_size-head);

    ans+=disk_size;

    //find max between 0 and head
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max && arr[i]<head)
            max=arr[i];
    }

    ans+=max;


    printf("\n\nSeek time : %d",ans);

}
