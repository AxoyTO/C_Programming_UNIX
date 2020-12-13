#include <stdio.h>
#include <stdlib.h>

void removeExtraSpaces(char *str)
{
	int i, x=0;
	for(i=0; str[i]; ++i)
	{
		if(str[i]!=' ' || (i > 0 && (str[i-1])!=' '))
		{
			str[x] = str[i];
			x++;
		}
	}
	
	if(str[x-1]==' ')
		str[x-1] = '\0';
	else
		str[x] = '\0';
}

int main()
{
	char str[10000];
	gets(str);
	removeExtraSpaces(str);
//	int len = strlen(str);
//	printf("%d\n", len);
	puts(str);
	free(str);
	return 0;
}
