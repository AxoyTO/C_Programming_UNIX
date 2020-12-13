#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if((a<=b) && (a<=c) && (a<=d) && (a<=e))
		printf("%d",a);
	else if ((b<=a) && (b<=c) && (b<=d) && (b<=e))
		printf("%d",b);
	else if ((c<=a) && (c<=b) && (c<=d) && (c<=e))
		printf("%d",c);
	else if ((d<=a) && (d<=b) && (d<=c) && (d<=e))
		printf("%d",d);
	else 
		printf("%d",e);
	return 0;
}
