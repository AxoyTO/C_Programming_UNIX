#include <stdio.h>
#define M 10
#define N 10

int sumOfMax(int A[][N], int m, int n)
{
	int i, j, sum = 0;
	int max = A[0][0];
	for(i=0; i<m; i++)
	{
		max = A[i][0];
		for(j=1; j<n; j++)
		{
			if (A[i][j] > max)
				max = A[i][j];
		}
		sum += max;
	}
	return sum;
}

int main()
{
	int A[M][N], i, j;
	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			scanf("%d", &A[i][j]);
	
	printf("%d",sumOfMax(A, M, N));
	return 0;
}
