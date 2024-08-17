#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t q;
    q=fork();
    
    if(q<0)
        printf("not created");
    else if(q==0)
    {
        
        printf("It is child process\n");
        printf("I am child with pid : %d\n",getpid());
        printf("My parent : %d\n",getppid());
        
    }
    
    else
        {
            sleep(3);
            printf("It is parent process\n");
            printf("I am parent with pid : %d\n",getpid());
            printf("My child : %d\n",q);
           
        }
    printf("\n");
}
