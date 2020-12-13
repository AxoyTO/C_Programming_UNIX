// PARENT READS THE NUMBERS FROM STDIN AND SENDS THEM TO THE CHILD
// CHILD READS THEM FROM THE PARENT AND FINDS THE SUM AND PARENTS
// PARENT 1 2 3 4 5 6 7
// SON 1+2+3+4+5+6+7 = 28

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) < 0)	//created a channel till fork
	{
		perror("pipe");
		return 1;
	}

	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid>0)
	{
		//PARENT	
		int k;
		close (fd[0]);
		while(scanf("%d", &k) != EOF)
			write(fd[1], &k, sizeof(int)); 	//fd[1] -> to write
		close(fd[1]);
		wait(NULL);		//in wait() always: parent waits for his child
	}
	else
	{
		//CHILD
		int n, sum=0;
		close(fd[1]);					//fd[1] -> to write
		while(read(fd[0], &n, sizeof(int)) > 0)		//fd[0] -> to read
		{
			sum +=n;
		}
		close(fd[0]);
		printf("%d\n", sum);
	}
	return 0;
}
