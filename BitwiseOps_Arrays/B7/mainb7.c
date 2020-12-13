#include <stdio.h>

void print_rwx(short num)
{
	int mask=1;
	mask <<= 8;

	while(mask){
		if(num&mask)
			printf("r");
		else
			printf("-");
		mask >>= 1;
		if(num&mask)
			printf("w");
		else
			printf("-");
		mask >>= 1;
		if(num&mask)
			printf("x");
		else
			printf("-");
		mask >>= 1;
	}
		
}

int main()
{
	short num;
	scanf("%ho",&num);
	print_rwx(num);
	return 0;
}
