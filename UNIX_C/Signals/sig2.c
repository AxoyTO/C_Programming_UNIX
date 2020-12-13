#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

volatile int count = 0;
volatile int flag = 0;			
//volatile -> these variables shouldn't be optimized, because they may be changed at any moment.
// System V
// received SIGINT
// then SysV changes SIGINT to SIG_DFL by default
void SigHandler(int s)
{
	signal(SIGINT, SigHandler);
	signal(SIGTSTP, SigHandler);
	count++;
	if(s==SIGINT)
	{
		flag = 1;
		if(count==5)
			signal(SIGINT, SIG_DFL);
	}
	if(s==SIGTSTP)
	{
		if(count>3)
			signal(SIGINT, SIG_DFL);
	}
}

int main()
{
	signal(SIGINT, SigHandler);
	signal(SIGTSTP, SigHandler);
	kill(getpid(), SIGINT);
	raise(SIGINT);	//kill(getpid(), SIGINT) = raise(SIGINT) ---- process sends himself a signal
	while(1)
	{
		if (flag)
		{
			flag = 0;
			printf("I've received SIGINT %d time(s)\n", count);
		}
	}
	return 0;
}
	
