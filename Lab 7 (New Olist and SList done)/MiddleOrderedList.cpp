#pragma once
#include "MiddleOrderedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
MiddleOrderedList<T>::MiddleOrderedList()
{
    PointerArray = new T *[ARRAY_SIZE];
    Size = ARRAY_SIZE;
    MiddleIndex = (ARRAY_SIZE / 2);
    RightIndex = (MiddleIndex);
    LeftIndex = (MiddleIndex);
    numItems = 0;
    numComps = 0;
    numMoves = 0;
    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
}

template <class T>
void MiddleOrderedList<T>::addItem(T inval)
{
    // list full case
    if (isFull())
    {
        throw FullListException();
    }

    // list emtpy case
    if (isEmpty())
    {
        PointerArray[MiddleIndex] = new T(inval);
        numItems++;
        numMoves++;
        RightIndex = MiddleIndex + 1;
        LeftIndex = MiddleIndex - 1;
        return;
    }

    int current = MiddleIndex;
    // left case

    if (inval < (*PointerArray[MiddleIndex]))
        {
        numComps++;
        // find desired index
        while ((PointerArray[current] != nullptr && inval < (*PointerArray[current])) && current != 0)
        {
            numComps++;
            current--;
        }
        if (PointerArray[current] == nullptr) // nullptr case
        {
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
            numMoves++;
        }
        else if (current == 0)
        {
            for (int i = RightIndex; i >= 0; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
            LeftIndex++;
            numMoves++;
        }
        else if (LeftIndex == -1 || current == 0) // right shift case (no room on left) PROBLEM CASE
        {
            for (int i = RightIndex; i >= current; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
            LeftIndex++;
            numMoves++;
        }
        else // left shift case (room on left to shift)
        {
            for (int i = LeftIndex; i < current; i++)
            {
                PointerArray[i] = PointerArray[i + 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
            RightIndex--;
            numMoves++;
        }
    }
    else
    { // right case
        // find desired index
        while ((PointerArray[current] != nullptr && inval > (*PointerArray[current])) && current != ARRAY_SIZE - 1)
        {
            current++;
            numComps++;
        }
        if (PointerArray[current] == nullptr) // nullptr case
        {
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
            numMoves++;
        }
        else if (RightIndex == ARRAY_SIZE || current == ARRAY_SIZE - 1) // left shift case (no room on right) PROBLEM CASE
        {
            for (int i = LeftIndex; i < current; i++)
            {
                PointerArray[i] = PointerArray[i + 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
            numMoves++;\
        }
        else // (room on right to shift)
        {
            for (int i = RightIndex; i >= current; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
            numMoves++;
        }
    }
}

template <class T>
T MiddleOrderedList<T>::removeItem(T n)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    int index = FindItem(n);

    T retval = (*PointerArray[index]);
    numMoves++;

    if (index > MiddleIndex)
    {
        numComps++;
        for (int i = index; i < RightIndex; i++) // loop to shift other items left
        {
            PointerArray[i] = PointerArray[i + 1];
            numMoves++;
        }
        RightIndex--;
        PointerArray[RightIndex] = nullptr;
        numMoves++;
    }
    else if (index < MiddleIndex)
    {
        for (int i = index; i > LeftIndex; i--) // loop to shift other items right
        {
            PointerArray[i] = PointerArray[i - 1];
            numMoves++;
        }
        LeftIndex++;
        PointerArray[LeftIndex] = nullptr;
        numMoves++;
    }
    else // remove middle case
    {
        // index == middleIndex
        for (int i = index; i < RightIndex; i++) // loop to shift other items left
        {
            PointerArray[i] = PointerArray[i + 1];
            numMoves++;
        }
        RightIndex--;
        PointerArray[RightIndex] = nullptr;
        numMoves++;
        if (PointerArray[MiddleIndex] == nullptr && (!isEmpty()))
        {
            for (int i = MiddleIndex; i > LeftIndex; i--) // loop to shift other items right
            {
                PointerArray[i] = PointerArray[i - 1];
                numMoves++;
            }
            LeftIndex++;
            RightIndex++;
            PointerArray[LeftIndex] = nullptr;
            numMoves++;
        }
    }
    numItems--;
    return retval;
}

template <class T>
void MiddleOrderedList<T>::MakeEmpty()
{
    for (int i = 0; i < Size; i++)
    {
        PointerArray[i] = nullptr;
    }
    LeftIndex = MiddleIndex;
    RightIndex = MiddleIndex;
    numItems = 0;
}

template <class T>
int MiddleOrderedList<T>::FindItem(T val) // returns index of the value passed in if it exists in the list (if not throws item not found exception
{
    if (val > (*PointerArray[MiddleIndex]))
    {
        numComps++;
        for (int i = MiddleIndex; i < RightIndex; i++)
        {
            numComps++;
            if ((*PointerArray[i]) == val)
            {
                return (i);
            }
        }
    }
    else
    {
        numComps++;
        for (int i = MiddleIndex; i > LeftIndex; i--)
        {
            numComps++;
            if ((*PointerArray[i]) == val)
            {
                return (i);
            }
        }
    }
    throw ItemNotFoundException();
}

template <class T>
string MiddleOrderedList<T>::Print()
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
    return (ret);
}

template <class T>
bool MiddleOrderedList<T>::isEmpty()
{
    return (numItems == 0);
}

template <class T>
bool MiddleOrderedList<T>::isFull()
{
    return (numItems == ARRAY_SIZE);
}

template <class T>
string MiddleOrderedList<T>::PrintStats()
{
    string ret = "Number of Comparisons: " + to_string(numComps) + "\n" + "Number of Moves: " + to_string(numMoves);
    return(ret);
}

template <class T>
int MiddleOrderedList<T>::getRight()
{
    return(RightIndex);
}

template <class T>
int MiddleOrderedList<T>::getLeft()
{
    return(LeftIndex);
}