#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(char * str);
void removeAll(char *str, char c, int index);
void removeSpaces(char *s);

void removeDuplicates(char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        removeAll(str, str[i], i + 1);
        i++;
    }
}

void removeAll(char *str, char c, int index)
{
    int i;

    while(str[index] != '\0')
    {
        if(str[index] == c)
        {
            i = index;
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        }
        else
        {
            index++;
        }
    }
}
void removeSpaces(char *s) {
    char *t = s;
    do {
		
        while (*t == ' ')
            t++;
     
    } while (*s++ = *t++);
}

int main()
{
	char str[10000];
	gets(str);
	
	removeDuplicates(str);
	removeSpaces(str);

	puts(str);

	return 0;
}
     
