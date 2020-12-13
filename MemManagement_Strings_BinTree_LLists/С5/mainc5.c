#include <stdio.h>
#include <stdlib.h>


int cmpStr(char *str1, char *str2)
{
	int val;
	while(*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}

	val = *str1 - *str2;
	
		return val;
}

int lengthStr(char *str)
{
	char *p = str;
	while(*p)
		p++;
		
	return p-str;
}

void copyStr(char *str1, char *str2)
{
	while(*str1++ = *str2++);
	
}

void sortStrings(char str[1000][1000], int count)
{
	int i=0, j;
	char tmp[1000];
	
	for(i=0; i<count-1; i++)
	{
		for(j=i+1; j<count; j++)
		{
			if(cmpStr(str[i],str[j]) > 0)
			{
				copyStr(tmp, str[i]);
				copyStr(str[i],str[j]);
				copyStr(str[j],tmp);
			}
		}
	}
}

int main()
{
    char str[10000];
    char splitStr[1000][1000];
    int i, j=0, count=0;
 
    gets(str);
	int len = lengthStr(str);

    for(i=0;i<len+1;i++)
    {
        
        if(str[i]==' ' || str[i] == '\0')
        {
			splitStr[count][j]='\0';
			while(str[i+1]==' ' || str[i+1]=='\0')
				i++;
            count++;
            j=0;
        }
        else
        {
            splitStr[count][j]=str[i];
            j++;
        }
    }
 
	//printf("%d\n", count);
	sortStrings(splitStr, count);
	//removeSpaces(splitStr);
	//printf("%d\n", cmpStr("a","A"));
    for(i=0; i<count;i++)
    {
		if(splitStr[i][0]!='\0' && splitStr[i][0]!=' ')
        puts(splitStr[i]);
	}    
    return 0;
    
    
}
