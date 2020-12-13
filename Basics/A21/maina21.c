#include <stdio.h>

int main()
{
	char c;
	int sum=0,tmp;
	do{
		scanf("%c",&c);
		if(c>='0' && c<='9')
			{
				tmp = c - 48;
				sum += tmp;
				// printf("%d %d\n",tmp,sum);
			}

	}while(c != '.');
	printf("%d",sum);	
	return 0;	
}
