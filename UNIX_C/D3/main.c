#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int fd[2];
	int k;
	pid_t pid;

	if(pipe(fd) < 0)
	{
		perror("pipe");
		return 1;
	}

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return 1;
	}
	else if(pid>0)
	{
		//PARENT
		close(fd[0]);
		while(scanf("%d", &k)  != EOF)
			write(fd[1], &k, sizeof(int));
		close(fd[1]);
		wait(NULL);
	}	
	else
	{	
		//CHILD
		pid = fork();
		if(pid<0)
		{
			perror("fork");
			return 1;
		}
		else if(pid>0)
		{
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
			exit(0);
		}
		else
		{
			//GRANDCHILD
			int count=0, max, min;
			close(fd[1]);
			while(read(fd[0], &k, sizeof(int))>0)
			{
				if(count==0)
					max = min = k;
				else{
					if(k<min)
						min = k;
					if(k>max)
						max = k;
				}
				count++;
			}
			close(fd[0]);
			printf("%d %d\n", min, max);
			exit(0);
		}
	}


	return 0;
}
