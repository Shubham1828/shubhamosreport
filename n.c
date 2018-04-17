#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t a,b,c,d,e;
int x;
int h;
void *zoombie1();
void *zoombie2();
void *orphan1();
void *orphan2();

//======================================
void *orphan1()

{
    // Create a child process      
    int pid = fork();
 
    if (pid > 0)
        printf("in parent process");
 
    // Note that pid is 0 in child process
    // and negative if fork() fails
    else if (pid == 0)
    {
        sleep(3);
        printf("in child process");
    }
 
    return 0;
}


//===============================================

void *orphan2()
{
    // Create a child process      
    int pid = fork();
 
    if (pid > 0)
        printf("in parent process");
 
    // Note that pid is 0 in child process
    // and negative if fork() fails
    else if (pid == 0)
    {
        sleep(3);
        printf("in child process");
    }
 
    return 0;
}
//======================================================
void *zoombie1()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();

    // Parent process 
    if (child_pid > 0)
	{printf("in zombie");
        sleep(5);}

    // Child process
    else    
	 {   
        exit(0);}

    return 0;
}
//=======================================================
void *zoombie2()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();

    // Parent process 
    if (child_pid > 0)
	{printf("in zombie2");
        sleep(5);}

    // Child process
    else    
	 {   
        exit(0);}

    return 0;
}
//==========================================================


void *login()
{
 printf("\n1.zoombie1\n2. zoombie2\n3. orphan1\n4. orphan2 \n\nEnter Your category for login :: ");
scanf("%d",&x);

if(1<=x<=4){

if (x == 1 ) {

		printf("zoombie 1\n");
		pthread_create(&a,NULL,zoombie1,NULL);
		pthread_join(a,NULL);
	     }


else if(x==2){
		printf("\nzoombie2\n");
		pthread_create(&b,NULL,zoombie2,NULL);
		pthread_join(b,NULL);
              } 

if (x == 3){
		printf("orphan 1\n");
		pthread_create(&c,NULL,orphan1,NULL);
		pthread_join(c,NULL);
              }

if (x == 4){
		printf("orphan 2\n");
		pthread_create(&d,NULL,orphan2,NULL);
		pthread_join(d,NULL);
	    }


//else{
//pthread_exit(NULL);
//}
}
}
//======================================

void main()
{
for(int i=0;i<=3;i++)
{
printf("\nEnter which process to execute :: \n");
pthread_create(&e,NULL,login,NULL);
pthread_join(e,NULL);
}}

















