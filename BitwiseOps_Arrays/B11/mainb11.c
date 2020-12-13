#include <stdio.h>
#define M 10

int main()
{
	int i, tmp=0,tmp1=0, a[M];
	
	for(i=0;i<M;i++)
		scanf("%d",&a[i]);	
	
	for(i=0;i<M/4;i++)
	{								
		tmp=a[i];				
		a[i]=a[M/2-i-1];	
		a[M/2-i-1]=tmp;		
				
		tmp1=a[M/2+i];		
		a[i+M/2]=a[M-i-1];
		a[M-i-1]=tmp1;
	}
	

	for(i=0;i<M;i++)
		printf("%d ",a[i]);
		
	return 0;
}
