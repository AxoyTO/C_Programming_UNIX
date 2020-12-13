#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd[2], semid, value, count=0, countMax, ff;
	key_t key;
	pid_t pid;
	struct sembuf P1 = {0, -1, 0};	//Semaphore #0
	struct sembuf V1 = {0, 1, 0};
	struct sembuf P2 = {1, -1, 0};	//Semaphore #1
	struct sembuf V2 = {1, 1, 0};
	struct sembuf P3 = {2, -1, 0};	//Semaphore #2
	struct sembuf V3 = {2, 1, 0};

	scanf("%d", &countMax);
	ff = open("file", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if(ff<0)
	{
		perror("open");
		return 1;
	}
	key = ftok("file", 1);
	if(key<0)
	{
		perror("key");
		return 2;
	}
	close(ff);

	semid = semget(key, 3, IPC_CREAT | 0666);
	if(semid<0)
	{
		perror("semget");
		return 3;
	}

	semctl(semid, 0, SETALL, 0);	//All semaphores = 0

	if(pipe(fd) < 0)
	{
		perror("pipe");
		return 4;
	}
	
	if((pid=fork()) < 0)
	{
		perror("fork");
		return 5;
	}
	else if(pid==0)
	{
		//CHILD #1
		while(count < countMax)
		{
		//	value = semctl(semid, 0, GETVAL, 0);
		//	printf("CHILD #1 Semaphore #0 Value = %d\n", value);
		//	value = semctl(semid, 1, GETVAL, 0);
		//	printf("CHILD #1 Semaphore #1 Value =%d\n", value);
		//	value = semctl(semid, 2, GETVAL, 0);
		//	printf("CHILD #1 Semaphore #2 Value =%d\n", value);
			
			semop(semid, &P2, 1);
			//semop(semid, &P3, 1);
			read(fd[0], &count, sizeof(int));
			if(count<=countMax)
			{
				printf("son1 %d\n", count++);
				fflush(stdout);
				write(fd[1], &count, sizeof(int));
				semop(semid, &V3, 1);		
			}
		}
		close(fd[0]);
		close(fd[1]);
		return 0;
	}
	else
	{
		//PARENT
		if((pid=fork())<0)
		{
			perror("fork");
			return 5;
		}
		else if(pid==0)
		{
			//CHILD #2
			while(count < countMax)
			{
			//	value = semctl(semid, 0, GETVAL, 0);
			//	printf("CHILD #2 Semaphore #0 Value =%d\n", value);
			//	value = semctl(semid, 1, GETVAL, 0);
			//	printf("CHILD #2 Semaphore #1 Value =%d\n", value);
			//	value = semctl(semid, 2, GETVAL, 0);
			//	printf("CHILD #2 Semaphore #2 Value =%d\n", value);
			
				semop(semid, &P3, 1);
				//	semop(semid, &P2, 1);
				read(fd[0], &count, sizeof(int));
				if(count<=countMax)
				{
					printf("son2 %d\n", count++);
					fflush(stdout);
					write(fd[1], &count, sizeof(int));
					semop(semid, &V1, 1);	
				}
			}
			close(fd[0]);
			close(fd[1]);
			return 0;
		}
		else
		{
			//PARENT
			write(fd[1], &count, sizeof(int));
			semop(semid, &V2, 1);
			while(count<countMax)
			{
			//	value = semctl(semid, 0, GETVAL, 0);
			//	printf("Parent Semaphore #0 Value =%d\n", value);
			//	value = semctl(semid, 1, GETVAL, 0);
			//	printf("Parent Semaphore #1 Value =%d\n", value);
			//	value = semctl(semid, 2, GETVAL, 0);
			//	printf("Parent Semaphore #2 Value =%d\n", value);
				semop(semid, &P1, 1);
				//	semop(semid, &P3, 1);
				read(fd[0], &count, sizeof(int));
				if(count<=countMax)
				{
					printf("father %d\n", count++);
					fflush(stdout);
					write(fd[1], &count, sizeof(int));
					semop(semid, &V2, 1);
				}
			}
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
			wait(NULL);
		}

		semctl(semid, 0, IPC_RMID, 0);
		return 0;
	}
}	
