#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<limits.h>

int main(int argc, char**argv)
{
        int fd1, fd2, a;
        int cur_min = INT_MAX; // <- limits.h
        int int_max= INT_MAX;
        long pos;

        if(argc<3)
        {
                printf ("./c24 input.bin output.bin\n");
                return 1;}
        fd1 = open(argv[1], O_RDWR);
        if (fd1<0) return 1;

        fd2 = creat(argv[2], 0644);
        if (fd2<0) return 1;

        while(1)
        {
                lseek(fd1, 0, SEEK_SET);//в начало файла
                cur_min = INT_MAX;
                while(read(fd1, &a, sizeof(int)) == sizeof(int))
                {
                        if (a < cur_min)
 {
                                cur_min = a;
                                pos = lseek(fd1, 0, SEEK_CUR) - sizeof(int);
                        }

                }
                if (cur_min == INT_MAX)
                        break;
                write(fd2, &cur_min, sizeof(int));
                lseek(fd1, pos, SEEK_SET);
                write(fd1,&int_max, sizeof(int));
        }
        close(fd1); close(fd2);
        return 0;
}