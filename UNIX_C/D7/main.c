#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

volatile int count_SIGINT = 0;
volatile int flag = 0;
volatile int count_SIGQUIT = 0;
volatile int flagF = 0;

void SigHandler(int s)
{
	signal(SIGINT, SigHandler);
	signal(SIGQUIT, SigHandler);
	if(s==SIGINT)
	{
		count_SIGINT++;
		flag = 1;
		if(count_SIGINT>4)
		{
			flagF = 1;
		}
		if(count_SIGINT>=7)
		{
			signal(SIGINT, SIG_DFL);
			//printf("I've received SIGQUIT a total of %d time(s) between the 2nd and 4th times of receiving SIGINT.\n", count_SIGQUIT); 
		}
	}
	if(s==SIGQUIT)
	{
		if(count_SIGINT>=2 && count_SIGINT<=4)		//Влючено или не включено 2 и 4 нажатия?
		{
			count_SIGQUIT++;
		//	printf("I've received SIGQUIT %d time(s)!\n", count_SIGQUIT);
		}
		/*
		if(count_SIGINT>=7)				//Программа должна завершиться при любой SIGINT после 7го? Т.к. после 7 SIGINT если вводим SIGQUIT до SIGINT, программа входит в if(s==SIGQUIT)
			signal(SIGINT, SIG_DFL);		//а не в if(s==SIGINT), поэтому ожидает пока не введен только SIGINT
		*/
		
	}
}

int main()
{
	signal(SIGINT, SigHandler);
	signal(SIGQUIT, SigHandler);
	while(1)
	{
		if(flag && !flagF)
		{
			flag = 0;
			printf("I've received SIGINT %d time(s)!\n", count_SIGINT);
		}
		if(flag && flagF)
		{
			flag = 0;
			printf("I've received SIGINT %d time(s) and SIGQUIT %d time(s)!\n", count_SIGINT, count_SIGQUIT);
		}
	}
	return 0;
}
