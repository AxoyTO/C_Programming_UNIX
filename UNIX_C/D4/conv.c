#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int fd[2];
	pipe(fd);

	if(fork() == 0)
	{
		dup2(fd[1], 1);		// duplicated fd[1] to descryptor 1
		close(fd[0]);
		close(fd[1]);		// closed fd[1], but descryptors 0=stdin, 1=fd[1], 2=stderr still open
		execl("/bin/ls", "ls", "-l", NULL);
		fprintf(stderr, "error ls\n");
	}
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	execlp("wc", "wc", NULL);
	fprintf(stderr, "error wc\n");
	return 0;
}
