#include <stdio.h>

float sinus(float x)
{
	int i;
	float t,sum,tmp,eps=0.001;
	x=x*3.14/180;
	t=x;
	sum=x;
	tmp=x;

	for(i=1;tmp>eps;i++)
	{
		t = (t*(-1)*x*x)/(2*i*(2*i+1));
		sum = sum+t;
		if(t<0)
			tmp = -t;
		else
			tmp = t;

	//	printf("%f     %f      %f\n",t,tmp,sum);
	}

	return sum;
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("%.3f",sinus(a));
	return 0;
}
