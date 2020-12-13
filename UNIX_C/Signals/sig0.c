#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	int count = 0;
	signal(SIGINT, SIG_IGN);	//sig_ignore -> ignore SIGINT -- ctrl+c can't break the program

	while(1)
	{
		count++;
		if(count>5)
			signal(SIGINT, SIG_DFL);	//sig_default -> return SIGINT to default -- SIGINT back to default
		else
		{
			signal(SIGINT, SIG_IGN);
			printf("count = %d\n", count);
			sleep(1);
		}
	}
	return 0;
}
