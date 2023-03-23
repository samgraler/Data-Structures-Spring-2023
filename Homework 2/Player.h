#pragma once
#include <string>
#include <cstdlib>
#include "Wheel.h"
#include <iostream>

using namespace std;

class Player
{
protected:
    int Total;
    string Name;
    Wheel* pWheel;

public:
    Player();                         // Default Constructor
    Player(Wheel* w, int T, string N); // Fill constructor
    ~Player();                        // Destructor

    // Getters
    int getLastSpin();
    int getTotal();
    string getName();
    Wheel* getWheel();

    // Setters
    void setTotal(int M);
    void setName(string N);
};