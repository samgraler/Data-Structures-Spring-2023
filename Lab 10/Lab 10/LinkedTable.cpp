#pragma once
#include "LinkedTable.h"
#include <iomanip>
#include <iostream>
#include <algorithm>


template <class T>
LinkedTable<T>::LinkedTable(int s) : HashTable<T>(s)
{
    MAX_SIZE = s;
    arr = new LinkedList<T>*[s];
    for (int i = 0; i < s; i++)
    {
        arr[i] = new LinkedList<T>();
        arr[i]->head = nullptr;
    }
}

template <class T>
LinkedTable<T>::~LinkedTable()
{
    LinkedList<T>::comparisons = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        delete arr[i];
    }
}

// The sum of all the ASCII values for the passed in string and modulus by the maximum size of the table
template <class T>
int LinkedTable<T>::Hash(string s)
{
    int HashValue = 0;
    for (int i = 0; i < s.length(); i++)
    {
        HashValue += (int)s[i];
    }
    return (HashValue % MAX_SIZE);
}

template <class T>
void LinkedTable<T>::AddItem(T *inval)
{
    int index = Hash(*inval);
    if (arr[index] == nullptr)
    {
        arr[index] = new LinkedList<T>();
    }
    else
    {
        arr[index]->AddItem(inval);
    }
    numItems++;
}

template <class T>
T *LinkedTable<T>::GetItem(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash(*key);
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }

    arr[index]->comparisons++;
    return arr[index]->GetItem(key);
}

template <class T>
T *LinkedTable<T>::RemoveItem(T *key) // changes
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash(*key);
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    numItems--;
    return arr[index]->Remove(key);
}

template <class T>
int LinkedTable<T>::GetLength()
{
    return (numItems);
}

template <class T>
bool LinkedTable<T>::isEmpty()
{
    if (numItems == 0)
    {
        return true;
    }
    return false;
}

template<class T>
int LinkedTable<T>::getComps()
{
    return(LinkedList<T>::comparisons);
}

template<class T>
void LinkedTable<T>::ResetComps()
{
    LinkedList<T>::comparisons = 0;
}