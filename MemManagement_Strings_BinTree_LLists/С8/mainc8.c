#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrom(char s[])
{
	int flag=1, odd=0, k=0, i=0, j=0, count=0, size=0;
	int *M = NULL;
	char save[10000];
	strcpy(save, s);
	char *tmp = s;
	char c;		
	int len = strlen(s);
	
	for(i=0; i<len; i++)
	{
		c = *(tmp+i);
		if(c!='.')
			size++;
		for(j=i+1; j<len; j++)
		{
			if(*(tmp+i)=='.')
				break;
			if(*(tmp+j) == c)
				*(tmp+j)='.';
		}
	}
	M = (int*)malloc(size*sizeof(int));
	if(M==NULL)
		exit(1);

	strcpy(s, save);
	tmp = s;
	for(i=0; i<len; i++)
	{
		c = *(tmp+i);
		count++;
		for(j=i+1; j<len; j++)
		{
			if(*(tmp+i)=='.')
				break;
			if(*(tmp+j)==c)
			{
				count++;
				*(tmp+j)='.';
			}
		}	
		//puts(tmp);
		
	//	printf("%d\n", count);
		
		while(k<len && *(tmp+i)!='.')
		{
			*(M+k) = count;
			k++;
			break;
		}
		count=0;
	}
	
	for(i=0;i<size;i++)
	{
		if(*(M+i)%2==1)
			odd++;
	}
	
	if(odd>1)
		flag=0;
	else
		flag=1;
	
	return flag;
}

void removeSpaces(char *s)
{
	char *p = s;
	do{
		while(*p == ' ')
			p++;
					
	}while(*s++ = *p++);
	
}

int main()
{
	int boole;
	char str[10000];
	gets(str);
	removeSpaces(str);
	boole=is_palindrom(str);
	if(str[0]!='\0')
	{
		if(boole==1)
			printf("YES");
		else
			printf("NO");
	}
	else
		printf("NO");
	
	return 0;
}
