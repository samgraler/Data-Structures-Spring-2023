#pragma once
#include <iomanip>
#include <random>
#include <time.h>
#include <chrono>
#include <vector>
#include "LinkedList.cpp"
#include "Student.h"

// Sort Function Files
#include "Bubble.h"
#include "Insertion.h"
#include "Quick.h"
#include "Merge.h"
#include "Radix.h" // counting is included in radix
#include "Heap.h"

using namespace std;
typedef chrono::high_resolution_clock Clock;

void MakeArrays(int* arr, int seed, int choice)
{
	srand(seed);
	// populate given array with random numbers accoring to the size of the array (indicated by choice)
	switch(choice){
		case 0:
			for (int i = 0; i < 10; i++)
			{
				arr[i] = rand() % 21;
			}
			break;
		case 1:
			for (int i = 0; i < 100; i++)
			{
				arr[i] = rand() % 201;
			}
			break;
		case 2:
			for (int i = 0; i < 500; i++)
			{
				arr[i] = rand() % 1001;
			}
			break;
		case 3:
			for (int i = 0; i < 5000; i++)
			{
				arr[i] = rand() % 10001;
			}
			break;
		case 4:
			for (int i = 0; i < 25000; i++)
			{
				arr[i] = rand() % 50001;
			}
			break;
		case 5:
			for (int i = 0; i < 100000; i++)
			{
				arr[i] = rand() % 200001;
			}
			break;
		default:
			break;
	}
}

// Function to print an array
void PrintArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	
}

