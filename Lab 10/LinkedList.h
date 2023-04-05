#pragma once
#ifndef _LinkedList_
#define _LinkedList_

#include <string>
#include "HashExceptions.h"
#include "Node.h"
#include "Node.cpp"

template <class T>
class LinkedList
{
public:
    static int comparisons; // static variable to hold number of comparisons for all linked lists in the LinkedTable (reset after each run in test function)
    Node<T>* head;
    int length = 0;
    Node<T>* current;

    // constructor and destructor
    LinkedList();
    ~LinkedList();

    // additional methods
    void AddItem(T* item);
    T* Remove(T* item);
    void PrintAll();
    void Reset();

    bool IsInList(T* item);
    bool isEmpty();
    bool Available(string s);

    int Size();

    T* SeeNext();
    T* SeePrev();
    T* SeeAt(int l);
    T* SeeAt();
    T* GetItem(T* item);

    void ascii_art(string input);
};

#endif

// initialize static member
template <typename T>
int LinkedList<T>::comparisons = 0;
