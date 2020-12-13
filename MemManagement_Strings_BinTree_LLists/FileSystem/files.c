#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fi, *fo;	//filein fileout
	if(argc != 3)
	{
		fprintf(stderr, "Enter 2 files!");
		return -1;
	}

	fi = fopen(argv[1], "r");
	if(fi == NULL)
	{
		fprintf(stderr, "FILE %s CAN NOT BE OPENED!\n", argv[1]);
		return -2;
	}

	int num;

	fo = fopen(argv[2], "w");
	if(fo == NULL)
	{
		fprintf(stderr, "FILE %s CAN'T BE OPENED!\n", argv[2]);
		return -2;
	}
	while(fscanf(fi, "%d", &num) != EOF)
		fprintf(fo, "%d ", num*2);
	
//	while(fscanf(stdin, "%d", &num) != EOF)
//		fprintf(stdout, "%d ", 2*num);
//
	printf("\n");
	fclose(fi);
	fclose(fo);
	return 0;
}
