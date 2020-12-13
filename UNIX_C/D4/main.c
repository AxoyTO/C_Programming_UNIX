#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//program1 arg1 arg2 | program2
//ls -l -a | wc

int main(int argc, char *argv[])
{
	int fd[2];
	pid_t pid1, pid2;

	if(argc<5)
	{
		printf("./program1 arg1 arg2 arg3 arg4\n");
		return 4;
	}
	if(pipe(fd) < 0)
	{
		perror("pipe");
		return 1;
	}
	pid1 = fork();
	if(pid1 < 0)
	{
		perror("fork1");
		return 2;
	}
	else if(pid1 == 0)
	{
		//1ST SON
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp(argv[1], argv[1], argv[2], argv[3], NULL);
		fprintf(stderr, "Can't run %s\n", argv[1]);
		return 3;
	}	
	pid2 = fork();
	if(pid2 < 0)
	{
		perror("fork2");
		return 2;
	}
	else if(pid2 == 0)
	{
		//2ND SON
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execlp(argv[4], argv[4], NULL);
		fprintf(stderr, "Can't run %s\n", argv[4]);
		return 3;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return 0;
}
