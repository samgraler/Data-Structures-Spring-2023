#include <array>
#include <string>
#include <iostream>
#include <iomanip>
#include "EmptyShelfException.h"
#include "FullShelfException.h"

using namespace std;

const int NUM_T = 10;

template <class T>
class EntertainmentCollection
{
private:
    int Count;
    T *Items[NUM_T];

public:

    // Default constructor
    EntertainmentCollection()
    {
        Count = 0;
    }

    // Destructor
    ~EntertainmentCollection()
    {
    }

    // Getters
    int getCount()
    {
        return Count;
    }

    T *getItem(int index)
    {
        return Items[index];
    }

    // Setters
    void setItem(T *item, int index)
    {
        Items[index] = item;
    }

    // Additional Functions
    void addItem(T *item)
    {
        if (Count >= NUM_T) // if collection is full, full shelf exceotion is thrown
        {
            throw FullShelfException();
        }
        Items[Count] = item;
        Count++;
    }

    T *removeItem() // if collection is empty, empty shelf exceotion is thrown
    {
        if (Count <= 0)
        {
            throw EmptyShelfException();
        }
        Count--;
        T *returnT = Items[Count];
        return returnT;
    }
};