#include <stdio.h>

int main()
{
	int a,i;
	scanf("%d",&a); // 1234
	i = a%10;
	while(a!=0)
	{		
		a /= 10;		
		i += a%10;			
	}
	printf("%d",i);	
	return 0;
}
