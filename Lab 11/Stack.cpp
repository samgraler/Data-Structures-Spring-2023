#pragma once
#include "Stack.h"
#include "StackExceptions.h"

Stack::Stack(int MaxSize)
{ // Default Constructor
    StackArray = new int(MaxSize);
    for (int i = 0; i < MaxSize; i++)
    {
        StackArray[i] = 0;
    }
}

Stack::~Stack()
{ // Destructor
}

void Stack::Push(int c)
{
    if (Top < 5)
    {
        StackArray[Top] = c;
        Top++;
    }
    else
    {
        throw StackOverflowException();
    }
}

int Stack::Pop()
{
    if (isEmpty())
    {
        throw StackUnderflowException();
    }
    Top--;
    return (StackArray[Top]);
}

int Stack::getLength()
{
    return (Top);
}

bool Stack::isEmpty() {
    if (Top == 0)
    {
        return true;
    }
    return false;
}