#include<stdio.h>

#include<unistd.h>


int main(){

printf("Beginning\n");

int counter = 0;

int pid = fork();

if(pid==0)

{

for(int i=0;i<5;i++)

{

printf("Child process = %d\n",++counter);

}

printf("Child Ended\n");

}

else if(pid>0)

{

for(int i=0;i<5;i++)

{

printf("Parent process = %d\n",++counter);

}

printf("Parent Ended\n");

}

else

{

printf("fork() failed\n");

return 1;

}

return 0;

}
