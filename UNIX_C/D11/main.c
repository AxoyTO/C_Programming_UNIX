#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int main() {
    pid_t pid1, pid2;
    key_t key;
    int N, ff, shmid, semid;
    int fd[2], ft[2];
    int *phy;
    int count = 2;
    struct sembuf P1 = {0, -1, 0};
    struct sembuf V1 = {0, 1, 0};
    struct sembuf P2 = {1, -1, 0};
    struct sembuf V2 = {1, 1, 0};

    if (pipe(fd) < 0) {
        perror("pipe");
        return 202;
    }

//	printf("BP_1\n");
    ff = open("file", O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (ff < 0) {
        perror("open");
        return 404;
    }
    key = ftok("file", 'k');
    if (key < 0) {
        perror("key");
        return 3;
    }
    close(ff);

    semid = semget(key, 2, IPC_CREAT | 0666);
    if (semid < 0) {
        perror("semget");
        return 101;
    }

    semctl(semid, 0, SETALL, 0);

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork1");
        return 1;
    } else if (pid1 == 0) {
        /*****		SON1		*****/
        /*	GENERAL CODE	*/
        semop(semid, &P1, 1);
        //	printf("SON1 in GENERAL CODE\n");
        read(fd[0], &N, sizeof(int));
        //    printf("N = %d\n", N);
        semid = semget(key, 2, IPC_CREAT | 0666);
        if (semid < 0) {
            perror("semget");
            return 101;
        }

        shmid = shmget(key, N, IPC_CREAT | 0666);
        if (shmid < 0) {
            perror("shmget");
            return 4;
        }

        phy = shmat(shmid, NULL, 0);
        if (phy == (void *) -1) {
            perror("shmat");
            return 5;
        }
        count = phy[0];
        /*	END OF GENERAL CODE	*/
        //	semop(semid, &P1, 1);
        //printf("SON1\n");

        //	printf("N = %d\n", N);
        /*	while(count<N)
            {
                phy[count] = phy[count-1] + phy[count-2];
                printf("S1 -> %d ---- count = %d\n", phy[count], count);
                count++;
                write(fd[1], &count, sizeof(int));
                semop(semid, &P1, sizeof(int));
                read(fd[0], &count, sizeof(int));
                semop(semid, &V2, sizeof(int));
            }
         */
        while (phy[0] < N) {
            if (!(phy[0] % 2)) {
                //    printf("phy[phy[0]+1] = %d ------- phy[0] = %d\n", phy[phy[0]], phy[0]);
                phy[phy[0] + 1] = phy[phy[0] - 1] + phy[phy[0]];
                //  printf("S1 -> %d ----- count = %d\n", phy[phy[0]+1], phy[0]);
                phy[0]++;
            }
        }
        //    printf("END OF SON 1\n");
        close(fd[0]);
        close(fd[1]);
        return 0;
    } else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("fork2");
            return 2;
        } else if (pid2 == 0) {
            /*****		SON2		*****/
            /*	GENERAL CODE	*/
            semop(semid, &P2, 1);
            //	printf("SON2 in GENERAL CODE\n");
            read(fd[0], &N, sizeof(int));
            //    printf("N = %d\n", N);
            shmid = shmget(key, N, IPC_CREAT | 0666);
            if (shmid < 0) {
                perror("shmget");
                return 4;
            }
            phy = shmat(shmid, NULL, 0);
            if (phy == (void *) -1) {
                perror("shmat");
                return 5;
            }
            //count = phy[0];
            /*	END OF GENERAL CODE	*/
            //	semop(semid, &P2, 1);
            //	printf("SON2\n");

            //	printf("N = %d\n", N);

            //	read(fd[0], &count, sizeof(int));
            /*	while(count<N)
                {
                    read(fd[0], &count, sizeof(int));
                    semop(semid, &V1, 1);
                    phy[count] = phy[count-1] + phy[count-2];
                    printf("S2 -> %d ----- count = %d\n", phy[count], count);
                    count++;
                    write(fd[1], &count, sizeof(int));
                    semop(semid, &P2, 1);
                }
             */

            while (phy[0] < N) {
                if ((phy[0] % 2)) {
                    //    printf("phy[phy[0]+1] = %d ------- phy[0] = %d\n", phy[phy[0]], phy[0]);
                    phy[phy[0] + 1] = phy[phy[0]] + phy[phy[0] - 1];
                    //  printf("S2 -> %d ----- count = %d\n", phy[phy[0] + 1], phy[0]);
                    phy[0]++;
                }
            }
            close(fd[0]);
            close(fd[1]);
            //        printf("END OF SON 2\n");
            return 0;
        } else {
            /*****		FATHER		*****/
            //	semop(semid, &V1, 1);
            //	semop(semid, &P1, 1);
            //	printf("FATHER\n");
            scanf("%d", &N);
            int i;
            N++;

            /* 	GENERAL CODE 	*/
            shmid = shmget(key, N, IPC_CREAT | 0666);
            if (shmid < 0) {
                perror("shmget");
                return 4;
            }
            //     printf("N = %d\n", N);
            phy = shmat(shmid, NULL, 0);
            if (phy == (void *) -1) {
                perror("shmat");
                return 5;
            }
            /*	END OF GENERAL CODE	*/
            phy[0] = count;
            phy[1] = 0;
            phy[2] = 1;

            write(fd[1], &N, sizeof(int));
            write(fd[1], &N, sizeof(int));

            semop(semid, &V1, 1);
            semop(semid, &V2, 1);

            wait(NULL);
            wait(NULL);

            //	printf("BP final %d\n", count);

            for (i = 1; i < N; i++) {
                if (i < N-1)
                    printf("%d  ", phy[i]);
                else
                    printf("%d\n", phy[i]);
            }
//			printf("test");
//			printf("\n");
            close(fd[0]);
            close(fd[1]);
            semctl(semid, 0, IPC_RMID, 0);
            semctl(semid, 1, IPC_RMID, 0);
            shmctl(shmid, IPC_RMID, 0);
            return 0;
        }
    }
}