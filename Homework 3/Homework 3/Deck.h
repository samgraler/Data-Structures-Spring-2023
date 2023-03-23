#pragma once
#include <string>
#include "DeckExceptions.h"
#include "Card.h"

using namespace std;

class Deck
{
private:
    Card* head = nullptr;
    int length = 0;

public:
    Deck(Card* h);
    Deck();
    ~Deck();

    Card* Dequeue();
    Card* Peek();

    void Enqueue(Card* c);

    int getLength();

    bool isEmpty();
};