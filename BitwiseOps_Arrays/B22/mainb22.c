#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

void allocateMemory(int ***M, int rows, int columns)
{
	int i;
	
	*M=(int**)malloc(rows*sizeof(int*));
	if(*M==NULL)
	{
		printf("%d", ERROR);
		exit(0);
	}
	
	for(i=0; i<rows; i++){
		(*M)[i]=NULL;
		(*M)[i]=(int*)malloc(columns*sizeof(int));
		if((*M)[i]==NULL)
		{
			printf("%d", ERROR);
			exit(0);
		}
	}
}


void freeMemory(int **M, int rows)
{
	int i;
	for(i=0; i<rows; i++){
		free(M[i]);
		M[i]=NULL;
	}
	free(M);
	M = NULL;
}

void printMatrix(int **M, int rows, int columns)
{
	int i,j;
	
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++)
			printf("%d ", M[i][j]);
	printf("\n");
	}
}

int main()
{

	int i,j,k,rowsA,columnsA,rowsB,columnsB;
	int **A=NULL;							
	int **B=NULL;							
	int **C=NULL;							
	
	scanf("%d%d",&rowsA,&columnsA);
	allocateMemory(&A,rowsA,columnsA);
	/*A=(int**)malloc(rowsA*sizeof(int*));
	if(A==NULL)
	{
		printf("%d", ERROR);
		exit(0);
	}
	
	for(i=0; i<rowsA; i++){
		A[i]=NULL;
		A[i]=(int*)malloc(columnsA*sizeof(int));
		if(A[i]==NULL)
		{
			printf("%d", ERROR);
			exit(0);
		}
	}
	*/
	
	for(i=0;i<rowsA;i++)
		for(j=0;j<columnsA;j++)
			scanf("%d",&A[i][j]);
	
	scanf("%d%d",&rowsB,&columnsB);
	allocateMemory(&B,rowsB,columnsB);
	/*B=(int**)malloc(rowsB*sizeof(int*));
	if(B==NULL)
	{
		printf("%d", ERROR);
		exit(0);
	}
	
	for(i=0; i<rowsB; i++){
		B[i]=NULL;
		B[i]=(int*)malloc(columnsB*sizeof(int));
		if(B[i]==NULL)
		{
			printf("%d", ERROR);
			exit(0);
		}
	}
	*/
	for(i=0;i<rowsB;i++)
		for(j=0;j<columnsB;j++)
			scanf("%d",&B[i][j]);
				
	if(columnsA!=rowsB)
	{
		printf("%d", ERROR);
	}
	else
	{
		allocateMemory(&C, rowsA, columnsB);
	/*C=(int**)malloc(rowsA*sizeof(int*));
	if(C==NULL)
	{
		printf("%d", ERROR);
		exit(0);
	}
	
	for(i=0; i<rowsA; i++){
		C[i]=NULL;
		C[i]=(int*)malloc(columnsB*sizeof(int));
		if(C[i]==NULL)
		{
			printf("%d", ERROR);
			exit(0);
		}
	}
	*/
			
		for(i=0; i<rowsA; i++)
		{
			for(j=0; j<columnsB; j++)
			{
				C[i][j]=0;
					for(k=0; k<columnsA; k++)
					{
						C[i][j] += A[i][k]*B[k][j];
					}
			}
			
		}
//	printf("C=");
	printMatrix(C,rowsA,columnsB);
//	printf("\n");
	freeMemory(C,rowsA);
	
	}
/*	printf("\nA=\n");
	printMatrix(A,rowsA,columnsA);
	printf("\n");
	printf("B=\n");
	printMatrix(B,rowsB,columnsB);
	*/
	freeMemory(B,rowsB);	
	freeMemory(A,rowsA);
			
	
	return 0;	
}
