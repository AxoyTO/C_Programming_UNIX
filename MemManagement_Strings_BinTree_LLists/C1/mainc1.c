#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthStr(char *str)
{
	char *p = str;
	while(*p)
		p++;
		
	return p-str;
}

int main()
{
	char *str;
	int S=0, L=0, i=0;
	str=(char*)calloc(10000, sizeof(char));
	if(str==NULL)
	{
		printf("ERROR");
		exit(0);
	}

	scanf("%[^\n]s", str);
	int len = lengthStr(str);
	
	str=(char*)realloc(str, (len+1)*sizeof(char));
	if(str==NULL)
	{
		printf("ERROR");
		exit(0);
	}

	while(str[i]!='\0')
	{
			if(str[i]>='A' && str[i]<='Z')
				L++;
			
			if(str[i]>='a' && str[i]<='z')
				S++;
		i++;
	}
	printf("%d %d", S, L);
	
	free(str);
	return 0;
}
