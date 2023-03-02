#pragma once
#ifndef _OrderedList_
#define _OrderedList_

#include <string>
#include "ListExceptions.h"

using namespace std;

template <class T>
class OrderedList
{
protected:
    T **PointerArray;
    int Size;
    int numItems;
    int numComps;
    int numMoves;

public:
    // Constructor (Takes an invalue of type 'T')
    OrderedList();

    virtual void addItem(T inval);
    virtual T removeItem(T n);
    virtual int FindItem(T val); // helper function to remove item
    bool isEmpty();
    bool isFull();
    virtual void MakeEmpty();
    string Print();
    string PrintStats();

};

#endif