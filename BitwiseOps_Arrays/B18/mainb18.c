#include <stdio.h>
#define M 5
#define N 5

int arithmeticMean(int A[][N], int m, int n)
{
	int i,j;
	int sum=0;
	int avg=0;
	for(i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			if(i==j)
			sum += A[i][j];	
		}
	}
		
		avg=sum/n;
		return avg;
}

int biggerThanAvg(int A[][N], int m, int n)
{
	int i, j, count;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(A[i][j] > arithmeticMean(A, M, N))
				count++;
		}
	}
	
	return count;
} 

int main()
{
	int A[M][N], i, j;
	
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			scanf("%d",&A[i][j]);
	
	printf("%d", biggerThanAvg(A, M, N));
}
