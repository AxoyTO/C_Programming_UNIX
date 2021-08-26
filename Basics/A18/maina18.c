#include <stdio.h>

int main()
{
	int num ,digit;
	scanf("%d",&num);
	while(num)
	{
		digit = num%10;
		if(digit%2)
		{
			printf("NO");
			break;
		}
		num/=10;
	}
	
	if(!num)
		printf("YES");
		
	return 0;
}
