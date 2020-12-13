#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

#define MAX 256

struct msgbuf {
    long mtype;
    char str[MAX];
//    int count;
//    int endFlag;
    int countMax;
};

int main() {
    struct msgbuf message;
    key_t key;
    pid_t pid;
    int msgid, ff;

    scanf("%d", &message.countMax);
    //printf("CountMax = %d\n", countMax);
    ff = open("file", O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (ff < 0) {
        perror("file");
        return 1;
    }
    key = ftok("file", 'a');
    if (key < 0) {
        perror("key");
        return 2;
    }
    close(ff);
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("msgget");
        return 3;
    }

//    printf("MESSAGE --> Type=%ld, Str=%s, lengthOfStr=%ld, countMax=%d\n", message.mtype, message.str, strlen(message.str), countMax);

    if ((pid = fork()) < 0) {
        perror("fork");
        return 3;
    } else if (pid == 0) {
        //  C1
        char buf1[256];
        char c1[] = "a";
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        strcpy(buf1, message.str);
        //printf("RECEIVED MESSAGETYPE=%ld AND GOING INSIDE CYCLE C1\n", message.mtype);
        while (1) {
            message.mtype = 2;
            strcat(buf1, c1);
            strcpy(message.str, buf1);
//            printf("C1[%d] = %c\n", i++, c1);
            if (c1[0] == 'z') {
                c1[0] = 'a';
            } else {
                c1[0]++;
            }
            //printf("C1[%d] -> %c\n", i++, c1);
            msgsnd(msgid, &message, sizeof(message), 0);
            if (strlen(buf1) == message.countMax) {
                //done and sent to parent
//                printf("END OF C1\n");
                message.mtype = 5;
                msgsnd(msgid, &message, sizeof(message), 0);
                return 0;
            }
            msgrcv(msgid, &message, sizeof(message), 4, 0);
            strcpy(buf1, message.str);
            if (strlen(buf1) == message.countMax) {
                message.mtype = 2;
                msgsnd(msgid, &message, sizeof(message), 0);
                return 0;
            }
        }
        return 0;
    } else {
        if ((pid = fork()) < 0) {
            perror("fork");
            return 3;
        } else if (pid == 0) {
            //  C2
            char buf2[256];
            char c2[] = "0";
            while (1) {
                msgrcv(msgid, &message, sizeof(message), 2, 0);
                message.mtype = 3;
                strcpy(buf2, message.str);
//                printf("C2[%d] -> %d\n", j++, c2);
                if (strlen(buf2) == message.countMax) {
                    msgsnd(msgid, &message, sizeof(message), 0);
                    return 0;
                }
                strcat(buf2, c2);
                strcpy(message.str, buf2);
                if (c2[0] == '9')
                    c2[0] = '0';
                else
                    c2[0]++;
                msgsnd(msgid, &message, sizeof(message), 0);
                if (strlen(buf2) == message.countMax) {
//                    printf("END OF C2\n");
                    message.mtype = 5;
                    msgsnd(msgid, &message, sizeof(message), 0);
                    return 0;
                }
            }
//            printf("END -> C2\n");
            return 0;
        } else {
            if ((pid = fork()) < 0) {
                perror("fork");
                return 3;
            } else if (pid == 0) {
                //  C3
                char buf3[256];
                char c3[] = "A";
                while (1) {
                    msgrcv(msgid, &message, sizeof(message), 3, 0);
                    //printf("C3[%d] -> %c\n", k++, c3);
                    message.mtype = 4;
                    strcpy(buf3, message.str);
                    if (strlen(buf3) == message.countMax) {
                        message.mtype = 4;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        return 0;
                    }
                    strcat(buf3, c3);
                    strcpy(message.str, buf3);
                    if (c3[0] == 'Z')
                        c3[0] = 'A';
                    else
                        c3[0]++;
                    msgsnd(msgid, &message, sizeof(message), 0);
                    if (strlen(buf3) == message.countMax) {
                        //printf("END OF C3\n");
                        message.mtype = 5;
                        msgsnd(msgid, &message, sizeof(message), 0);
                        return 0;
                    }
                }
//                printf("END -> C3\n");
                return 0;
            } else {
                //  PARENT
                scanf("%d", &message.countMax);
                message.mtype = 1;
                message.str[0] = '\0';
//              printf("FATHER SENDING THE FIRST MSG TO C1\n");
                msgsnd(msgid, &message, sizeof(message), 0);
//              printf("FATHER RECEIVED THE FINAL MSG\n");
                msgrcv(msgid, &message, sizeof(message), 5, 0);
                printf("%s\n", message.str);
                wait(NULL);
                wait(NULL);
                wait(NULL);
                msgctl(msgid, IPC_RMID, 0);
                return 0;
            }
        }
    }
    return 0;
}
