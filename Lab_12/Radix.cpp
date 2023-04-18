#include "Radix.h"

void RadixSort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        // CountingSort(arr, n, exp);
    }
}
