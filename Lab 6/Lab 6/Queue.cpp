#pragma once
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(int s)
{
    QueueArray = new T *[s];
    NumItems = 0;
    Size = s;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] QueueArray;
}

template <class T>
void Queue<T>::Enqueue(T *inval)
{
    if (NumItems < Size)
    {
        QueueArray[NumItems] = inval;
        NumItems++;
    }
    else
    {
        throw QueueOverflowException();
    }
}

template <class T>
T *Queue<T>::Dequeue()
{
    if (NumItems < 0)
    {
        throw QueueUnderflowException();
    }
    else
    {
        T *temp = QueueArray[0];
        NumItems--;
        for (int i = 0; i < NumItems; i++)
        {
            QueueArray[i] = QueueArray[i + 1];
        }
        return (temp);
    }
}

template <class T>
T *Queue<T>::Peek()
{
    if (NumItems > 0)
    {
        return QueueArray[NumItems - 1];
    }
    throw QueueUnderflowException();
}

template <class T>
int Queue<T>::Length()
{
    return (NumItems);
}

template <class T>
void Queue<T>::Empty()
{
    for (int i = 0; i < NumItems; i++)
    {
        delete QueueArray[i];
    }
    NumItems = -1;
}