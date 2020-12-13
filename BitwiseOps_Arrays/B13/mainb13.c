#include <stdio.h>
#define N 10

void changeMaxMin(int* a, int min, int max, int m)
{
	int tmp,i;
	
	for(i=0;i<N;i++)
	{
		if(a[i]>=a[max])
			max = i;
		if(a[i]<=a[min])
			min = i;	
	}
	
	tmp = a[min];
	a[min]=a[max];
	a[max]=tmp;
}

int main()
{
	int i, max=0, min=0, a[N]; 
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	
	changeMaxMin(a, min, max, N);

	for(i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}

	return 0;	
}
