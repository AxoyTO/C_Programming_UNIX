#include <stdio.h>

int areParenthesesCorrect(char c)
{
	int count,t;
	count=0;
	while(c!='.')
	{
		if(count<0)
			break;
		t++;
		if(c=='(')
			count++;
		else if (c==')')
			count--;
		scanf("%c",&c);
	}

		if(count==0)
			return 1;
		else
			return 0;
}

int main()
{
	char c;
	scanf("%c",&c);
	if(areParenthesesCorrect(c))
		printf("YES");
	else
		printf("NO");
	return 0;
}
