#include <stdio.h>

int main()
{
	int i,num,min,max;
	scanf("%d",&min);
	max=min;
	//printf("num=%d max=%d min=%d\n",num,max,min);
	for (i=1; i<5; i++)
	{
		scanf("%d",&num);
		if(num<min)
			min=num;
		if(num>max)
			max=num;

	//	printf("num=%d max=%d min=%d\n",num,max,min);
	}
	printf("%d",min+max);
	
	return 0;

}
