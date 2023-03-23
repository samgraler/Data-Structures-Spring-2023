#pragma once
#include "Wheel.h"
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Default constructor
Wheel::Wheel()
{
    Max = 10;
    Min = 1;
    BallValue = 0;
}

// Fill constructor
Wheel::Wheel(int minimum, int maximum)
{
    Max = maximum;
    Min = minimum;
    BallValue = 0;
}

// Destructor
Wheel::~Wheel()
{
}

// Getters
int Wheel::getMin()
{
    return (Min);
}

int Wheel::getMax()
{
    return (Max);
}

int Wheel::getBallValue()
{
    return (BallValue);
}

// Setters
void Wheel::setMin(int M)
{
    Min = M;
}

void Wheel::setMax(int M)
{
    Max = M;
}

void Wheel::setBallValue(int B)
{
    BallValue = B;
}

// regular wheel spin
void Wheel::Spin(int val, int max)
{
    BallValue = (rand() % Max + Min); 
}
