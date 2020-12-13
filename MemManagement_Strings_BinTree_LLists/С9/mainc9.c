#include <stdio.h>
#include <string.h>

struct colour
{
	char name[20];
	int count;
};

void Print_colour(struct colour *p)
{
	printf("%s %d\n", p->name, p->count);
}

int main()
{
	struct colour white = {"WHITE", 0};
	struct colour black = {"BLACK", 0};
	struct colour other;

	char buf[20];

	strcpy(other.name, "OTHER");
	other.count = 0;
	
	while(scanf("%19s", buf) != EOF)
	{
		if(!strcmp(buf, white.name))
			white.count++;
		else if(!strcmp(buf, black.name))
			black.count++;
		else
			other.count++;
	}
	
	//printf("%s %d\n", white.name, white.count);
	//printf("%s %d\n", black.name, black.count);
	//printf("%s %d\n", other.name, other.count);	
	
	Print_colour(&white);
	Print_colour(&black);
	Print_colour(&other);
	
	return 0;
}
