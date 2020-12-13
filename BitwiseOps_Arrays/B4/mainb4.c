#include <stdio.h>

int is_happy_number(int n)
{
	int sum=0,prod=1,t;
	while(n!=0)
	{
		t=n%10;
		sum+=t;
		prod*=t;
		n/=10;
	}
	// printf("%d %d\n",sum,prod);
	return (sum==prod);
}

int main()
{
	int n;
	scanf("%d",&n);
	if(is_happy_number(n))
		printf("YES");
	else
		printf("NO");
	return 0;
}
