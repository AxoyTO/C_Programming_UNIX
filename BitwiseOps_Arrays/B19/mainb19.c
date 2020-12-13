#include <stdio.h>
#include <stdlib.h>
#define M 10

void prod(int *A, int size, int flag)		//production of odds in number
{
	int i, num=1, tmp=0;
	if(flag==1)
	{
		for(i=0; i<size; i++)
		{
			if(*(A+i)%2!=0)
			{
				while(*(A+i))
				{
					tmp=*(A+i)%10;
					*(A+i)/=10;
					if(tmp%2!=0)
						num *= tmp;
				}
				*(A+i)=num;
			}
			num=1;
		}
	}
	else
	{
		for(i=0; i<size; i++)
		{
			if(A[i]%2==0)
			{
				while(A[i])
				{
					tmp=A[i]%10;
					A[i]/=10;
					if(tmp%2==0)
						num*=tmp;
				}
				A[i]=num;
			}
			num=1;			
		}
	}
	
}

int main()
{
	int i, countOdd=0, countEven=0, flag=0;
	int A[M];
	for(i=0; i<M; i++)
	{
		scanf("%d",A+i);
		if(abs(*(A+i)%2==0))
			countEven++;
		else
			countOdd++;
	}
	
	if(countEven > countOdd)	//if flag==1 -> заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи
		flag=1;
	else
		flag=0;					//if flag==0 -> заменить каждое чётное число на произведение чётных цифр в его десятичной записи. 
	
	prod(A, M, flag);
	
	for(i=0;i<M;i++)
		printf("%d ",A[i]);
		
	return 0;
}
