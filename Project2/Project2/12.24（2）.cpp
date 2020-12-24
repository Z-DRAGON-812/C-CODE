#include<stdio.h>
int main()
{
	int input=0;
	printf("你要好好学习吗？(1/0)=");
	scanf_s("%d", &input);
	if (input == 1)
		printf("走上人生巅峰");
	else
		printf("捡垃圾");
	


	return 0;
}