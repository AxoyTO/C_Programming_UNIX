#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile int flag = 0;

void SigHandler(int s)
{
	flag = 1;
}	

int main()
{
	int fd[2];
	pid_t pid;
	signal(SIGUSR1, SigHandler);
	if (pipe(fd)<0)
	{
		perror("pipe");
		return 1;
	}
	
	pid=fork();
	if(pid<0)
	{
		perror("fork");
		return 2;
	}

	if(pid == 0)
	{
		int var = 5, var2;
		printf("Son send var = %d\n", var);
		write(fd[1], &var, sizeof(int));
		if(!flag)
			pause();
		read(fd[0], &var2, sizeof(int));
		printf("Son received var2 = %d\n", var2);
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		int n,k = 3;
		read(fd[0], &n, sizeof(int));
		printf("Father received n = %d\n", n);	//n = 5
		write(fd[1], &k, sizeof(int));
		printf("Father send k = %d\n", k);	//k = 3
		kill(pid, SIGUSR1);	// sends signal to pid = son
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}
