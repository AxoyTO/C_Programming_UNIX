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
	struct sembuf sops;
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

	semid = semget(key, 1, IPC_CREAT | 0666);
	if(semid < 0)
	{
		perror("semget");
		return 3;
	}

	shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr == (void*)-1)
	{
		perror("shmat");
		return 4;
	}

	sops.sem_num = 0;
	sops.sem_flg = SEM_UNDO;

	do
	{
		sops.sem_op = -1;
		semop(semid, &sops, 1);
		if(shmaddr[0] == -1)
		{
			shmdt(shmaddr);
			break;
		}
		printf("process2: %d\n", shmaddr[0]++);
		sops.sem_op = -1;
		semop(semid, &sops, 1);
	}while(1);

	return 0;
}
