#pragma once
#include "Player.h"

Player::Player()
{
    name = "";
    D = new Deck();
    SD = new SideDeck();
}

Player::Player(string n)
{
    name = n;
    D = new Deck();
    SD = new SideDeck();
}

Player::~Player()
{
}

Deck* Player::getDeck()
{
    return D;
}

SideDeck* Player::getSideDeck()
{
    return SD;
}

string Player::getName()
{
    return name;
}