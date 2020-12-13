#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	int fd[2], semid, count=0, countMax, ff;
	struct sembuf P1 = {0, -1, 0};	//нулевой семафор
	struct sembuf V1 = {0, 1, 0};
	struct sembuf P2 = {1, -1, 0};	//первый семафор
	struct sembuf V2 = {1, 1, 0};
	key_t key;
	pid_t pid;

	scanf("%d", &countMax);
	ff = creat("file", 0666);
	if(ff<0)
	{
		perror("file");
		return 5;
	}

	key = ftok("file", 'd');
	if(key<0)
	{
		perror("key");
		return 1;
	}
	close(ff);

	semid = semget(key, 2, IPC_CREAT | 0666);	//created 2 semaphores
	if(semid<0)
	{
		perror("semget");
		return 2;
	}

	semctl(semid, 0, SETVAL, 0);	//0th sem = 0
	semctl(semid, 1, SETVAL, 0);	//1st sem = 0
//	semctl(semid, 0, SETALL, 0);	//all sem = 0

	if(pipe(fd) < 0)
	{
		perror("pipe");
		return 3;
	}

	if((pid=fork()) < 0)
	{
		perror("fork");
		return 4;
	}
	else if(pid>0)	//father
	{
		write(fd[1], &count, sizeof(int));	// 0 -> pipe
		semop(semid, &V1, 1);			// 0thSem sem.val = 0+1=1
		while(count < countMax)
		{
			semop(semid, &P2, 1);
			read(fd[0], &count, sizeof(int));
			printf("father %d\n", count++);
			fflush(stdout);
			write(fd[1], &count, sizeof(int));
			semop(semid, &V1, 1);
		}
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	else	//son
	{
		while(count < countMax)		//		
		{
			semop(semid, &P1, 1);	//0thSem sem.val = 0 -1 < 0 blocking
			read(fd[0], &count, sizeof(int));//count = 0 <- pipe
			printf("son %d\n", count++);	//
			fflush(stdout);
			write(fd[1], &count, sizeof(int));
			semop(semid, &V2, 1);
		}
		close(fd[0]);
		close(fd[1]);
		return 0;
	}

	semctl(semid, 0, IPC_RMID, 0);	//delete sem
	return 0;
}
