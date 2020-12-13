#include <stdio.h>
#include <fcntl.h>  // open, creat e.t.c.
#include <unistd.h> // read, write
#include <sys/stat.h> // stat

int main(int argc, char **argv)
{
	int fd, fd1, fd2, n, m;
	char buf[1024];
	struct stat s;


	/*fd = open("input", O_WRONLY | O_CREAT | O_TRUNC, 0644); //if fd==-1 -> NOT OPENED
	fd = creat("output", 0644);
	
	if(fd == -1)
	{
		fprintf(stderr, "Can't open file input\n");
		return 1;
	}
	printf("file descryptor = %d\n", fd);
	close(fd);
	return 0;
	*/

	if(argc<3)
	{
		fprintf(stderr, "Use: ./exe firstfile secondfile");
		return 3;
	}
	fd1 = open(argv[1], O_RDONLY);
	if(fd1==-1)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		return -1;
	}
	stat(argv[1], &s);
	fd2 = creat(argv[2], s.st_mode);
	if(fd2 == -1)
	{
		fprintf(stderr, "Can't open file %s\n", argv[2]);
		return 2;
	}
	while( (n = read(fd1, buf, 1024)) > 0)
		//m = write(fd2, buf, n);
		write(fd2, buf, n);
	//printf("%d\n", m);
	close (fd1);
	close (fd2);

	return 0;
}
