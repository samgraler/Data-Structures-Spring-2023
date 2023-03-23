// #pragma once
#include "Player.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Player::Player()
{
    pWheel = new Wheel();
    Total = 0;
    Name = "";
}

// Fill constructor
Player::Player(Wheel* pW, int T, string N)
{
    pWheel = pW;
    Total = T;
    Name = N;
}

// Destructor
Player::~Player()
{
}

// Getters
int Player::getLastSpin()
{
    return (pWheel->getBallValue());
}

int Player::getTotal()
{
    return (Total);
}

Wheel* Player::getWheel()
{
    return(pWheel);
}

// Setters
void Player::setTotal(int T)
{
    Total = T;
}

string Player::getName()
{
    return (Name);
}

void Player::setName(string N)
{
    Name = N;
}