#include <stdio.h>

void print_simple(int n)			
{
	int i;		
	for (i=2; n!=1; i++)			
	{
		if(n%i == 0)
		{
			n /= i;
			if(n!=1)
				printf("%d ",i);
			else
				printf("%d",i);
			i--;
		}
	}

}

int main()
{
	int s;
	scanf("%d",&s);
	print_simple(s);
	return 0;
}
