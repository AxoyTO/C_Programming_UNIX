#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <fcntl.h>

struct msgbuf{
	long msgtype;
	char msg[256];
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid, semid;
	struct sembuf V = {0, 1, 0};
	struct sembuf P = {0, -1, 0};
	char str[256];

	key = ftok("p1.c", 'k');
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

	semctl(semid, 0, SETVAL, 0);
	msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid<0)
	{
		perror("msgget");
		return 2;
	}

//	int val;

	while(1)
	{
		printf("Send a message: ");
		fgets(str, 255, stdin);
		strcpy(message.msg, str);
		message.msgtype = 2;
		msgsnd(msgid, &message, strlen(str)+1, 0);
		printf("P1 wrote: %s", message.msg);
		//printf("strcmp = %d", strcmp(message.msg, "q\n"));
		if(!strcmp(message.msg, "q\n"))
		{
			printf("Sent \"q\" to P2. Quitting!\n");
			break;
		}
//		semop(semid, &V, 1);
//		val = semctl(semid, 0, GETVAL, 0);
//		printf("val=%d\n", val);
		msgrcv(msgid, &message, 256, 1, 0);
		if(!strcmp(message.msg, "q\n"))
		{
			printf("Received \"q\" from P2. Deleting the message queue and quitting!\n");
			msgctl(msgid, IPC_RMID, 0);
			break;
		}
		else
			//printf("P1 received: %s", message.msg);
			printf("P2 wrote: %s", message.msg);
	}
	return 0;
}
