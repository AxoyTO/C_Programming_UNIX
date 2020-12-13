#include <stdio.h>

int Sum(int s)
{
	int i,sum=0;
	for(i=1;i<=s;i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",Sum(n));	
	return 0;

}
