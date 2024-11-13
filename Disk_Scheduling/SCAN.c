#include <stdio.h>
#include <stdlib.h>

int main()
{
    int head,n,disk_size,direction;

    printf("Enter head pointer : ");
    scanf("%d",&head);

    printf("Enter no. of elements in request queue : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter request queue elements :-\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    disk_size--;

    int ans=0;
    ans+=abs(disk_size-head);

    //find min;
    int val=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<val)
            val=arr[i];
    }
    ans+=abs(disk_size-val);
    printf("Seek Time : %d",ans);
}
