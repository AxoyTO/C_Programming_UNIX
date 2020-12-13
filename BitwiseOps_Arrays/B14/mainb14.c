#include <stdio.h>
#include <stdlib.h>

void changeArray(int *arr, int size)
{
	
	int i,j = 0, tmp, flag;
	do{
		flag = 0;
		for(i=0; i<size-1-j; i++)
		{
				if(abs(arr[i]%2) > abs(arr[i+1]%2))
				{
					tmp = arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=tmp;
					flag = 1;
				}
		}
		j++;
	}while(flag);
	
	
	/*int i, even[size], odd[size];
	int e,o;
	//int j, count=0, tmp=0, tmpArr[size];
	e=o=0;
	
	for (i=0;i<size;i++)
	{
		if(arr[i]%2==0)
		{
			even[e]=arr[i];
			e++;		
		}
		else
		{
			odd[o]=arr[i];
			o++;
		}
	}
	
	for(i=0;i<e;i++)
		printf("%d ",even[i]);
	
	for(i=0;i<o;i++)
		printf("%d ",odd[i]);
	
	
	/*for(i=0;i<size;i++)
		tmpArr[i]=arr[i];
		
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]%2==1 && arr[j]%2==0)
			{
					tmp=arr[i];
					arr[i]=arr[j];
					arr[j]=tmp;
			}
		}
	}
	
	while(count<size)
	{
		count++;
		if(arr[count]%2!=0)
			break;			
	}
	tmp=0;
	for(i=0;i<size;i++)
	{
		if(tmpArr[i]%2==1)
		{
			arr[count]=tmpArr[i];
			count++;
		}
	}*/ 
}

int main()
{
	const int N = 20;
	int i,  arr[N];
	
	for(i=0; i<N; i++)
		scanf("%d",arr+i);

	changeArray(arr, N);
	
	for(i=0; i<N; i++)
		printf("%d ", arr[i]);
	return 0;
	
}
