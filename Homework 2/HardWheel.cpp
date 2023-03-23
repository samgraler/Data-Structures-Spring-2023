#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "HardWheel.h"

using namespace std;

// default constructor
HardWheel::HardWheel()
{
    Max = 1;
    Min = 10;
    BallValue = 0;
    WinCount = 0;
}

// fill constructor
HardWheel::HardWheel(int minimum, int maximum)
{
    Max = maximum;
    Min = minimum;
    BallValue = 0;
    WinCount = 0;
}

// destructor
HardWheel::~HardWheel()
{
}

// overloaded spin
void HardWheel::Spin(int val, int max)
{
    BallValue = (rand() % Max + Min); // generate number
    if (BallValue < val) // if the player wins, increase the max value of the HardWheel
    {
        Max++;
    }
    else // if the house wins, check to see if it has won multiple times in a row and if that is the case, decrease the max value of the HardWheel (will not go lower than the # of values on the player's wheel
    {
        WinCount++;
        if (WinCount > 1 && Max > max)
        {
            Max--;
        }
    }
}

// Getter
int HardWheel::getWinCount()
{
    return (WinCount);
}

// Setter
void HardWheel::setWinCount(int w)
{
    WinCount = w;
}