#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/msg.h>

struct msgbuf{
	long msgtype;
	char msg[256];
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid, ff;

/*	ff = open("file", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if(ff<0)
	{
		perror("file");
		return 1;
	}
*/
	key = ftok("msg.c", 'z');
	if(key<0)
	{
		perror("key");
		return 2;
	}
//	close(ff);

	msgid = msgget(key, IPC_CREAT | 0666);
	if(msgid<0)
	{
		perror("msgget");
		return 3;
	}
	
	for(;;)
	{
		msgrcv(msgid, &message, 256, 1, 0);
		if(strcmp(message.msg, "q") == 0)
			break;
		else
			printf("Process received: %s", message.msg);
	}
	return 0;
}