// print the 2d array that holds the times
void PrintResults(long long arr[7][6])
{
	cout << "Time in Nanoseconds" << endl;
	cout << "Sizes:\t"  << "\t";
	for (int j = 0; j < 6; j++) {
			switch (j) {
			case 0:
				cout << "10\t";
				break;
			case 1:
				cout << "100\t";
				break;
			case 2:
				cout << "500\t";
				break;
			case 3:
				cout << "5000\t\t";
				break;
			case 4:
				cout << "25000\t\t";
				break;
			case 5:
				cout << "100000\t\t";
				break;
			default:
				break;
			}
		}
	cout << endl << endl;
	for (int i = 0; i < 7; i++) {

		switch (i) {
		case 0:
			cout << "Bubble Sort: " << "\t";
			break;
		case 1:
			cout << "Insert Sort: " << "\t";
			break;
		case 2:
			cout << "Quick Sort: " << "\t";
			break;
		case 3:	
			cout << "Merge Sort: " << "\t";
			break;	
		case 4:
			cout << "Count Sort: " << "\t";
			break;
		case 5:
			cout << "Radix Sort: " << "\t";
			break;
		case 6:
			cout << "Heap Sort: " << "\t";
			break;
		default:
			break;
		}
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << "\t";
			if (j > 2 && arr[i][j] < 9999999) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

// function to call / time bubble sort
auto Bubble(int* arr, int n)
{
	auto t1 = Clock::now();
	BubbleSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time insertion sort
auto Insertion(int* arr, int n)
{
	auto t1 = Clock::now();
	InsertionSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time quick sort
auto Quick(int* arr, int n)
{
	
	auto t1 = Clock::now();
	QuickSort(arr, 0, n - 1);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time merge sort
auto Merge(int* arr, int n)
{
	auto t1 = Clock::now();
	MergeSort(arr, 0, n - 1);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time counting sort
auto Count(int* arr, int n)
{
	
	auto t1 = Clock::now();
	CountingSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time radix sort
auto Radix(int* arr, int n)
{
	
	auto t1 = Clock::now();
	RadixSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// function to call / time heap sort
auto Heap(int* arr, int n)
{
	
	auto t1 = Clock::now();
	HeapSort(arr, n);
	auto t2 = Clock::now();
	return(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
}

// DRIVER FOR TASK 1
void main1()
{
	// initialize arrays to be sorted
	int *arr1 = new int[10];
	int *arr2 = new int[100];
	int *arr3 = new int[500];
	int *arr4 = new int[5000];
	int *arr5 = new int[25000];
	int *arr6 = new int[100000];

	long long results[7][6] = { 0 };

	int seed = time(NULL);
	long long averagetime = 0;

	// loop through each array size and call bubble sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
			case 0:
				for (int i = 0; i < 11; i++) // each for loop opertes in the same format
				{
					MakeArrays(arr1, seed, 0); // populate the array with random values to be sorted
					averagetime += Bubble(arr1, 10); // call the respective sort function one time and add the time to the running count
				}
				results[0][0] = averagetime / 10; // calculate the average and store it in a 2D array
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Bubble(arr2, 100);
				}
				results[0][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Bubble(arr3, 500);
				}
				results[0][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Bubble(arr4, 5000);
				}
				results[0][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Bubble(arr5, 25000);
				}
				results[0][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Bubble(arr6, 100000);
				}
				results[0][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}

	// loop through each array size and call insertion sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++) 
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr1, seed, 0);
				averagetime += Insertion(arr1, 10);
			}
			results[1][0] = averagetime / 10;
			break;
		case 1:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr2, seed, 1);
				averagetime += Insertion(arr2, 100);
			}
			results[1][1] = averagetime / 10;
			break;
		case 2:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr3, seed, 2);
				averagetime += Insertion(arr3, 500);
			}
			results[1][2] = averagetime / 10;
			break;
		case 3:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr4, seed, 3);
				averagetime += Insertion(arr4, 5000);
			}
			results[1][3] = averagetime / 10;
			break;
		case 4:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr5, seed, 4);
				averagetime += Insertion(arr5, 25000);
			}
			results[1][4] = averagetime / 10;
			break;
		case 5:
			for (int i = 0; i < 11; i++)
			{
				MakeArrays(arr6, seed, 5);
				averagetime += Insertion(arr6, 100000);
			}
			results[1][5] = averagetime / 10;
			break;
		default:
			cout << "Invalid Array" << endl;
			break;
		}
	}
	
	// loop through each array size and call quick sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
			case 0:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr1, seed, 0);
					averagetime += Quick(arr1, 10);
				}
				results[2][0] = averagetime / 10;
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Quick(arr2, 100);
				}
				results[2][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Quick(arr3, 500);
				}
				results[2][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Quick(arr4, 5000);
				}
				results[2][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Quick(arr5, 25000);
				}
				results[2][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Quick(arr6, 100000);
				}
				results[2][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}

	// loop through each array size and call merge sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr1, seed, 0);
					averagetime += Merge(arr1, 10);
				}
				results[3][0] = averagetime / 10;
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Merge(arr2, 100);
				}
				results[3][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Merge(arr3, 500);
				}
				results[3][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Merge(arr4, 5000);
				}
				results[3][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Merge(arr5, 25000);
				}
				results[3][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Merge(arr6, 100000);
				}
				results[3][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}
	 // loop through each array size and call counting sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr1, seed, 0);
					averagetime += Count(arr1, 10);
				}
				results[4][0] = averagetime / 10;
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Count(arr2, 100);
				}
				results[4][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Count(arr3, 500);
				}
				results[4][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Count(arr4, 5000);
				}
				results[4][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Count(arr5, 25000);
				}
				results[4][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Count(arr6, 100000);
				}
				results[4][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}

	// loop through each array size and call radix sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr1, seed, 0);
					averagetime += Radix(arr1, 10);
				}
				results[5][0] = averagetime / 10;
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Radix(arr2, 100);
				}
				results[5][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Radix(arr3, 500);
				}
				results[5][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Radix(arr4, 5000);
				}
				results[5][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Radix(arr5, 25000);
				}
				results[5][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Radix(arr6, 100000);
				}
				results[5][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}
	 // loop through each array size and call heap sort 10 times on each size to get an average time for each size
	for (int i = 0; i < 6; i++)
	{
		averagetime = 0;
		switch (i)
		{
		case 0:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr1, seed, 0);
					averagetime += Heap(arr1, 10);
				}
				results[6][0] = averagetime / 10;
				break;
			case 1:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr2, seed, 1);
					averagetime += Heap(arr2, 100);
				}
				results[6][1] = averagetime / 10;
				break;
			case 2:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr3, seed, 2);
					averagetime += Heap(arr3, 500);
				}
				results[6][2] = averagetime / 10;
				break;
			case 3:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr4, seed, 3);
					averagetime += Heap(arr4, 5000);
				}
				results[6][3] = averagetime / 10;
				break;
			case 4:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr5, seed, 4);
					averagetime += Heap(arr5, 25000);
				}
				results[6][4] = averagetime / 10;
				break;
			case 5:
				for (int i = 0; i < 11; i++)
				{
					MakeArrays(arr6, seed, 5);
					averagetime += Heap(arr6, 100000);
				}
				results[6][5] = averagetime / 10;
				break;
			default:
				cout << "Invalid Array" << endl;
				break;
		}
	}

	// output results
	PrintResults(results);
}

