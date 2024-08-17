#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p = fork();
    
    if(p<0)
        printf("Failed\n");
        
    else if(p==0)
    {
        sleep(5);
        printf("\nI am Child with pid : %d\n",getpid());
        printf("My parent pid : %d\n",getppid());
    }
    
    else
    {
        printf("\nI am Parent with pid : %d\n",getpid());
        printf("My child pid : %d\n",p);
    }
}
