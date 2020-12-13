#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile int flag = 0;

void SigHandler(int s)
{
    signal(SIGUSR1, SigHandler);
    flag = 1;
}

int main()
{
    pid_t pid;
    //pid_t pidFather = getpid();
    int fd[2];
    int count=0, countMax, queue=0;
   
    scanf("%d",&countMax);

    signal(SIGUSR1, SigHandler);
    if(pipe(fd) < 0)
    {
        perror("pipe\n");
        return 1;
    }

    if((pid=fork()) < 0)
    {
        perror("fork\n");
        return 2;
    }
    else if(pid == 0)
    {
        //SON
        pid = fork();
        if(pid<0)
        {
            perror("fork\n");
            return 3;
        }
        else if(pid == 0)
        {
            //GRANDSON
            while(count < countMax)
            {
                if(!flag)
                {
                    pause();
                }
                flag = 0;
                read(fd[0], &count, sizeof(int));
		if(count<=countMax)
		{
                	printf("grandson %d\n", count++);
                	fflush(stdout);
               		write(fd[1], &count, sizeof(int));
			kill(getppid(), SIGUSR1);
		}
            }
            close(fd[0]);
            close(fd[1]);
            return 0;
        }
        else
        {
            //SON
            flag = 0;
            kill(pid, SIGUSR1);
            while(count < countMax)
            {
                if(!flag)
                {
                    pause();
                }
                flag = 0;
                read(fd[0], &count, sizeof(int));
		if(count<=countMax)
		{
                	printf("son %d\n", count++);
		//	printf("queue = %d\n", queue);
                	fflush(stdout);
              		write(fd[1], &count, sizeof(int));
			/* иногда внук и отец попадают в race condition не смотря на то, кто стоит на queue(очереди), хотя сын вызывает kill по queue, как они могут сами по себе войти в race condition?
			 * при вводе 4k(k>=1 и натуральное число) должен писать внук, но иногда отец выигрывает этот race condition
			 * хотя бы так в моей системе */
                	if(!queue)
                	{
                    	        kill(getppid(), SIGUSR1);
                    		queue = 1;
                	}
                	else if(queue)
           		{
	                	kill(pid, SIGUSR1);
	                	queue = 0;
        	        }
		}
            }
	    kill(getppid(), SIGUSR1);
            close(fd[0]);
            close(fd[1]);
            return 0;
        }
    }
    else
    {
        //FATHER
	write(fd[1], &count, sizeof(int));
        kill(pid,SIGUSR1);
        fflush(stdout);
        while(count < countMax)
        {
            if(!flag)
            {
                pause();
            }
            flag = 0;
            read(fd[0], &count, sizeof(int));
	    if(count<=countMax)
	    {
           	printf("father %d\n", count++);
           	fflush(stdout);
            	write(fd[1], &count, sizeof(int));
                kill(pid, SIGUSR1);
	    }
        }
        close(fd[0]);
	close(fd[1]);
        return 0;
    }
}
