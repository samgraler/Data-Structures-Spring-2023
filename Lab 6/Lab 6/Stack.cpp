#pragma once
#include "Stack.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack(int s)
{
    StackArray = new T *[s];
    top = 0;
    Size = s;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] StackArray;
}

template <class T>
void Stack<T>::Push(T *inval)
{
    if (top < Size)
    {
        StackArray[top] = inval;
        top++;
    }
    else
    {
        throw StackOverflowException();
    }
}

template <class T>
T *Stack<T>::Pop()
{
    if (top != 0)
    {
        top--;
        return StackArray[top];
    }
    else
    {
        throw StackUnderflowException();
    }
}

template <class T>
T *Stack<T>::Top()
{
    if (top != 0)
    {
        return StackArray[top - 1];
    }
    throw StackUnderflowException();
}

template <class T>
int Stack<T>::Length()
{
    return (top);
}

template <class T>
void Stack<T>::Empty()
{
    for (int i = 0; i < top; i++)
    {
        delete StackArray[i];
    }
    top = -1;
}