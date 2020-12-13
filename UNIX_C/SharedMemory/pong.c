#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main()
{
	int semid, shmid;
	key_t key;
	int flag = 1;
	struct sembuf V2 = {1, 1, 0};
	struct sembuf P1 = {0, -1, 0};
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

	semctl(semid, 1, SETVAL, 0);

	shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (void*)-1)
	{
		perror("shmat");
		return 4;
	}

	do
	{
		semop(semid, &P1, 1);
		if(shmaddr[0] == -1)
		{
			shmdt(shmaddr);
			break;
		}
		printf("process2: %d\n", shmaddr[0]++);
		semop(semid, &V2, 1);
	}while(1);

	return 0;
}
