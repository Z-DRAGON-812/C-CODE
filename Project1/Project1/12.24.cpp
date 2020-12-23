#include<stdio.h>
int main()
{
	int a, b, result;
	for (a = 1; a < 10; a++)
	{
		for (b = 1; b < 10; b++)
		{
			result = a * b;
			printf("%d*%d=%-7d", a, b, result);
		}
		printf("\n");
	}
	
}