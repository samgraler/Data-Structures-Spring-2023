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
#include "Radix.h"
#include "Counting.h"

using namespace std;

int main() {

	// initialize arrays to be sorted
	int arr1[10];
	int arr2[100];
	int arr3[500];
	int arr4[5000];
	int arr5[25000];
	int arr6[100000];

	srand(time(NULL));
	
	// populate arrays with random numbers
	for (int i = 0; i < 10; i++) {
		arr1[i] = rand() % 21;
	}
	for (int i = 0; i < 100; i++) {
		arr2[i] = rand() % 201;
	}
	for (int i = 0; i < 500; i++) {
		arr3[i] = rand() % 1001;
	}
	for (int i = 0; i < 5000; i++) {
		arr4[i] = rand() % 10001;
	}
	for (int i = 0; i < 25000; i++) {
		arr5[i] = rand() % 50001;
	}
	for (int i = 0; i < 100000; i++) {
		arr6[i] = rand() % 100001;
	}





	return 0;
}