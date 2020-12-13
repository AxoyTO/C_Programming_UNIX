#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
	pid_t pid;
	int status;

	if((pid=fork()) < 0){	perror("fork");	return 1;}
	else if(pid==0)
	{
		execlp("lsi", "ls", "-l", NULL);
		perror("execlp");
		return 404;
	}
	else
	{
//		kill(pid, SIGINT);
		wait(&status);

		if(WIFEXITED(status))
			printf("child process exited normally with code %d\n", WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
			printf("child process exited with signal %d\n", WTERMSIG(status));
		else
			printf("child process exited abnormally\n");
		return 0;
	}
}

