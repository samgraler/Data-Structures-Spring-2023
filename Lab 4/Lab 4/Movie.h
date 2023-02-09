#pragma once
#include "Show.h"
#include <string>
#include <iostream>
using namespace std;

class Movie : public Show
{
private:
    string Credits;

public:
    Movie(); // Default Constructor
    Movie(string T, string D, string C); // Fill constructor
    ~Movie(); // destructor

    // new Getter
    string getCredits();

    // new Setter
    void setCredits(string C);

    // Play
    void Play();

    // no details overide
};