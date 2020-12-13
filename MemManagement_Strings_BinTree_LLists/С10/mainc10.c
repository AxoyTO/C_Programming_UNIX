#include <stdio.h>
#include <math.h>

struct vector{
	double x;
	double y;
	double z;
};

double cos_angle_vectors(struct vector *a, struct vector *b)	//cosTheta = (a*b)/(|a||b|)
{
	double t, rootA, rootB, cosin;
	t = (a->x)*(b->x)+(a->y)*(b->y)+(a->z)*(b->z);
	rootA = sqrt((a->x)*(a->x)+(a->y)*(a->y)+(a->z)*(a->z));
	rootB = sqrt((b->x)*(b->x)+(b->y)*(b->y)+(b->z)*(b->z));
	cosin = t/(rootA*rootB);
	
	return cosin;
}

int main()
{
	struct vector a,b;
	int count=1;
	double n;
	
	while(count<=6)
	{
		scanf("%lf", &n);
		switch (count)
		{
			case 1:
				a.x=n;
				break;
			case 2:
				a.y=n;
				break;
			case 3:
				a.z=n;
				break;
			case 4:
				b.x=n;
				break;
			case 5:
				b.y=n;
				break;
			case 6:
				b.z=n;
				break;
			default:
				break;
		}
		count++;
	}
	
	if((a.x==0 && a.y==0 && a.z==0) || (b.x==0 && b.y==0 && b.z==0))
		printf("-2");
	else
		printf("%lf", cos_angle_vectors(&a, &b));
	
	return 0;
	
}
