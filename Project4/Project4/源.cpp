#include<stdio.h>
int main()
{
	int a;
	scanf_s("%d", &a);
	if (a % 2 == 0)
		printf("%d��ż��", a);
	else
		printf("%d������", a);
	return 0;


}