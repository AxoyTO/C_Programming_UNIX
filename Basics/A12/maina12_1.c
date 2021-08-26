#include <stdio.h>

int main()
{
	int i,num,min;
	scanf("%d",&min);
	
	for (i=1; i<5; i++)
	{
		scanf("%d",&num);
		if(num<min)
			min=num;
	}
	printf("%d",min);
	
	return 0;

}
