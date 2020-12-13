#include <stdio.h>
#include <stdlib.h>


void Howmany (char *c)
{
	int i=0, j=0, k=0;
	while (c[i]!='\0')
	{
		if (c[i]>='A'&& c[i]<= 'Z')
			k++;
		else if (c[i]>='a' && c[i]<= 'z')
			j++;
		i++;
	}
printf ("%d %d", j, k);

}

int main(){
	char *arr,*b;
	int num = 10, i=0;
	arr = (char*)malloc(num*sizeof(char));
	
	if (arr==NULL){
		printf("-1");
		exit (0);
	}
	while (scanf ("%c", &arr[i])!= EOF)
	{
		i++;
		if (i == num)
		{
			char *a=NULL;
			num*=2;
			a = (char*)realloc(arr, num*sizeof(char));
			if (a==NULL)
			{
				free (arr);
				printf("-1");
				exit (0);
			}
		else
			arr=a;
		}
	}
	b=(char*)realloc(arr,i*sizeof(char));
	if (b==NULL)
	{
		printf("-1");
		exit (0);
	}
	else
		arr=b;
	
	Howmany(arr);
	return 0;
}
