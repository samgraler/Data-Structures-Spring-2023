#pragma once
#include <string>
#include "Card.h"

using namespace std;

const int MaxSize = 5;

class SideDeck
{
protected:
    int Top = 0;
    Card* SD[MaxSize];

public:
    SideDeck();  // Default Constructor
    ~SideDeck(); // Destructor

    Card* Pop();

    void Push(Card* c);

    int getLength();

    bool isEmpty();
};