#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    int f1, f2, r, w, count = 0;
    char buf[1024];
    struct stat s;

    if (argc < 3)
        return 1;

    f1 = open(argv[1], O_RDONLY);
    if (f1 == -1)
        return 1;

    stat(argv[1], &s);
    f2 = creat(argv[2], s.st_mode);
    if (f2 == -1)
        return 1;

    while (1) {
        r = read(f1, buf, 1);
        if (r == 0)
            break;
        count++;

        if (count < 51) {
            w = write(f2, buf, 1);
            if (buf[0] == '\n') {
                count = 0;
            }
        } else {
            //printf("%d\n", count);

            while (read(f1, buf, 1)) {
                if (buf[0] == '\n')
                {
                    write(f2, "\n", 1);
                    break;
                }}
            count = 0;

        }/* if (w > 0) {
             write(f2, "\n", 1);
             while (read(f1, buf, 1)) {
                 if (buf[0] == '\n' || buf[0] == EOF)
                     break;
             }
         }*/
        //   printf("in cycle r = %d w = %d\n", r, w);
    }
    //printf("r = %d w = %d\n", r, w);
    close(f1);
    close(f2);

    return 0;
}
