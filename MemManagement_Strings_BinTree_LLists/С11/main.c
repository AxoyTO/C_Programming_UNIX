#include <stdio.h>
#include <string.h>
#define MAX 20
struct colour
{
    char name[20];
    int count;
};

int add_element(struct colour *colour, char *buf, int *num);

int main() {
    struct colour col[MAX];
    char buf[20];
    int num_colours = 0, i;
    char exist = 0;

    while(scanf("%19s", buf) != EOF)
    {
		puts(buf);
        exist = 0;
        for(i = 0; i< num_colours; i++)
        {
            if(strcmp(col[i].name, buf) == 0)
            {
                col[i].count++;
                exist = 1;
            }
        }
        if(!exist) {
            if(add_element(col+num_colours, buf, &num_colours))
                break;
 /*           if (num_colours >= MAX)
                break;
            strcpy(col[num_colours].name, buf);
            col[num_colours].count = 1;
            num_colours++;
 */
        }
    }

    for(i=0; i<num_colours; i++)
    {
        printf("%s %d\n", col[i].name, col[i].count);
    }
    return 0;
}

int add_element(struct colour *colour, char *buf, int *num)
{
    if(*num >= MAX)
        return 1;
    strcpy(colour->name, buf);
    colour->count=1;
    (*num)++;
    return 0;
}
