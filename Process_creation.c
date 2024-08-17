#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();
    
    //program to display 1 to 10
    printf("\nPrint 1 to 10 : ");
    for(int i=1; i<=10; i++)
        printf("%d ",i);
  
    //program to display 10 to 20
    printf("\nPrint 10 to 20 : ");
    for(int j=10; j<=20; j++)
        printf("%d ",j);
    printf("\n\n");
    
}
