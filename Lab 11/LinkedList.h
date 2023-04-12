#pragma once
#ifndef _LinkedList_
#define _LinkedList_
#include <string>
#include "ListExceptions.h"
#include "Node.h"
#include "Node.cpp"

template <class T>
class LinkedList
{
private:
    Node<T>* head;
    int length = 0;
    Node<T>* current;

public:
    // constructor and destructor
    LinkedList();
    ~LinkedList();

    // additional methods
    void Insert(T* item);
    T* Remove(T* item);

    bool IsInList(T* item);
    bool isEmpty();

    int Size();

    void Reset();
    T* SeeNext();
    T* SeeAt();

    void Print();
};

#endif
