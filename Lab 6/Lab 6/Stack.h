#pragma once
#include <string>
#include "StackExceptions.h"

template <class T>
class Stack
{
private:
    T **StackArray; // Array of pointers to data
    int top;        // holds index of the next available space
    int Size;       // holds the constructed size of the array

public:
    // Constructor
    Stack(int s);
    // Destructor
    ~Stack();
    // Additional Functions
    void Push(T *inval);
    T *Pop();
    T *Top();
    int Length();
    void Empty();
};