#include <stdio.h>

int main()
{
	int i=0, j=0, num, tmp, count=0;
	
	scanf("%d",&num);
	tmp=num;	
	while(num)
		{
			i=num%10;
			num/=10;
			count++;
		}	

	int a[count];
	count=0;
	num=tmp;

	while(num)
	{
		i=num%10;
		num/=10;
		a[count]=i;
		count++;
	}
	
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(a[i]<a[j])
			{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			}
		}
		
	}
	
	for(i=0;i<count;i++)
		printf("%d",a[i]);

	return 0;

	
}

