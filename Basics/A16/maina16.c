#include <stdio.h>

int main()
{
	int a,i,k,tmp;
	scanf("%d",&a);	//
	tmp=0;
	while(a!=0)
	{
		i = a%10;
		a /= 10;
		k = a%10;
		if (i==k)
			tmp=1;
	}
	if(tmp==1)
		printf("YES");
	else
		printf("NO");
		
	return 0;
}
