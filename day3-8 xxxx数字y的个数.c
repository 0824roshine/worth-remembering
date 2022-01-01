#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int j = 0, count = 0,c=0,n=0,k=10,num=0,time =0,i=0,c1=0; 
	int ar[10] = { 0 };// (1-10  1  , 1-100  20 , 1-10^n  =n*10^n)
	printf("输入___之内____出现的个数");
	scanf("%d %d", &c,&num);
	for (n = 1; c > k; k = 10 * k, n++);//判断n位数； 5
	{; }        // c=55678     k=100000 n=5
	if (num != 0)
	{
		if (k == num);
		count = n * k / 10;
		for (i = 0, c1 = c; i < n; i++)
		{
			ar[n - i - 1] = c1 % 10;
			c1 = c1 / 10;
		}
			for (j = 0, k = k / 100; j < n; j++, k = k / 10)
			{
				if (ar[j] < num)
					count = count + (ar[j]) * (n - j - 1) * k;
				else if (ar[j] = num)
					count = count + 1 + (ar[j]) * (n - j - 1) * k;
				else
					count = count + k * 100 + (ar[j]) * (n - j - 1) * k;
			}
	}
	else
	{
		printf("你问我零有几个，我懒得数了，换个数吧");
	}
	printf("%d", count);
	return 0;
}