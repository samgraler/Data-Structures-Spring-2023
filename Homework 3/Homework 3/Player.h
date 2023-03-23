#pragma once

#include "Deck.h"
#include "Sidedeck.h"
#include <string>

using namespace std;

class Player
{
protected:
    Deck* D;
    SideDeck* SD;
    string name;

public:
    Player(); // Default Constructor
    Player(string n);
    ~Player();

    Deck* getDeck();
    SideDeck* getSideDeck();
    string getName();
};