#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>

int main(int argc, char **argv) {
    	int fd1, fd2, a;
//    int m, n, indexN, indexM, tmp, num, indexNum;
//    struct stat s;
	int cur_min = INT_MAX;
	int int_max = INT_MAX;
	long pos;

    if (argc < 3) {
        fprintf(stderr, "There should be at least 2 files attached in by arguments\n");
        return 1;
    }
    fd1 = open(argv[1], O_RDWR);
    if (fd1 == -1) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        return 1;
    }

//    stat(argv[1], &s);
    fd2 = open(argv[2], O_RDWR | O_CREAT, 0644);
    if (fd2 == -1) {
        fprintf(stderr, "Failed to create/open file %s\n", argv[2]);
        return 1;
    }

    while(1)
    {
	    lseek(fd1, 0, SEEK_SET);
	    //
	    while(read(fd1, &a, sizeof(int)) == sizeof(int))
	    {
		    if(a<cur_min)
		    {
			    cur_min = a;
			    pos = lseek(fd1, 0, SEEK_CUR)-sizeof(int);
		    }
	    }
	    if(cur_min == INT_MAX)
		    break;

	    write(fd2, &cur_min, sizeof(int));
	    lseek(fd1, pos, SEEK_SET);
	    write(fd1, &int_max, sizeof(int));
    }
    close(fd1);
    close(fd2);
    return 0;
}
/*
    lseek(fd1, 0, SEEK_SET);
    while ((read(fd1, &m, sizeof(int)) == sizeof(int)))
        write(fd2, &m, sizeof(int));


    lseek(fd1, 0, SEEK_SET);
    while ((read(fd1, &m, sizeof(int)) == sizeof(int))) 
    {
        indexNum = lseek(fd1, 0, SEEK_CUR) - sizeof(int);
	num = m;
	n = m;
	indexN = indexNum;
	while((read(fd1, &m, sizeof(int)) == sizeof(int)))
	{
		if(m < n)
		{
			n = m;
			indexN = lseek(fd1, 0, SEEK_CUR) - sizeof(int);
		}
		else
			break;
	}
       // printf("\n");
        lseek(fd1, indexNum + sizeof(int), SEEK_SET);
 	read(fd1, &m, sizeof(int));
	lseek(fd1, indexNum, SEEK_SET);
	write(fd2, &n, sizeof(int));
	lseek(fd1, indexN, SEEK_SET);
	write(fd2, &n, sizeof(int));
	lseek(fd1, indexNum + sizeof(int), SEEK_SET);
    }

    return 0;
}*/
