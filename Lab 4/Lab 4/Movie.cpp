#pragma once
#include "Movie.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Movie::Movie()
{
    Title = "";
    Description = "";
    Credits = "";
}

// Fill constructor
Movie::Movie(string T, string D, string C)
{
    Title = T;
    Description = D;
    Credits = C;
}

// Destructor
Movie::~Movie()
{
}

// new Getter
string Movie::getCredits()
{
    return (Credits);
}

// new Setter
void Movie::setCredits(string C)
{
    Description = C;
}

// Play
void Movie::Play() // uses cout to disply the values of class attributes
{
    cout << fixed << setprecision(2);
    cout << "Movie Play:" << endl;
    cout << "Now Playing: " + getTitle() << endl;
    cout << "Credits: " << getCredits();
    cout << endl;
}
