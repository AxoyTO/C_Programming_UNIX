#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

int count = 0;
char *str = "I've received SIGINT\n";

void SigHandler(int s)
{
	int save_errno = errno;
	signal(SIGINT, SigHandler);
//	printf("I received SIGINT %d times(s)\n", count++);	//using printf in such low-level program is bad because of buffering
	write(1, str, 21);	// error errno = another error code
	count++;
	if(count==5)
		signal(SIGINT, SIG_DFL);
	errno = save_errno;
}

int main()
{
	signal(SIGINT, SigHandler); 
//	printf(" ");
//	char c = 'r';
//	if(write(1, &c, 1) == -1) // error	errno = error code
//	received signal, errno is a global variable, we might get the wrong errno(from the function)
//	{
//		if(errno == EACES)
//	}
	while(1);
	return 0;
}
