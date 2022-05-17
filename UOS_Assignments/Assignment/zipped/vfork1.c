#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
pid_t p = vfork();
if(p < 0)
{
printf("vfork() failed\n");
}
else if(p == 0)
{printf("In Child Process Started with pid = %d\n",getpid());
for(int i=1;i<=5;i++){
printf("In Child : %d\n",i);
}
printf("Child Finished\n");
exit(0);
}
else
{
printf("Parent Process Starded with pid = %d\n",getpid());
for(int i=1;i<=5;i++)
{
printf("In Parent : %d\n",i);
}
printf("Parent Finished\n");
}
}
