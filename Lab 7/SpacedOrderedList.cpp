#pragma once
#include "SpacedOrderedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
SpacedOrderedList<T>::SpacedOrderedList()
{
    PointerArray = new T * [ARRAY_SIZE];
    Size = ARRAY_SIZE;
    numItems = 0;
    indexMax = 0;
    numComps = 0;
    numMoves = 0;
    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
}

template <class T>
void SpacedOrderedList<T>::addItem(T inval)
{
    int i;   // counter to hold place where we want to insert inval
    int nl;   // counter to hold index of first null pointer to the left of the desired index
    int nr;   // counter to hold index of first null pointer to the right of the desired index

    // list full case
    if (isFull())
    {
        throw FullListException();
    }

    // list emtpy case
    if (isEmpty())
    {
        PointerArray[0] = new T(inval);
        numMoves++;
        numItems++;
        return;
    }

    // entering largest item case
    if (inval > (*PointerArray[indexMax]) && indexMax < ARRAY_SIZE - 2)
    {
        numComps++;
        PointerArray[indexMax + 2] = new T(inval);
        numMoves++;
        indexMax += 2;
        numItems++;
        return;
    }

    int lessIndex = 0;
    int moreIndex = 0;

    // loop to find index of lesser and greater item
    for (i = 0; i <= indexMax; i++) 
    {
        numComps++;
        if (i == indexMax) {
            break;
        }
        else if ((PointerArray[i] != nullptr) && (*PointerArray[i] < inval)) {
            lessIndex = i;
            numComps++;
        }
        else if ((PointerArray[i] != nullptr) && (*PointerArray[i] > inval))
        {
            moreIndex = i;
            numComps++;
            break;
        }
    }

    // logic to get index to insert at
    if (moreIndex - lessIndex > 2)
    {
        i = lessIndex + 2;
    }
    else {
        i = lessIndex + 1;
    }


    if (PointerArray[i] == nullptr) {  // no shift case
        PointerArray[i] = new T(inval);
        numMoves++;
        numItems++;
        return;
    }
    else { // shift case
        nl = i;
        nr = i;
        while (PointerArray[nl] != nullptr && PointerArray[nr] != nullptr)
        {
            if (nl > 0) { nl--; }
            if (nr < 24) { nr++; } 
            numComps++;
        }
        if (PointerArray[nl] == nullptr) // left shift is easiest
        {
            for (int j = nl; j < i - 1; j++) // loop to shift other items left
            {
                numMoves++;
                PointerArray[j] = PointerArray[j + 1];
                if (moreIndex - lessIndex == 1) {
                    i -= 1;
                }
            }
        }
        else // right shift is easiest
        {
            for (int j = nr; j > i; j--) // loop to shift other items right
            {
                numMoves++;
                PointerArray[j] = PointerArray[j - 1];
            }
        }
        PointerArray[i] = new T(inval);
        numMoves++;
        numItems++;
        for (int i = indexMax; i > 0; i--)
        {
            if (PointerArray[i] != nullptr)
            {
                indexMax = i;
                break;
            }
        }
    }
}

template <class T>
T SpacedOrderedList<T>::removeItem(T n)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    int index = FindItem(n);

    T retval = (*PointerArray[index]);
    numMoves++;
    PointerArray[index] = nullptr;

    // loop to reset max index
    if (PointerArray[indexMax] == nullptr)
    {
        for (int i = indexMax; i > 0; i--)
        {
            if (PointerArray[i] != nullptr)
            {
                indexMax = i;
                break;
            }
        }
    }
    numItems--;
    return retval;
}

template <class T>
bool SpacedOrderedList<T>::isEmpty()
{
    return (numItems == 0);
}

template <class T>
bool SpacedOrderedList<T>::isFull()
{
    return (numItems == ARRAY_SIZE);
}

template <class T>
void SpacedOrderedList<T>::MakeEmpty()
{

    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }    numItems = 0;
}

template <class T>
int SpacedOrderedList<T>::FindItem(T val)
{
    for (int i = 0; i < Size; i++)
    {
        numComps++;
        if ((PointerArray[i] != nullptr) && ((*PointerArray[i]) == val))
        {
            return (i);
        }
    }
    throw ItemNotFoundException();
}

template <class T>
string SpacedOrderedList<T>::Print()
{
    string ret = "";
    for (int i = 0; i < Size; i++)
    {
        if (PointerArray[i] == nullptr)
        {
            ret += "np ";
        }
        else
        {
            ret += to_string((*PointerArray[i]));
            ret += " ";
        }
    }
    return(ret);
 }

template <class T>
string SpacedOrderedList<T>::PrintStats()
{
    string ret = "Number of Comparisons: " + to_string(numComps) + "\n" + "Number of Moves: " + to_string(numMoves);
    return(ret);
}