#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
	int fd[2];
	int fd2[2];
	pid_t pid1, pid2, pid3;
	
	if(argc<7){
		fprintf(stderr,"Format: ./exe pr1 arg1 arg2 pr2 arg3 pr3\n");
		return 1;
	}

	if(pipe(fd)<0)
	{
		perror("pipe");
		return 1;
	}

	pid1 = fork();
	if(pid1<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid1==0)
	{
		//SON
		if(pipe(fd2)<0)
		{
			perror("pipe 2");
			return 1;
		}
		pid2 = fork();
		if(pid2<0)
		{
			perror("fork 2");
			return 1;
		}
		else if(pid2==0)
		{
			//GRANDSON
			pid3 = fork();
			if(pid3<0)
			{
				perror("fork 3");
				return 1;
			}
			else if(pid3 == 0)
			{
				printf("Son v3\n");
				//GRANDGRANDSON -> Son v3
				dup2(fd[1],1);
				close(fd[0]);
				close(fd[1]);
			close(fd2[0]);
				close(fd2[1]);
				execlp(argv[1], argv[1], argv[2], argv[3], NULL);
				fprintf(stderr,"Can't run %s\n", argv[1]);
				return 1;
			}
			else
			{
				printf("Son v2\n");
				//GRANDSON -> Son v2
				dup2(fd[0], 0);
				dup2(fd2[1], 1);
				close(fd[0]);
				close(fd[1]);
				close(fd2[0]);
				close(fd2[1]);
				execlp(argv[4], argv[4], argv[5], NULL);
				fprintf(stderr, "Can't run %s\n", argv[4]);
				return 1;
			}
		}
		else
		{
			//SON
			printf("Son v1\n");
			dup2(fd2[0],0);
			close(fd[0]);
			close(fd[1]);
			close(fd2[0]);
			close(fd2[1]);
			execlp(argv[6],argv[6], NULL);
			fprintf(stderr, "Can't run %s\n", argv[6]);		
			return 1;
		}
	}
	else
	{
		//PARENT
		wait(NULL);
		printf("Father\n");
		close(fd[0]);
		close(fd[1]);
		}	
	return 0;
}
