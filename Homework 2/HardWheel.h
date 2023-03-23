#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "Wheel.h"

using namespace std;

class HardWheel : public Wheel
{
protected:
    int WinCount;

public:
    HardWheel();                         // default constructor
    HardWheel(int minimum, int maximum); // fill constructor
    ~HardWheel();                        // destructor

    // Getter
    int getWinCount();

    // Setter
    void setWinCount(int w);

    void Spin(int val, int max); // overloaded spin accept player's spin and the # of values on their wheel
};