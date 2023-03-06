#pragma once
#ifndef _SpacedOrderedList_
#define _SpacedOrderedList_

#include <string>
#include "ListExceptions.h"
#include "OrderedList.h"
#include "OrderedList.cpp"

using namespace std;

template <class T>
class SpacedOrderedList : protected OrderedList<T>
{
protected:
    T **PointerArray;
    int Size;
    int numItems;
    int indexMax;
    int numComps;
    int numMoves;

public:
    // Constructor (Takes an invalue of type 'T')
    SpacedOrderedList();
    virtual void addItem(T inval);
    virtual T removeItem(T n);
    virtual int FindItem(T val); // helper function to remove item
    bool isEmpty();
    bool isFull();
    virtual void MakeEmpty();
    virtual string Print();
    string PrintStats();

    int getIndexMax();
};

#endif