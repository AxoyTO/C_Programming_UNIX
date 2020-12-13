#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

struct msgbuf{
	long msgtype;	//message type
	char msg[256];	
};

int main()
{

	struct msgbuf message;
	key_t key;
	int msgid, ff;
	char str[256];

/*	ff = open("file", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if(ff<0)
	{
		perror("file");
		return 1;
	}
*/	key = ftok("msg.c", 'z');
	if(key < 0)
	{
		perror("key");
		return 2;
	}
//	close(ff);
	msgid = msgget(key, IPC_CREAT | 0666);		//created or connected to the messenger
	if(msgid < 0)
	{
		perror("msgget");
		return 3;
	}
	while(1)
	{
		fgets(str, 255, stdin);
		strcpy(message.msg, str);
		switch(str[0])
		{
			case 'a':
			case 'A':
				message.msgtype = 1;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				break;
			case 'b':
			case 'B':
				message.msgtype = 2;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				break;
			case 'q':
			case 'Q':
				strcpy(message.msg, "q");
				message.msgtype = 1;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				message.msgtype = 2;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				msgctl(msgid, IPC_RMID, 0);	//remove the messenger
				return 0;
			default:
				break;
		}
	}
}