// DRIVER FOR TASK 3 
void main2()
{
	// initialize vectors that hold names for the students
	vector<string> firstNames = { "Emma", "Olivia", "Ava", "Isabella", "Sophia", "Mia", "Charlotte", "Amelia", "Harper", "Evelyn", "Abigail", "Emily", "Elizabeth", "Mila", "Ella", "Avery", "Sofia", "Camila", "Aria", "Scarlett", "Victoria", "Madison", "Luna", "Grace", "Chloe", "Penelope", "Layla", "Riley", "Zoey", "Nora", "Lily", "Eleanor", "Hannah", "Lillian", "Addison", "Aubrey", "Ellie", "Stella", "Natalie", "Zoe", "Leah", "Hazel", "Violet", "Aurora", "Savannah", "Audrey", "Brooklyn", "Bella", "Randy", "Sam" };
	vector<string> lastNames = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "King", "Wright", "Scott", "Green", "Baker", "Adams", "Nelson", "Carter", "Mitchell", "Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart", "Sanchez", "Morris", "Rogers" };

	Student *s;
	LinkedList<Student>* list = new LinkedList<Student>();
	for (int i = 0; i < 50; i++) // create 50 students with the names from the vectors and a random mnumber 
	{
		s = new Student(firstNames[0], lastNames[0], (rand() % 9999999) + 10000000);
		list->AddItem(s);
		firstNames.erase(firstNames.begin());
		lastNames.erase(lastNames.begin());
	}

	// output the original (unsorted) list
	cout << "Unsorted List: " << endl;
	list->Print();

	// get the user input for the sorting algorithm, key, and order
	char algorithm, order;
	int key = 0;
	cout << "Select the sorting algorithm: " << endl;
	cout << "(1) Bubble Sort" << endl;
	cout << "(2) Insertion Sort" << endl;
	cout << "(3) Heap Sort" << endl;
	cout << "> ";
	cin >> algorithm;
	cout << endl;
	cout << "Select the key: " << endl;
	cout << "(1) First Name" << endl;
	cout << "(2) Last Name" << endl;
	cout << "(3) MNumber" << endl;
	cout << "> ";
	cin >> key;
	cout << endl;
	cout << "Select the order: " << endl;
	cout << "(1) Ascending" << endl;
	cout << "(2) Descending" << endl;
	cout << "> ";
	cin >> order;

	bool ascending = true;
	if (order == '2')
	{
		ascending = false;
	}
	// call the proper sort with the right key and ascending order
	switch (algorithm)
	{
		case '1':
			list->BubbleSort(key, ascending);
			break;
		case '2':
			list->InsertionSort(key, ascending);
			break;
		case '3':
			list->HeapSort(key, ascending);
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
	// output the sorted version of the list
	cout << endl << "Sorted List: " << endl;
	list->Print();
}

int main() {
	string choice = "";
	while (choice != "3") { // ask the use whether they want to test task 1 or task 3
		cout << "Which driver would you like to run?" << endl;
		cout << "(1) Sorting Algorithms" << endl; // task 1
		cout << "(2) LinkedList Sorting" << endl; // task 3
		cout << "(3) Exit" << endl;
		cout << "> ";
		cin >> choice;
		cout << endl;
		if (choice == "1") {
			main1(); // run task 1 driver
		}
		else if (choice == "2") {
			main2(); // run task 2 driver
		}
		else if (choice == "3") {
			return 0;
		}
		else {
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
}