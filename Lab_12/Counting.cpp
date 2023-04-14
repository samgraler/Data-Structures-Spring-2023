#include "Counting.h"

void CountingSort(int* arr, int n) {
	int i, j;
	int count[100001] = {0};
	int temp[100000];
	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	for (i = 1; i <= 100000; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		temp[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}