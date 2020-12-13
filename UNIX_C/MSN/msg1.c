#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf
{
	long mtype;	//msg type
	long cnt;
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;
	key = ftok("msg1.c", 'a');
	if(key<0)
	{
		perror("key");
		return 1;
	}

	msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid < 0)
	{
		perror("msgget");
		return 2;
	}

	while(1)
	{
		msgrcv(msgid, &message, sizeof(long), 2, 0);
		printf("cnt = %ld mtype = %ld\n", message.cnt, message.mtype);
		if(message.cnt == -1)
			break;
		message.cnt++;
		message.mtype = 1;				//program1 sends message of type 1
		msgsnd(msgid, &message, sizeof(long), 0);	//sent message
	}

	msgctl(msgid, IPC_RMID, 0);		//delete the messenger
	return 0;
}
