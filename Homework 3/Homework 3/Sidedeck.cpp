#pragma once
#include "Sidedeck.h"
#include "SideDeckExceptions.h"

SideDeck::SideDeck()
{ // Default Constructor
    for (int i = 0; i < MaxSize; i++)
    {
        SD[i] = nullptr;
    }
}

SideDeck::~SideDeck()
{ // Destructor
}

void SideDeck::Push(Card* c)
{
    if (Top < 5)
    {
        SD[Top] = c;
        Top++;
    }
    else
    {
        throw SideDeckOverflowException();
    }
}

Card* SideDeck::Pop()
{
    if (isEmpty())
    {
        throw SideDeckUnderflowException();
    }
    Top--;
    return (SD[Top]);
}

int SideDeck::getLength()
{
    return (Top);
}

bool SideDeck::isEmpty() {
    if (Top == 0)
    {
        return true;
    }
    return false;
}