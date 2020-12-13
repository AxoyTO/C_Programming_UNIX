#include <stdio.h>

int main()
{
	char c;
	do{
		scanf("%c",&c);
		
		if(c==' ')
		{
			while(c==' ')
			{
				scanf("%c",&c);
			}
			if(c=='.')
				break;
			printf(" ");
			printf("%c",c);
		}
		else
		{
			if(c=='.')
				break;
			printf("%c",c);
		}
	}while(c!='.');
	return 0;
}
