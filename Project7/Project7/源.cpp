#include<stdio.h>
int main()
{ 
	int w = 1;
	int t = 1;
	int sum = 0;
	for (w = 1; w <= 10; w++)
	{
		t = t * w;
		sum = sum + t;
	}
	printf("sum=%d", sum);



	return 0;
}