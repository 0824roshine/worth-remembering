#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
int main()
{
	int arr[30][30] = { 0 }; int i = 0,j=0,n=0;
	memset(arr, 0, sizeof(arr) / sizeof(arr[0][0]));
	printf("请输入一个大于零的正整数：\n");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		arr[i][0] = 1;
	}
	printf("%6d\n", arr[0][0]);
	if (n > 1)
	{
		for (i = 1; i < n; i++)
		{
			for (j = 1; j <= i; j++)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			for (j = 0; j <= i; j++)
				printf("%6d ", arr[i][j]);
			printf("\n");
		}
	}
	return 0;
}