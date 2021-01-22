#include<stdio.h>
int main()
{
	int w = 1;
	int t = 1;
	int r = 1;
	int sum = 0;
	for (t = 1; t <= 10; t++)
	{
		for (w=1,r=1; w <=t; w++)
		{
			r = r * w;
		}
		sum = sum + r;
	}
	printf("sum=%d", sum);
	
	return 0;
}