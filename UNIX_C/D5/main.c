#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd[2],fi,r,w;
	char buf[512];
	pid_t pid1, pid2;
	
	if(argc<5){		//ERROR
		fprintf(stderr, "Format: ./exe pr1 arg1 arg2 filename\n");
		return 1;
	}
	if(pipe(fd) < 0)	//ERROR
	{
		perror("pipe");
		return 1;
	}
	pid1 = fork();
	if(pid1<0)		//ERROR
	{
		perror("fork");
		return 1;
	}
	else if(pid1 == 0)
	{
		//1st SON
		dup2(fd[1], 1);			//stdout(1) is now fd[1]
		close(fd[0]);
		close(fd[1]);
		execlp(argv[1], argv[1], argv[2], argv[3], NULL);
		fprintf(stderr, "Can't run %s\n", argv[1]);
		return 1;
	}
	pid2 = fork();
	if(pid2<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid2==0)
	{
		//2nd SON
		dup2(fd[0], 0);			//stdin(0) is now fd[0]
		close(fd[0]);
		close(fd[1]);
		fi = open(argv[4], O_WRONLY | O_CREAT, 0644);
		if(fi == -1)
		{
			fprintf(stderr,"Can't open or create file %s\n", argv[4]);
			return 1;
		}
		while((r=read(0, buf, 512)) > 0)
			w = write(fi, buf, r);
		return 0;
	}
	close(fd[0]);
	close(fd[1]);
//	wait(NULL);
//	wait(NULL);
	return 0;
}
