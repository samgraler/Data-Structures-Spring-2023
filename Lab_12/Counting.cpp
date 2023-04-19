#include "Counting.h"

void CountingSort(int* arr, int n)
{
	int *count, *temp;
	int max = arr[0];
	for (int i = 1; i < n; i++) // find max value in array
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	count = new int[max + 1]; // creates a count array for each value in the original array
	temp = new int[n];
	for (int i = 0; i <= max; i++) // initialize count array to all 0's
	{
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) // gets counts 
	{
		count[arr[i]]++;
	}
	for (int i = 1; i <= max; i++) // get cummulative counts
	{
		count[i] += count[i - 1];
	}
	for (int i = 0; i < n; i++) // create sorted array
	{
		temp[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < n; i++) // copy sorted array to original array
	{
		arr[i] = temp[i];
	}
	delete[] temp;
}


void CountingSort(int* arr, int n, int exp)
{
    int *output = new int[n]; // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
