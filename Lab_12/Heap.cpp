#include "Heap.h"

void HeapSort(int arr[], int N)
{
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        heapify(arr, N, i);
    }
    for (int i = N - 1; i > 0; i--) {
        swaph(arr, 0, i); // Move current root to end (index 0 is the max value
        heapify(arr, i, 0); // fix heap and continue 
    }
}

// heapify a subtree with node i as the root (array size n)
void heapify(int* arr, int N, int i)
{
    // Initialize largest as root
    int largest = i;
    // left = 2*i + 1
    int l = 2 * i + 1;
    // right = 2*i + 2
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest]) 
    {
        largest = l;
    }
    if (r < N && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i) { // if largest is not root
        swaph(arr, i, largest);
        heapify(arr, N, largest); // heapify the subtree (largest is now the index of the root)
    }
}

// helper swap function
void swaph(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}