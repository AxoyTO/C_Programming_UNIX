#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(((c<a+b) && (c>abs(a-b))) && ((b<a+c) && (b>abs(a-c))) && ((a<b+c) && a>abs(b-c)))
		printf("YES");
	else
		printf("NO");
		
	return 0;
}
