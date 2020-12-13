#include <stdio.h>
#include <stdlib.h>

void converseText(char **A, int size)
{
	int i,j=0, flag;
	char c;

	do{
		flag=0;
		for(i=0; i<size-1-j; i++)
		{
			if(((*A)[i]>='A' && (*A)[i]<='Z') && ((*A)[i+1]>='a' && (*A)[i+1]<='z'))
			{
				c = (*A)[i];
				(*A)[i]=(*A)[i+1];
				(*A)[i+1]=c;
				flag=1;
			}	
		}
		j++;
	}while(flag);
}

int main()
{
	char *A=NULL;
	char c;
	int len=1, i=0;

	A = (char*)malloc(len*sizeof(char));

	while(scanf("%c", &c)!=EOF)
	{
		A[i]=c;
		i++;
		char *TMP = NULL;
		if(i==len)
		{
			len += 1;
			TMP=(char*)realloc(A,(len)*sizeof(char));
			if(TMP==NULL)
			{
				free(A);
				exit(0);
			}
			else
				A = TMP;	
		}
	}

	//printf("\n length = %d\n", len);
	converseText(&A, len);
	for(i=0;i<len-1;i++)
		printf("%c", A[i]);

	free(A);
	A=NULL;
	return 0;

}
