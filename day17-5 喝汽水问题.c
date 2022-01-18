#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
.{
	int full = 0; int sum = 0; int bottle = 0;
	printf("一瓶汽水1元，2个空瓶子兑换一瓶，你有多少钱？\n");
	scanf("%d",&full);
	do
	{
		sum += full;
		bottle =bottle+ full;
		if (bottle <2)
			break;
		full = bottle / 2;
		bottle = bottle % 2;
		
	} while (1);
	printf("%d", sum);
	return 0;
}