#include <stdio.h>

void print_bit(short num)
{
	unsigned short mask = 1;
	mask <<= sizeof(short)*8 - 1;
	while(mask)
	{
		if(num&mask)
			printf("1");
		else
			printf("0");
		mask >>= 1;
	}
	printf("\n");
}

int main()
{
	short num;
	scanf("%hd",&num);
	print_bit(num);
	return 0;
}
