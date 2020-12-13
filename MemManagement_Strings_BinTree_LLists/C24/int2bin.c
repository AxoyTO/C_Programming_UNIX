#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fi;
	int fd;
	int num;

	if(argc<3)
	{
		printf("./int2bin textfile binfile\n");
		return 1;
	}
	fi = fopen(argv[1], "r");
	if(fi==NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		return 2;
	}

	fd = creat(argv[2], 0644);
	if(fd==-1)
	{
		fprintf(stderr, "Can't open f ile %s\n", argv[2]);
		return 2;
	}

	while(fscanf(fi, "%d", &num)!=EOF)
		write(fd, &num, sizeof(int));

	fclose(fi);
	close(fd);
	return 0;
}
