#include <stdio.h>

int main()
{
	int a,b,c,d,tmp;
	scanf("%d",&a);		
	d=a;
	tmp = 0;								
	while(a!=0)
	{
		b = a%10; 		
		a /= 10;		
		while(a!=0)
		{	
			c = a%10;			
			a /= 10;		
			if (b==c)
				tmp=1;
		}
		d /= 10;		
		a = d;		
	}
	if(tmp==1)
		printf("YES");
	else
		printf("NO");
		
	return 0;
}
