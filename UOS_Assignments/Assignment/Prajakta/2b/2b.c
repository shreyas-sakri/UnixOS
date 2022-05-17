#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void inthandle(int sig)
{
	signal(SIGINT,inthandle);
	printf("SIGINT invoked by daughter\n");
}
void quithandle(int sig)
{
	signal(SIGQUIT,quithandle);
	printf("SIGQUIT invoked by son\n He killed me\n");
	exit(1);
}
void huphandle(int sig)
{
signal(SIGHUP,huphandle);
printf("SIGHUP invoked by child\n");
}
int main()
{
pid_t ppid,pid;
ppid=getpid();
if((pid=vfork())<0)
{
printf("Fork Failed!!!!\n");
exit(1);
}
else if(pid==0){
printf("In Child!!!!\n");
signal(SIGINT,inthandle);
signal(SIGHUP,huphandle);
signal(SIGQUIT, quithandle);
printf("Looping\n");
for(;;);
}
else
{
printf("In Parent!!!!\n");
printf("kill SIGHUP\n");
kill(pid,SIGHUP);
sleep(2);
printf("kill SIGINT\n");
kill(pid,SIGINT);
sleep(2);
printf("kill SIGQUIT\n");
kill(pid,SIGQUIT);
sleep(2);
//exit(0);
}
}
