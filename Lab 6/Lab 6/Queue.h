#pragma once
#include <string>
#include "QueueExceptions.h"

template <class T>
class Queue
{
private:
    T **QueueArray; // Array of pointers to data
    int NumItems;        // holds index of the next available space
    int Size;       // holds the constructed size of the array

public:
    // Constructor
    Queue(int s);
    // Destructor
    ~Queue();
    // Additional Functions
    void Enqueue(T *inval);
    T *Dequeue();
    T *Peek();
    int Length();
    void Empty();
};