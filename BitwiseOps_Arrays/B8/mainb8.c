#include <stdio.h>

 /* void printBits(unsigned int num)
{
	unsigned short mask = 1;
	mask <<= 3;
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
*/

void changeBits(unsigned int num)
{
	unsigned int newNum=0;	
		
	while(num)
	{	
		newNum <<= 1;
		newNum = newNum | (num&1);	
		num>>=1;
	}
	printf("%u\n",newNum);
}

int main()
{
	unsigned int num;
	scanf("%u",&num);
	//printBits(num);
	changeBits(num);
	return 0;
}
