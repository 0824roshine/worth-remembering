#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void 笨办法(char* a,int k,int sz)
{
	int i = 0; int j = 0;
	char b[100] = { '0' };
	for (i = 0; i < k; i++)
		b[i] = *(a+i);
	for (i = k; i < sz; i++)
		a[i - k] = a[i];
	for (i = sz - k ,j=0; i < sz;j++, i++)
		a[i] = b[j];
}
void reverse(char* arr1,char* arr2)
{
	char tmp = '0';
	while (arr1 < arr2)
	{
		tmp = *arr1;
		*arr1 = *arr2;
		*arr2 = tmp;
		arr1++;
		arr2--;
	}
}
void 三次倒转(char* a, int k, int sz)
{
	reverse(a, a + k - 1);
	reverse(a+k, a+sz - 1);
	reverse(a, a+sz - 1);
}
void 用库函数实现()
{
	;//strncat......strcat
}
int main()
{
	char a[256] = { '0' };
	gets(a);
	int k = 0; int sz = strlen(a);
	scanf("%d", &k);
	//笨办法(a,k,sz);
	三次倒转(a, k, sz);
	printf("%s", a);
	return 0;
}