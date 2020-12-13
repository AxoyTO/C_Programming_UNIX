#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	char *argv[] = {"ls", "-l", NULL};

	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid==0)
	{
		//SON
		execl("/bin/ls", "ls", "-l", NULL);
		
//		execlp("ls", "ls", "-l", NULL);
//		execv("/bin/ls", argv);
//		execvp(char *file, char *argv[]);
//		execle(char *path, char *argv0, char *argv1, NULL, char *env0, char *env0,..., NULL);
//		execve(char *path, char *argv[], char *envp[]); 
		
		fprintf(stderr, "Can't start ls\n");
	}
	else
		wait(NULL);
	return 0;
}
