#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr=NULL;
	int num=1, i=0, j;
	
	arr = (int*)malloc(num*sizeof(int));
	if(arr==NULL)
		exit(1);
	
	while(scanf("%d", arr+i) != EOF)	//EOF = END OF FILE
	{
		i++;
		if (i==num)
		{
			int *a=NULL;
			num*=2;
			a = (int*)realloc(arr,num*sizeof(int));
			if(arr==NULL)
			{
				free(arr);
				exit(1);
			}
			else
				arr = a;
		}
	}
	
	for(j=i-1; j>=0; j--)
		printf("%d ", arr[j]);
	printf("\n");
	free(arr);
	arr=NULL;
	return 0;
}
