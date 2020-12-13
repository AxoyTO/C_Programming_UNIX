#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define CNT_MAX 10

int main()
{
	int semid, shmid;
	key_t key;
	int flag = 1;
	struct sembuf P2 = {1, -1, 0};
	struct sembuf V1 = {0, 1, 0};
	int *shmaddr;

	key = ftok("ping.c", 'a');
	if(key<0)
	{
		perror("ftok");
		return 1;
	}

	shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	if(shmid < 0)
	{
		perror("shmget");
		return 2;
	}

	semid = semget(key, 2, IPC_CREAT | 0666);
	if(semid < 0)
	{
		perror("semget");
		return 3;
	}

	semctl(semid, 0, SETVAL, 0);
	shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (void*)-1)
	{
		perror("shmat");
		return 4;
	}

	shmaddr[0] = 0;
	semop(semid, &V1, 1);

	do
	{
		semop(semid, &P2, 1);
		if(shmaddr[0] < CNT_MAX)
			printf("process 1: %d\n", shmaddr[0]++);
		else
		{
			shmaddr[0] = -1;
			flag = 0;
		}
		semop(semid,  &V1, 1);
	}while(flag);

	shmdt(shmaddr);

	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID, NULL);
	return 0;
}
