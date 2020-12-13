#include <stdio.h>

int main()
{
	int a,b,c,d,e,min,max;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if((a<=b) && (a<=c) && (a<=d) && (a<=e))
		min=a;
	else if ((b<=a) && (b<=c) && (b<=d) && (b<=e))
		min=b;
	else if ((c<=a) && (c<=b) && (c<=d) && (c<=e))
		min=c;
	else if ((d<=a) && (d<=b) && (d<=c) && (d<=e))
		min=d;
	else 
		min=e;

	if((a>=b) && (a>=c) && (a>=d) && (a>=e))
		max=a;
	else if ((b>=a) && (b>=c) && (b=d) && (b>=e))
		max=b;
	else if ((c>=a) && (c>=b) && (c>=d) && (c>=e))
		max=c;
	else if ((d>=a) && (d>=b) && (d>=c) && (d>=e))
		max=d;
	else 
	{
		max=e;
	}	
		
		printf("%d",max+min);
		return 0;
}
