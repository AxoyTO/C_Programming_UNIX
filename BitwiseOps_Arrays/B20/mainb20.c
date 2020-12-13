#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *a = NULL;
	int *b = NULL;
	int i, n, count = 0;
	scanf("%d", &n);

	a = (int*) malloc(n*sizeof(int));
	if(a == NULL)
	{
		printf("Error allocating memory");
		exit(1);
	}

	for(i=0; i<n; i++)
		scanf("%d", a+i);
	
	for(i=0; i<n; i++)
		if((a[i]/10)%10 == 0)
			count++;
			
	if (count!=0)
	{
		b = (int*)malloc(count*sizeof(int));
		if(b == NULL)
		{
			printf("Error allocating memory");
			exit(1);
		}
		count = 0;
		for(i=0; i<n; i++)
			if((a[i]/10)%10 == 0)
				b[count++] = a[i];
				
		for(i=0; i<count; i++)
			printf("%d ", b[i]);
		printf("\n");
		free(b);
		b=NULL;
	}
	
	free(a);
	a=NULL;
	return 0;
}
