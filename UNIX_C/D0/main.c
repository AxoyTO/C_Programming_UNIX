#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int var = 5;//1 process
    fork();	//2 process
    fork();	//4 process
    fork();	//8 process

    printf("var = %d PID =%d PPID = %d\n", var, getpid(), getppid());
    return 0;
}
