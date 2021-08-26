#include <stdio.h>

int main()
{
	int a,i;
	scanf("%d",&a); // 435
	i = a%10;		// i = 5 
	a /= 10;		// a = 43
	i *= a%10;		// i = 3 * 5 = 15
	a /= 10;		// a = 4
	i *= a;			// i = 3 * 5 * 4 = 60
	printf("%d",i);	
}
