#include <stdio.h>

int main()
{
	int a,b,tmp;
	tmp = 0;
	scanf("%d%d",&a,&b);
	while(a<=b)
	{
		tmp = tmp + a*a;
		a++;
	}
	printf("%d",tmp);
	return 0;
}
