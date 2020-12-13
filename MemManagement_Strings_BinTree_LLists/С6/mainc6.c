#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int indexStart, indexEnd, i, count=0, len;
	char str[10000], *move, *p;
	const char *start;
	const char ling[]="Ling";
	gets(str);
	start = str;
	move = str;
	
	len = strlen(str);
	while(1)
	{
		p = strstr(move, "Cao");
		if(p==NULL)
			break;
		count++;	
		move = p+3;
		indexStart = p-start;
		indexEnd = p-start+3;
		for(i=len+count; i>=indexEnd; i--)
		{
			str[i]=str[i-1];
		}
		strncpy(str+indexStart, ling, 4);
	}
	puts(str);
	return 0;
}
