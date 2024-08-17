#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int ans=0;
int addNumber(int n)
{
    //program to add n for 1000 times
    for(int i=1;i<=1000;i++)
        ans+=n;
    return ans;
}

int main()
{
    pid_t p = fork();
    
    if(p<0)
        printf("\nProcess not created : \n");
       
    else if(p>0)
    {
        printf("\nParent Process with id : %d\n",getpid());
        printf("Ans : %d\n",addNumber(1));
    }
    
    else
    {
        printf("\nChild Process with id : %d\n",getpid());
        printf("Ans : %d\n",addNumber(2));
    }
}
