#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int fd[2];
	pid_t pid;
	pipe(fd);	//created a channel till fork

	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid>0)
	{
		//PARENT writes
		int k = 7;
		close(fd[0]);
		write(fd[1], &k, sizeof(int)); 	//fd[1] -> to write
		close(fd[1]);
		printf("PARENT WRITES k = %d\n", k);
	}
	else
	{
		//CHILD reads
		int n;
		close(fd[1]);			//fd[1] -> to write
		read(fd[0], &n, sizeof(int));	//fd[0] -> to read
		close(fd[0]);
		printf("SON READS n = %d\n", n);
	}
	return 0;
}
