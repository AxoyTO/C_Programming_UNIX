#include <stdio.h>

int main()
{
	int month,day,totalDays;
	scanf("%d %d",&month,&day);
	switch(month)
	{
	case 1:
		totalDays=day;
		break;
	case 3:
		totalDays = 29+31+day;
		break;
	case 5:
		totalDays = 29+30+(31*2)+day;
		break;
	case 7:
		totalDays = 29+(30*2)+(31*3)+day;
		break;
	case 8:
		totalDays = 29+(31*4)+(30*2)+day;
		break;
	case 10:
		totalDays = 29+(31*5)+(30*3)+day;
		break;
	case 12:
		totalDays = 29+(31*6)+(30*4)+day;
		break;
	case 2:
		totalDays = 31+day;
		break;
	case 4:
		totalDays = 29+(2*31)+day;
		break;
	case 6:
		totalDays = 29+30+(31*3)+day;
		break;
	case 9:
		totalDays = 29+(30*2)+(31*5)+day;
		break;
	case 11:
		totalDays = 29+(30*3)+(31*6)+day;
		break;
	
	}
	printf("%d",366-totalDays);
	return 0;
}
