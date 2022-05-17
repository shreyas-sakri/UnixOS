#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main()
{
pid_t id=fork();
if(id==0)
{
      printf("Child Process Started..ProcessID = %d\n", getpid());
      printf("In Child\n");
      for(int i=0;i<5;i++)
      {
	printf("In Child : %d\n",i);
      }
      printf("Child Finished\n");
     exit(0);
}
else
{
     printf("Parent Process Started..ProcessID = %d\n", getpid());
     printf("In Parent\n");
     printf("Parent waiting\n");
     wait(NULL);
     printf("Parent Resumed\n");
     for(int i=0;i<5;i++)
     {
              printf("In parent : %d\n",i);
     }
      printf("Parent Finished\n");
}
}

