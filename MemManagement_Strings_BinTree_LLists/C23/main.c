#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	long n, min, indexMin;

	if(argc<2)
	{
		fprintf(stderr, "There should be a binary file in argv[1]!\n");
		return 1;
	}
	fd = open(argv[1], O_RDWR);
	if(fd==-1)
	{
		fprintf(stderr, "Can't open file input.bin\n");
		return 1;
	}
	if(read(fd, &n, sizeof(long)) == sizeof(long))
	{
		min = n;
		indexMin = 0;
	}
	else
		return 0;

	while(read(fd, &n, sizeof(long)) == sizeof(long))
	{
		if(n<min)
		{
			min = n;
			indexMin = lseek(fd, 0, SEEK_CUR) - sizeof(long);
		}
	}

//	printf("%ld\n", min);
	min *= -1;
	lseek(fd, indexMin, SEEK_SET);
	write(fd, &min, sizeof(long));
//	printf("%ld", min);
	close(fd);
	return 0;
}
