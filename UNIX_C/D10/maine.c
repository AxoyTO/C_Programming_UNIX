#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
struct msgbuf{
    long mtype;
    char data[256];
    long Cnt_Max;
};
int main(int argc,char*argv[]){
    int f_ctrl;
    pid_t pid1,pid2,pid3;
    key_t key;
    int msgid;
    struct msgbuf message;

    f_ctrl=creat("f_ctrl",0666);
    if(f_ctrl<0){ perror("creat");
        return 5;
    }
    close(f_ctrl);
    key=ftok("f_ctrl",'h');
    if (key<0){perror("key");
        return 1;
    }
    msgid=msgget(key,IPC_CREAT | 0666);
    if(msgid<0){perror("msgget");
        return 2;
    }
    pid1=fork();
    if((pid1=fork())<0){perror("fork");
        return 1;
    }
    else if(pid1>0){
        if((pid2=fork())<0){perror("fork");
            return 1;
        }else if(pid2>0){
            pid3=fork();
            if(pid3<0){perror("fork"); return 6;
            }else if(pid3==0){
                //son3
                char msgS3[256];
                char sonbuf3[2];
                sonbuf3[0]='A';
                sonbuf3[1]='\0';
                while(1==1){
                    msgrcv(msgid,&message,sizeof(message),3,0);
                    strcpy(msgS3,message.data);
                    if(strlen(msgS3)==message.Cnt_Max){
                        message.mtype =4;
                        msgsnd(msgid,&message,sizeof(message),0);
                        exit(0);
                    }
                    message.mtype =4;
                    strcat(msgS3,sonbuf3);
                    strcpy(message.data,msgS3);

                    if(sonbuf3[0]=='Z')
                        sonbuf3[0]='A';
                    else
                        sonbuf3[0]++;
                    msgsnd(msgid,&message,sizeof(message),0);
                    if(strlen(msgS3)==message.Cnt_Max){
                        message.mtype =5;
                        msgsnd(msgid,&message,sizeof(message),0);
                        exit(0);
                    }
                }
                return 0;
            }else{
                //father
                scanf("%ld",&message.Cnt_Max);
                message.mtype =1;
                message.data[0] ='\0';
                msgsnd(msgid,&message,sizeof(message),0);
                msgrcv(msgid,&message,sizeof(message),5,0);
                printf("%s\n",message.data);
                wait(NULL);
                wait(NULL);
                wait(NULL);
                msgctl(msgid,IPC_RMID,0);
                return 0;
            }
        }else{
            //son 2
            char msgS2[256];
            char sonbuf2[2];
            sonbuf2[0]='0';
            sonbuf2[1]='\0';
            while(1)
            {
                msgrcv(msgid,&message,sizeof(message),2,0);
                strcpy(msgS2,message.data);
                if(strlen(msgS2)==message.Cnt_Max)
                {
                    message.mtype =3;
                    msgsnd(msgid,&message,sizeof(message),0);
                    exit(0);
                }
                message.mtype =3;
                strcat(msgS2, sonbuf2);
                strcpy(message.data,msgS2);
                if( sonbuf2[0]=='9'){
                    sonbuf2[0]='0';
                }else{
                    sonbuf2[0]++;
                }
                msgsnd(msgid,&message,sizeof(message),0);
                if(strlen(msgS2)==message.Cnt_Max){
                    message.mtype =5;
                    msgsnd(msgid,&message,sizeof(message),0);
                    exit(0);
                }

            }
            return 0;
        }
    }
    else
    {
        //son1
        char msgS1[256];
        char  sonbuf1[2];
        sonbuf1[0]='a';
        sonbuf1[1]='\0';
        msgrcv(msgid,&message,sizeof(message),1,0);
        strcpy(msgS1,message.data);
        while(1==1){
            message.mtype =2;
            strcat(msgS1,sonbuf1);
            strcpy(message.data,msgS1);

            if(sonbuf1[0]=='z'){
                sonbuf1[0]='a';
            }else{
                sonbuf1[0]++;
            }
            msgsnd(msgid,&message,sizeof(message),0);
            if(strlen(msgS1)==message.Cnt_Max){
                message.mtype =5;
                msgsnd(msgid,&message,sizeof(message),0);
                exit(0);
            }
            msgrcv(msgid,&message,sizeof(message),4,0);
            strcpy(msgS1,message.data);
            if(strlen(msgS1)==message.Cnt_Max){
                message.mtype =2;
                msgsnd(msgid,&message,sizeof(message),0);
                exit(0);
            }
        }
        return 0;
    }
    return 0;
}