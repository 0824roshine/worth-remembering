#include<stdio.h>
void move(int arr[], int sz)
{
	int left = 0, right = sz - 1;
	while (left < right)
	{
		while((arr[left] % 2 == 1) && (left < right))
			left++;
		while (arr[right] % 2 == 0)
			right--;
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}	
}

int main()
{
	int arr[] = { 1,1,2,3,5,8,13,21,34,55 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	for (int j = 0; j < sz; j++)
		printf("%d ", arr[j]);
	return 0;
}