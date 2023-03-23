#include "Card.h"

using namespace std;

Card::Card(int inval, string s)
{
    data = inval;
    suit = s;
    next = nullptr;
}

Card::Card()
{
    data = -1;
    suit = " ";
    next = nullptr;
}

void Card::setData(int inval)
{
    data = inval;
}

void Card::setNext(Card* n)
{
    next = n;
}

int Card::getData()
{
    return (data);
}

void Card::setSuit(string s)
{
    suit = s;
}

string Card::getSuit()
{
    return suit;
}

Card* Card::getNext()
{
    return (next);
}