#include <stdio.h>

int main()
{
		int sum=0, realSum=0, num=1, min=0, max=0, count=0;
		
		while(num!=0)
		{
			scanf("%d",&num);
			if(num!=0)
				count++;
			if(count==1)
				min=num;
			if(num>=max)
				max=num;
			if(num<=min && num!=0)
				min=num;
			sum+=num;
		}
		
		realSum = (min+max)*(max-min+1)/2;
		
		// printf("count=%d	min=%d	max=%d	sum=%d	realSum=%d\n",count,min,max,sum,realSum);
		if(realSum-sum!=0)
			printf("%d",realSum-sum);
		return 0;
}
