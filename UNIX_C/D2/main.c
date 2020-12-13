#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int i, n, count=1;
	pid_t pid;
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		pid = fork();
		if(pid<0)
		{
			perror("fork");
			return 1;
		}else if(pid==0)
		{
			if(count<n && count!=1)
				printf("%d ", i+1);
			else if(count==n && count!=1)
				printf("%d\n", count);
			else if(count==n && count==1)
				printf("\n");
		//	fflush(stdout);
			exit(0);
		}
		else
		{
			if(count==1)
			{
				printf("%d ", count);
				fflush(stdout);
			}
			count++;
			wait(NULL);
		}

	}
	return 0;
}
