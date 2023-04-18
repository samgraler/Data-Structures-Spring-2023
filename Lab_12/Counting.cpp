#include "Counting.h"

void CountingSort(int* arr, int n)
{
	int* temp = new int[n];
	int* count = new int[n];
	for (int i = 0; i < n; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	for (int i = 1; i < n; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		temp[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}