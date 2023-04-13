#pragma once
#ifndef TWODHASH_H
#define TWODHASH_H
#include <string>
#include <iostream>
#include <math.h>
#include <exception>

class TwoDHash {

public:

	TwoDHash();
	~TwoDHash();

	bool isEmpty();
	int Hash(int inval);
	int Insert(int inval);
	int Find(int inval);
	int Remove(int inval);
	void Print() const;
	int getSize();

protected:
	int *table[100][5];
	const int MAX_SIZE = 500;
	int numItems = 0;

};
#endif