#pragma once
#ifndef _MiddleOrderedList_
#define _MiddleOrderedList_

#include "OrderedList.h"
#include "OrderedList.cpp"
#include <string>

using namespace std;

template <class T>
class MiddleOrderedList : protected OrderedList<T>
{
protected:
    T **PointerArray;
    int Size;
    int MiddleIndex;
    int RightIndex;
    int LeftIndex;
    int numItems;

public:
    // Constructor (Takes an invalue of type 'T')
    MiddleOrderedList();

    void addItem(T inval);
    T removeItem(T n);
    int FindItem(T val); // helper function to remove item

    bool isEmpty();
    bool isFull();
    void MakeEmpty();
    string Print();
};

#endif