#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile int flag = 0;
void SigHandler(int s)
{
	signal(SIGUSR1, SigHandler);
	flag = 1;
}

int main()
{
	pid_t pid;
	int fd[2], count = 0, countMax;
	scanf("%d", &countMax);

	if(pipe(fd)<0)
	{
		perror("pipe");
		return 1;
	}
	
	signal(SIGUSR1, SigHandler);
	if((pid=fork()) < 0)
	{
		perror("fork");
		return 2;
	}
	else if(pid==0)
	{
		pid_t pid_f = getppid();	// we need pid of father to send him signals.
		while(count < countMax)
		{
			if(!flag)
				pause();
			flag = 0;
			read(fd[0], &count, sizeof(int));
			printf("son %d\n", count++);
			fflush(stdout);
			write(fd[1], &count, sizeof(int));
			kill(pid_f, SIGUSR1);	// kill(getppid(), SIGUSR1)
		}
		close(fd[0]);
		close(fd[1]);
		return 0;
	}
	else
	{
		write(fd[1], &count, sizeof(int));
		kill(pid, SIGUSR1);
		while(count < countMax)
		{
			if(!flag)
				pause();
			flag = 0;
			read(fd[0], &count, sizeof(int));
			printf("father %d\n", count++);
			fflush(stdout);
			write(fd[1], &count, sizeof(int));
			kill(pid, SIGUSR1);
		}
		close(fd[0]);
		close(fd[1]);
	}
	return 0;
}
