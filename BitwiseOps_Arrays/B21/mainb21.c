#include <stdio.h>
#include <stdlib.h>

long factorial(int n) 
{ 
	int i; 
	long result = 1; 
  
	for (i=1; i<=n; i++) 
	result = result*i; 
   
	return result; 
}

int combination(int n, int k)			//C(n,k) = k!/((n-k)!n!)
{
	int result;
	result=factorial(n)/(factorial(n-k)*factorial(k));
	
	return result;
}

int main()
{
	int **p;
	int i,j,n;
	
	scanf("%d",&n);
	p = (int**)malloc((n+1)*sizeof(int*));
	if(p==NULL)
	{
		printf("Error allocating memory of p");
		exit(1);
	}
	
	for(i=0; i<=n; i++)
	{
			p[i]=(int*)malloc((i+1)*sizeof(int));
			if(p[i]==NULL)
			{
				printf("Error allocating memory of p[i]");
				exit(1);
			}
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			p[i][j]=combination(i,j);
		}
	}

		for(i=0;i<=n;i++)
		{
			for(j=0;j<=i;j++)
			{
				printf("%d ",p[i][j]);
			}
			printf("\n");
		}
	
	for(i=0;i<=n;i++)
		free(p[i]);
	
	
	free(p);
	p=NULL;
	return 0;
}
