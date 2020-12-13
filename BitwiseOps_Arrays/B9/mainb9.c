#include <stdio.h>

int main()
{
	int a[10];
	int i=1,max,maxNo=1,min,minNo=1;
	scanf("%d",&a[0]);
	max=a[0];
	min=a[0];
	while(i<10)
	{
		scanf("%d",&a[i]);
		if(a[i]<min)
		{
			min=a[i];
			minNo=i+1;
		}
		if(a[i]>max)
		{
			max=a[i];
			maxNo=i+1;
		}
		i++;
	}
	printf("%d %d %d %d",maxNo,max,minNo,min);	
	return 0;	
}
