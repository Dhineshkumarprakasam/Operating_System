#include <stdio.h>

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

    for(int i=0;i<n;i++)
    {
        if(i==0)
            ans+=abs(head-arr[i]);

        else
            ans+=abs(arr[i-1]-arr[i]);
    }

    printf("\n\nSeek time : %d",ans);

}
