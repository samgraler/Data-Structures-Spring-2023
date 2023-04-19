#pragma once
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>

// Sort Function Files
#include "Bubble.h"
#include "Insertion.h"
#include "Quick.h"
#include "Merge.h"
#include "Radix.h" // counting is included in radix

using namespace std;

void MakeArrays(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int *arr6, int n1, int n2, int n3, int n4, int n5, int n6)
{
	srand(time(NULL));

	// populate arrays with random numbers
	for (int i = 0; i < n1; i++)
	{
		arr1[i] = rand() % 21;
	}
	for (int i = 0; i < n2; i++)
	{
		arr2[i] = rand() % 201;
	}
	for (int i = 0; i < n3; i++)
	{
		arr3[i] = rand() % 1001;
	}
	for (int i = 0; i < n4; i++)
	{
		arr4[i] = rand() % 10001;
	}
	for (int i = 0; i < n5; i++)
	{
		arr5[i] = rand() % 50001;
	}
	for (int i = 0; i < n6; i++)
	{
		arr6[i] = rand() % 100001;
	}
}

// Function to print array
void PrintArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void TimeTaken(int *arr, int n, int sortType)
{
	clock_t start, end;
	start = clock();
	switch (sortType)
	{
	case 1:
		BubbleSort(arr, n);
		break;
	case 2:
		InsertionSort(arr, n);
		break;
	case 3:
		QuickSort(arr, 0, n - 1);
		break;
	case 4:
		MergeSort(arr, 0, n - 1);
		break;
	case 5:
		CountingSort(arr, n);
		break;
	case 6:
		RadixSort(arr, n);
		break;
	default:
		cout << "Invalid Sort Type" << endl;
		break;
	}
	end = clock();
	cout << "Time taken to sort " << n << " elements: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds" << endl;
}

int main()
{
	// initialize arrays to be sorted
	int arr1[10];
	int arr2[100];
	int arr3[500];
	int arr4[5000];
	int arr5[25000];
	int arr6[100000];

	// // populate arrays with random numbers
	// MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	// // Bubble Sort Arrays and print time taken to sort each array
	// cout << "Bubble Sort:" << endl; // Finished Bubble Sort
	// for (int i = 0; i < 6; i++)
	// {
	// 	cout << "Array " << i + 1 << ": ";
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		TimeTaken(arr1, 10, 1);
	// 		break;
	// 	case 1:
	// 		TimeTaken(arr2, 100, 1);
	// 		break;
	// 	case 2:
	// 		TimeTaken(arr3, 500, 1);
	// 		break;
	// 	case 3:
	// 		TimeTaken(arr4, 5000, 1);
	// 		break;
	// 	case 4:
	// 		TimeTaken(arr5, 25000, 1);
	// 		break;
	// 	case 5:
	// 		TimeTaken(arr6, 100000, 1);
	// 		break;
	// 	default:
	// 		cout << "Invalid Array" << endl;
	// 		break;
	// 	}
	// }

	// cout << endl;

	// MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	// cout << "Insertion Sort:" << endl; // Finished Insertion Sort
	// for (int i = 0; i < 6; i++) 
	// {
	// 	cout << "Array " << i + 1 << ": ";
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		TimeTaken(arr1, 10, 2);
	// 		break;
	// 	case 1:
	// 		TimeTaken(arr2, 100, 2);
	// 		break;
	// 	case 2:
	// 		TimeTaken(arr3, 500, 2);
	// 		break;
	// 	case 3:
	// 		TimeTaken(arr4, 5000, 2);
	// 		break;
	// 	case 4:
	// 		TimeTaken(arr5, 25000, 2);
	// 		break;
	// 	case 5:
	// 		TimeTaken(arr6, 100000, 2);
	// 		break;
	// 	default:
	// 		cout << "Invalid Array" << endl;
	// 		break;
	// 	}
	// }

	// cout << endl;

	// MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	// cout << "Quick Sort:" << endl; // Finished Quick Sort
	// for (int i = 0; i < 6; i++)
	// {
	// 	cout << "Array " << i + 1 << ": ";
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		cout << endl;
	// 		TimeTaken(arr1, 10, 3);
	// 		break;
	// 	case 1:
	// 		TimeTaken(arr2, 100, 3);
	// 		break;
	// 	case 2:
	// 		TimeTaken(arr3, 500, 3);
	// 		break;
	// 	case 3:
	// 		TimeTaken(arr4, 5000, 3);
	// 		break;
	// 	case 4:
	// 		TimeTaken(arr5, 25000, 3);
	// 		break;
	// 	case 5:
	// 		TimeTaken(arr6, 100000, 3);
	// 		break;
	// 	default:
	// 		cout << "Invalid Array" << endl;
	// 		break;
	// 	}
	// }

	// cout << endl;

	// MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	// cout << "Merge Sort:" << endl; // Finished Merge Sort
	// for (int i = 0; i < 6; i++)
	// {
	// 	cout << "Array " << i + 1 << ": ";
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		cout << endl;
	// 		TimeTaken(arr1, 10, 4);
	// 		break;
	// 	case 1:
	// 		TimeTaken(arr2, 100, 4);
	// 		break;
	// 	case 2:
	// 		TimeTaken(arr3, 500, 4);
	// 		break;
	// 	case 3:
	// 		TimeTaken(arr4, 5000, 4);
	// 		break;
	// 	case 4:
	// 		TimeTaken(arr5, 25000, 4);
	// 		break;
	// 	case 5:
	// 		TimeTaken(arr6, 100000, 4);
	// 		break;
	// 	default:
	// 		cout << "Invalid Array" << endl;
	// 		break;
	// 	}
	// }

	// cout << endl;

	// MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	// cout << "Counting Sort" << endl; // Finished Counting Sort
	// for (int i = 0; i < 6; i++)
	// {
	// 	cout << "Array " << i + 1 << ": ";
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		TimeTaken(arr1, 10, 5);
	// 		break;
	// 	case 1:
	// 		TimeTaken(arr2, 100, 5);
	// 		break;
	// 	case 2:
	// 		TimeTaken(arr3, 500, 5);
	// 		break;
	// 	case 3:
	// 		TimeTaken(arr4, 5000, 5);
	// 		break;
	// 	case 4:
	// 		TimeTaken(arr5, 25000, 5);
	// 		break;
	// 	case 5:
	// 		TimeTaken(arr6, 100000, 5);
	// 		break;
	// 	default:
	// 		cout << "Invalid Array" << endl;
	// 		break;
	// 	}
	// }

	// cout << endl;

	MakeArrays(arr1, arr2, arr3, arr4, arr5, arr6, 10, 100, 500, 5000, 25000, 100000);

	cout << "Radix Sort" << endl;
	for (int i = 0; i < 1; i++)
	{
		cout << "Array " << i + 1 << ": ";
		switch (i)
		{
		case 0:
			PrintArray(arr1, 10);
			TimeTaken(arr1, 10, 6);
			PrintArray(arr1, 10);
			break;
		case 1:
			TimeTaken(arr2, 100, 6);
			break;
		case 2:
			TimeTaken(arr3, 500, 6);
			break;
		case 3:
			TimeTaken(arr4, 5000, 6);
			break;
		case 4:
			TimeTaken(arr5, 25000, 6);
			break;
		case 5:
			TimeTaken(arr6, 100000, 6);
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}

	return 0;
}