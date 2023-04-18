#include "Quick.h"

void QuickSort(int *arr, int n)
{
	int pivot;
	int fromleft = 0;
	int fromright = n - 2;
	int temp;
	// base case
	if (n <= 1)
	{
		return;
	}
	
	if (arr[0] < arr[n - 1] && arr[0] > arr[n / 2])
	{
		pivot = 0;
	}
	else if (arr[n / 2] < arr[0] && arr[n / 2] > arr[n - 1])
	{
		pivot = n / 2;
	}
	else
	{
		pivot = n - 1;
	}

	// Put pivot at the end of the array
	temp = arr[pivot];
	arr[pivot] = arr[n-1];
	arr[n-1] = temp;

	while (fromleft < fromright)
	{
		while (arr[fromleft] < arr[n - 1])
		{
			fromleft++;
		}
		while (arr[fromright] > arr[n - 1])
		{
			fromright--;
		}
		if (fromleft < fromright)
		{
			temp = arr[fromleft];
			arr[fromleft] = arr[fromright];
			arr[fromright] = temp;
		}
	}
	// swap fromleft and pivot
	temp = arr[fromleft];
	arr[fromleft] = arr[n - 1];
	arr[n - 1] = temp;

	// get sub arrays and call quicksort on them

	// Left sub array
	// make sure left sub array is not empty
	if (fromleft > 0)
	{
		QuickSort(arr, fromleft);
	}

	// Right sub array
	// make sure right sub array is not empty
	if (fromleft < n - 1)
	{
		int* SubArray = new int[n - fromleft - 1]; // n - fromleft - 1 is the size of the right sub array

		for (int i = fromleft + 1; i < (n - fromleft - 1); i++) // grab elements from main array
		{
			SubArray[i] = arr[i + fromleft + 1];
		}

		QuickSort(SubArray, n - fromleft - 1); // sort right sub array

		for (int i = fromleft + 1; i < (n - fromleft - 1); i++) // replace elements in main array with sorted right sub array
		{
			arr[i + fromleft + 1] = SubArray[i];
		}
		delete[] SubArray; // clean up memory
	}
}