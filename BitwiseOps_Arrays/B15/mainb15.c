#include <stdio.h>
#define m 100

int main()
{
		int i,j=0, count=1, arr[m];
		
		for(i=0;i<m;i++)
		{
			scanf("%d",arr+i);
		}
		
	
		for(i=1;i<m;i++)
		{
			if(arr[i]!=arr[i-1])
				count++;
		}
		
		if(arr[0]!=0)
			count++;
		
		const int size = count;
		int a[size];
		
		
		
		if(arr[0]!=0)
		{
			a[0]=0;
			
			for(i=1;i<size;i++)
			{
				count = 1;
				while(j<m-1)
				{
					if(arr[j]==arr[j+1])
						count++;
					else
					{
						j++;
						break;
					}
					j++;
				}
				a[i]=count;
				
			}
		}
		else
		{
			for(i=0;i<size;i++)
			{
				count=1;
				while(j<m-1)
				{
					if(arr[j] == arr[j+1])
						count++;
					else
						{
						j++;
						break;
						}
						j++;
				}	
				a[i]=count;
			}
		}
		
		printf("[");
		for(i=0;i<size;i++)
		{
			if(i==size-1)
			printf("%d", a[i]);
			else
			printf("%d,",a[i]);
		}
		printf("]");
		return 0;
}
