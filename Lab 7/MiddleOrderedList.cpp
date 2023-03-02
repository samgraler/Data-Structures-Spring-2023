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
    RightIndex = (MiddleIndex + 1);
    LeftIndex = (MiddleIndex - 1);
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
        cout << current << endl;
        if (PointerArray[current] == nullptr) // nullptr case
        {
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
            numMoves++;
        }
        else if (current == 0 || LeftIndex == -1) // right shift case (no room on left)
        {
            for (int i = RightIndex; i > current; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
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
        cout << current << endl;
        if (PointerArray[current] == nullptr) // nullptr case
        {
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
            numMoves++;
        }
        else if (current == ARRAY_SIZE - 1 || RightIndex == ARRAY_SIZE) // left shift case (no room on right)
        {
            for (int i = LeftIndex; i < current; i++)
            {
                PointerArray[i] = PointerArray[i + 1];
                numMoves++;
            }
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
            numMoves++;
        }
        else // right shift case (room on right to shift)
        {
            cout << "Thing3 to happen" << endl;
            for (int i = RightIndex; i > current; i--)
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
        for (int i = index; i > LeftIndex; i--) // loop to shift other items right
        {
            PointerArray[i] = PointerArray[i - 1];
            numMoves++;
        }
        LeftIndex++;
        PointerArray[LeftIndex] = nullptr;
        numMoves++;
    }
    else
    {
        for (int i = index; i < RightIndex; i++) // loop to shift other items left
        {
            PointerArray[i] = PointerArray[i + 1];
            numMoves++;
        }
        RightIndex--;
        PointerArray[RightIndex] = nullptr;
        numMoves++;
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
        LeftIndex = MiddleIndex - 1;
        RightIndex = MiddleIndex + 1;
        numItems = 0;
    }
}

template <class T>
int MiddleOrderedList<T>::FindItem(T val) // returns index of the value passed in if it exists in the list (if not throws item not found exception
{
    if (val > (*PointerArray[MiddleIndex]))
    {
        numComps++;
        for (int i = MiddleIndex; i < RightIndex - 1; i++)
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
        for (int i = MiddleIndex; i > LeftIndex + 1; i--)
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