#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX 256

int main()
{
	key_t key;
	int shmid, semid;
	char str[MAX];
	char *shmaddr;
	struct sembuf V = {0,1,0};

	key = ftok("shm.c", 'k');
	if(key<0)
	{
		perror("key");
		return 1;
	}

	semid = semget(key, 1, IPC_CREAT | 0666);
	if(semid<0)
	{
		perror("semget");
		return 404;
	}
	shmid = shmget(key, MAX, IPC_CREAT | 0666);	//created shared memory of 256 bytes
	if(shmid<0)
	{
		perror("shmget");
		return 2;
	}
	
	semctl(semid, 0, SETVAL, 0);
	
	shmaddr = shmat(shmid, NULL, 0);	//connected to the shared memory
	if(shmaddr == (void*)-1)
	{
		perror("shmat");
		return 3;
	}

	fgets(str, 255, stdin);
	strcpy(shmaddr, str);		// wrote str to the shared memory shmaddr
	
	semop(semid, &V, 1);

	shmdt(shmaddr);			// disconnected from the shared memory
	shmctl(shmid, IPC_RMID, NULL);	// delete the shared memory
	semctl(semid, 0, IPC_RMID, NULL);

	return 0;
}

