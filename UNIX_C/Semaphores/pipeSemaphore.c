#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
	pid_t pid;
	int fd[2], semid;
	struct sembuf P = {0,-1,0};	//sem.op = -1;
	struct sembuf V = {0,1,0};	//sem.op = 1;
	key_t key = ftok("pipeSemaphore.c", 'n');
	if(key<0)
	{
		perror("key");
		return 1;
	}

	semid = semget(key, 1, IPC_CREAT | 0666);	//we created 1 semaphore.
	semctl(semid, 0, SETVAL, (int)0);	//initial value of semaphore = 0
						//sem.val = 0

	if(pipe(fd)<0)
	{
		perror("pipe");
		return 1;
	}
	pid = fork();
	if(pid<0)
	{
		perror("fork");
		return 1;
	}
	else if(pid==0)
	{
		int var = 5, var2;
		printf("son sends var = %d\n", var);
		write(fd[1], &var, sizeof(int));
		semop(semid, &P, 1);	//sem.val = sem.val + sem.op ? 0 ------- 0-1=-1 < 0 ---> process will be blocked.
		read(fd[0], &var2, sizeof(int));
		printf("son received var2 = %d\n", var2);
		close(fd[0]);
		close(fd[1]);
		return 0;
	}
	else
	{
		int n, k=3;
		read(fd[0], &n, sizeof(int));
		printf("father received n = %d\n", n);
		write(fd[1], &k, sizeof(int));
		printf("father sends k = %d\n", k);
		semop(semid, &V, 1);	//sem.val = sem.val + sem.op; ----- sem.val = 0+1 = 1
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	semctl(semid, 0, IPC_RMID, 0);	// deleting(closing) the semaphores.
	return 0;
}
