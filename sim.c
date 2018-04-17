
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
   int a;           
   pid_t p;         
   
   while(1)
     {
        printf("\n Enter the value of A =  ");
        scanf("%d", &a);
       
        if(a>0)         
          break;         
          
       else             
          {
             printf("\n The Number Cannot Be Negative ");
             continue;         
          }
      }
      
    p=fork();     // fork is used to create the child process 
      
    switch(p)
         {
            case -1 :  // Process Creation Failed
            
                       printf("\nProcess Creation Failed");
                       break;    
            case 0 :  // Child Process Executing
            
                       while(a>=1)
                         {
                            printf("%d\n", a);
                            a/=2;
                         }
                        break;
                       
            default : // Parent Process Executing
            
                      wait(NULL);  
           }
           
  return 0;
 }


