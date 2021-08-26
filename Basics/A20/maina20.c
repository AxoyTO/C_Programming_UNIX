#include <stdio.h>

int main()
{
	char c;
	int count = 0;
	
	do{
		scanf("%c",&c);
		if	(c >='0' && c <='9')
			count++;
		}while(c != '.');
		printf("%d",count);
		
		return 0;
}
