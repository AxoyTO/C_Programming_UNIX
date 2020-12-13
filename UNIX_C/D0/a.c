#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(0 == fork())
	{
		printf("%d",getppid());
	}
	return 0;
}
