#include <stdio.h>
#include <stdlib.h>

int lengthStr(char *str)
{
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
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
//	char *str2=NULL;
	int i=0, count=0, lmax=0, indexMax=0, tmp=0;
	int len=0;
	
/*	str = (char*)calloc(1000,sizeof(char));
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
	}
	*/
	for(i=0;i<len;i++)
	{
		if(str[i]==' ' || str[i+1]=='\0')
		{
			i++;
		//	printf("1st cycle\n");
		//	printf("i=%d , len=%d , lmax=%d , indexMax=%d\n", i, len, lmax, indexMax);
		//	printf("%c\n",str[i]);
			if(count>=lmax)
			{
				tmp=i-1;
				indexMax = i - count -1;
				if(str[i]!='\0')
					lmax = count;
				else
					lmax = count+1;
			}
			
			count=0;
		}
		count++;
	}
	
	//printf("!!!!!!!! TMP=%d !!!!!\n", tmp);
	count=0;
	
	for(i=0;i<len;i++)
	{
		if(i==tmp)
			count=0;
		else
		{
			if(str[i]==' ' || str[i+1]=='\0')
			{
				i++;
			//	printf("2nd cycle\n");
			//	printf("i=%d , len=%d , lmax=%d , indexMax=%d , count=%d\n", i, len, lmax, indexMax, count);
			//	printf("%c\n",str[i]);
				if(str[i+1]=='\0')
					count++;
				if(count==lmax)
				{
					//printf("exitting");
					exit(0);
				}
				
				count=0;
			}
			count++;
		}
	}
	
	for(i=0;i<len;i++)
	{
		if(i==indexMax)
			while(i!=indexMax+lmax)
			{
				printf("%c", str[i]);
				i++;
			}
	}
//	printf("i=%d , len=%d , lmax=%d , indexMax=%d , count=%d\n", i, len, lmax, indexMax, count);
	
//	free(str2);
//	free(str);
	return 0;

}

