#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define CNT_MAX 10

struct msgbuf
{
	long mtype;
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
	if(msgid<0)
	{
		perror("msgget");
		return 2;
	}

	message.mtype = 2;		//program2 sends message of type 2
	message.cnt = 0;
	msgsnd(msgid, &message, sizeof(long), 0);	//sent message

	while(1)
	{
		msgrcv(msgid, &message, sizeof(long), 1, 0);	//receives message of type 1
		printf("cnt = %ld, mtype = %ld\n", message.cnt, message.mtype);
		if(message.cnt < CNT_MAX)
		{
			message.mtype = 2;				//program2 sends message of type 2
			message.cnt++;
			msgsnd(msgid, &message, sizeof(long), 0);	//sent message
		}
		else
		{
			message.mtype = 2;				//escape/break condition
			message.cnt = -1;				//when count == -1
			msgsnd(msgid, &message, sizeof(long), 0);	
			break;
		}
	}
	return 0;
}
