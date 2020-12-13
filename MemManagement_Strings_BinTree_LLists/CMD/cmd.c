#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)		//./a.out	str	7	3.14
{					//argv[0]	argv[1]	argv[2]	argv[3]	--- argc=4
	int i;
	float f;

	for(i=0; i<argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	i = atoi(argv[1]);
	printf("i = %d\n", i);

	i = atoi(argv[2]);
	f = atoi(argv[3]);
	printf("i = %d\n", i);
	printf("f = %f\n", f);

	return 0;
}

