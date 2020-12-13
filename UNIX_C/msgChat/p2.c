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
	struct sembuf P = {0, -1, 0};
	struct sembuf V = {0, 1, 0};
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

/*	while(1)
	{
		fgets(str, 255, stdin);
		strcpy(message.msg, str);
		message.msgtype = 1;
//		semop(semid, &P, 1);
//		val = semctl(semid, 0, GETVAL, 0);
//		printf("val=%d\n", val);
		msgsnd(msgid, &message, strlen(str)+1, 0);
		printf("You wrote: %s", message.msg);
		if(strcmp(message.msg, "q") == 0)
			break;
		msgrcv(msgid, &message, 256, 2, 0);
		if(strcmp(message.msg, "q") == 0)
		{
			msgctl(msgid, IPC_RMID, 0);
			break;
		}
		else
			printf("You received: %s\n", message.msg);
	}
*/
	while(1)
	{
		msgrcv(msgid, &message, 256, 2, 0);
		if(!strcmp(message.msg, "q\n"))
		{
			printf("Received \"q\" from P1. Deleting the message queue and quitting!\n");	
			msgctl(msgid, IPC_RMID, 0);
			break;
		}
		else
			//printf("P2 received: %s", message.msg);
			printf("P1 wrote: %s", message.msg);
		printf("Send a message: ");	
		fgets(str, 255, stdin);
		strcpy(message.msg, str);
		message.msgtype = 1;
		msgsnd(msgid, &message, strlen(str)+1, 0);
		printf("P2 wrote: %s", message.msg);
		if(!strcmp(message.msg, "q\n"))
		{
			printf("Sent \"q\" to P1. Quitting!\n");
			break;
		}
	}
	return 0;
}
