#include <stdio.h>

int main()
{
	int a,i,duo,uno;
	scanf("%d",&a);		//1234
	duo=0;
	uno=0;
	while(a!=0)
	{
		i=a%10;		// i=4		i=3	i=2	i=1
		a/=10;		// a=123	a=12	a=1	a=0
		i=i%2;		// i=0		i=1	i=0	i=1
		if(i==0)	
			duo++;
		if(i==1)
			uno++;	
			
	}

	printf("%d %d",duo,uno);
	return 0;
}
