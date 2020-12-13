#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int max, min, a;
	long max_p, min_p;

	fd = open("data.bin", O_RDWR);
	if(fd==-1)
	{
		fprintf(stderr, "Can't open file data.bin\n");
		return 1;
	}
	if(read(fd, &a, sizeof(int)) == sizeof(int))
	{
		max = min = a;
		max_p = min_p = 0;
	}
	else
		return 0;


	while(read(fd, &a, sizeof(int)) == sizeof(int))
	{
		if(a>max)
		{
			max = a;
			max_p = lseek(fd, 0, SEEK_CUR) - sizeof(int);	//-sizeof(int) because we are reading by bytes
		}
		if(a<min)
		{
			min = a;
			min_p = lseek(fd, 0, SEEK_CUR) - sizeof(int);
		}
	}

	lseek(fd, max_p, SEEK_SET);
	write(fd, &min, sizeof(int));
	lseek(fd, min_p, SEEK_SET);
	write(fd, &max, sizeof(int));

	close(fd);
	return 0;

}
