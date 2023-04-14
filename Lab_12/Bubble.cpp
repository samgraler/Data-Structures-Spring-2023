#include "Bubble.h"

void bubbleSort(int *arr, int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n - 1; i++)
   {
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		// if no two elements were swapped 
		// by inner loop, then break
		if (swapped == false)
		break;
   }
}