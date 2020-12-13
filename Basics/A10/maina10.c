#include <stdio.h>

int main()
{
	int a,tmp;
	tmp=1;
	scanf("%d",&a);
	if(a>100)
		return -1;
	else
		while(tmp<=a)
			{
				printf("%d %d %d\n",tmp,tmp*tmp,tmp*tmp*tmp);
				tmp++;
			}
}
