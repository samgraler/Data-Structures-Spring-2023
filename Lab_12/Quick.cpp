#include "Quick.h"

void QuickSort(int* arr, int n)
{
	int pivot = 0;
	if (arr[0] < arr[n - 1] && arr[0] > arr[n / 2])
	{
		pivot = arr[0];
	}
	else if (arr[n / 2] < arr[0] && arr[n / 2] > arr[n-1])
	{
		pivot = arr[n/2];
	}
	else
	{
		pivot = arr[n - 1];
	}

	partition(arr, pivot);
}

void partition(int* arr, int pivot) // quick sort video we watched in class kind of
{
	int i = 0;
	int j = 0;
	int temp = 0;
	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
}