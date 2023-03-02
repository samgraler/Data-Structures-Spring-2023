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
        return;
    }

    int current = MiddleIndex;
    // left case
    if (inval < (*PointerArray[MiddleIndex]))
    {
        // find desired index
        while ((PointerArray[current] != nullptr && inval < (*PointerArray[current])) && current != 0)
        {
            current--;
        }
        cout << current << endl;
        if (PointerArray[current] == nullptr) // nullptr case
        {
            cout << "This should run" << endl;
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
        }
        else if (current == 0 || LeftIndex == -1) // right shift case (no room on left)
        {
            cout << "Wrong ran" << endl;
            for (int i = RightIndex; i > current; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
        }
        else // left shift case (room on left to shift)
        {
            cout << "also wrong ran" << endl;
            for (int i = LeftIndex; i < current; i++)
            {
                PointerArray[i] = PointerArray[i + 1];
            }
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
        }
    }
    else
    { // right case
        // find desired index
        while ((PointerArray[current] != nullptr && inval > (*PointerArray[current])) && current != ARRAY_SIZE - 1)
        {
            current++;
        }
        cout << current << endl;
        if (PointerArray[current] == nullptr) // nullptr case
        {
            cout << "Thing1 to happen" << endl;
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
        }
        else if (current == ARRAY_SIZE - 1 || RightIndex == ARRAY_SIZE) // left shift case (no room on right)
        {
            cout << "Thing2 to happen" << endl;
            for (int i = LeftIndex; i < current; i++)
            {
                PointerArray[i] = PointerArray[i + 1];
            }
            PointerArray[current] = new T(inval);
            numItems++;
            LeftIndex--;
        }
        else // right shift case (room on right to shift)
        {
            cout << "Thing3 to happen" << endl;
            for (int i = RightIndex; i > current; i--)
            {
                PointerArray[i] = PointerArray[i - 1];
            }
            PointerArray[current] = new T(inval);
            numItems++;
            RightIndex++;
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

    if (index > MiddleIndex)
    {
        for (int i = index; i > LeftIndex; i--) // loop to shift other items right
        {
            PointerArray[i] = PointerArray[i - 1];
        }
        LeftIndex++;
        PointerArray[LeftIndex] = nullptr;
    }
    else
    {
        for (int i = index; i < RightIndex; i++) // loop to shift other items left
        {
            PointerArray[i] = PointerArray[i + 1];
        }
        RightIndex--;
        PointerArray[RightIndex] = nullptr;
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
int MiddleOrderedList<T>::FindItem(T val)
{
    if (val > (*PointerArray[MiddleIndex]))
    {
        for (int i = MiddleIndex; i < RightIndex - 1; i++)
        {
            if ((*PointerArray[i]) == val)
            {
                return (*PointerArray[i]);
            }
        }
    }
    else
    {
        for (int i = MiddleIndex; i > LeftIndex + 1; i--)
        {
            if ((*PointerArray[i]) == val)
            {
                return (*PointerArray[i]);
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