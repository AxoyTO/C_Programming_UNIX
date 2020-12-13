#include <stdio.h>
#include <stdlib.h>

int lengthStr(char *str)
{
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}

void formMatrix(char *str, int **A, int length)
{
	int i,j=0, s=0;

	//	printf("%d",*A[j]);

	for(i=0;i<length;i++)
	{
		if(str[i]-48>=0 && str[i]-48<=9)
		{
			s = i;
			//printf("%d\n",s);
			(*A)[j]=atoi(str+s);
			j++;
		}
		while(str[i]-48>=0 && str[i]-48<=9)
			i++;	
		
	}
}

void sortMatrix(int **A, int length)
{
	int i,j=0, tmp;
	for(i=0;i<length;i++)
		for(j=i+1;j<length;j++)
		{
			if((*A)[i]>(*A)[j])
			{
				tmp = (*A)[i];
				(*A)[i] = (*A)[j];
				(*A)[j]=tmp;
			}
		}
}

void printMatrix(int *A, int length)
{
	int i;
	for(i=0;i<length;i++)
		printf("%d ", A[i]);
}

/*void copyStr(char **str, char *fromStr)
{
	int i=0;
	while(fromStr[i]!='\0')
	{
		(*str)[i] = fromStr[i];
		i++;
	}
}*/

int main()
{
	char str[10000];
	//char *tmpStr=NULL;
	int *A=NULL;
	int i=0, count=0;
	int len=0;
	
/*	str = (char*)calloc(100,sizeof(char));
	if(str==NULL)
	{
		printf("ERROR1");
		exit(0);
	}
	*/
	scanf("%[^\n]s", str);
	len = lengthStr(str);
/*	str = (char*)realloc(str, (len+1)*sizeof(char));
	if(str==NULL)
	{
		printf("ERROR2");
		exit(0);
	}*/
	//copyStr(&str, tmpStr);
	//free(tmpStr);
	for(i=0;i<len;i++)
	{
		while(str[i]-48>=0 && str[i]-48<=9)
		{
			count++;
			if(str[i-1]-48>=0 && str[i-1]-48<=9)
				count--;
			i++;
		}
	}
//	printf("%d\n", count);
	
	A=(int*)malloc(count*sizeof(int));
	if(A==NULL)
	{
		printf("ERROR3");
		exit(0);
	}
	
	formMatrix(str, &A, len);
	sortMatrix(&A,count);
	printMatrix(A,count);
	
	//printf("%d", len);
	free(A);
//	free(str);
	return 0;

}
