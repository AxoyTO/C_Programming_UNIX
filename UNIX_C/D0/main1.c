#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int var = 5;
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
	//pid<0 ------- ERROR
		perror("fork");
		return 1;
	}
	else if(pid==0)
	{
	//pid==0 ------ SON
		printf("var=%d PID=%d PPID=%d\n", var, getpid(), getppid());
	}
	else
	{
	//pid>0 ------- PARENT
		printf("PID SON=%d, PID=%d PPID=%d\n", pid,getpid(), getppid());
		wait(NULL);
	}

	return 0;
}
