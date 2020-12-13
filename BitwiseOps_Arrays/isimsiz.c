#include <stdio.h>
#include <stdlib.h>

int main()
{
	float **a;
	int m,n,i,j;
	scanf("%d%d",&m, &n);
	a=(float**)malloc(m*sizeof(float*));
	if(a==NULL)
		exit(1);
		
	for(i=0; i<m; i++)
	{
		a[i] = (float*)malloc(n*sizeof(float));
		if(a[i]==NULL)
			exit(1);
	}
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%f",&a[i][j]);
	
	for(j=0; j<n; j++)
	{
		for(i=0; i<m; i++)
			printf("%.2f ", a[i][j]);
		printf("\n");
	}
	
	for(i=0; i<m ;i++)
		free(a[i]);
	
	free(a);
	a=NULL;
	return 0;
}
