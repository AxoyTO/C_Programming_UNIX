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
//	struct sembuf V = {0,1,0};
	struct sembuf P = {0,-1,0};
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

	shmid = shmget(key, MAX, IPC_CREAT | 0666);	//creating or using(if already created) the shared memory
	if(shmid < 0)
	{
		perror("shmget");
		return 2;
	}

	//semctl(semid, 0, SETVAL, 0);
	
	shmaddr = shmat(shmid, NULL, 0);	//adding the shared memory to our process
	if(shmaddr == (void*)-1)
	{
		perror("shmat");
		return 3;
	}

	semop(semid, &P, 1);
	strcpy(str, shmaddr);		// read from the shared mem
	printf("%s\n", str);
	shmdt(shmaddr);			// disconnect from the shm	
	
	return 0;
}
