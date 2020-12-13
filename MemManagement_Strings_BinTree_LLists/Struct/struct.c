#include <stdio.h>
#include <string.h>

struct student
{
	char name[30];
	short age;
	float grade;
};

int main()
{
	int i;
	struct student st1;
	struct student st2={"First",20,4.5};
	
	st1.age=19;
	st1.grade=4;
	st2.age++;
	
	strcpy(st1.name, "Second");
}
