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
}

// Fill constructor
Movie::Movie(string T, string D)
{
    Title = T;
    Description = D;
}

// Destructor
Movie::~Movie()
{

}

// Getters
string Movie::getTitle()
{
    return (Title);
}

string Movie::getDescription()
{
    return (Description);
}

// Setters
void Movie::setTitle(string T)
{
    Title = T;
}

void Movie::setDescription(string D)
{
    Description = D;
}

// Play definition
void Movie::Play()
{
    cout << "Movie Play:" << endl;
    cout << "Now Playing: " + Title << endl;
}

// Details
void Movie::Details() // uses cout to disply the values of class attributes
{
    cout << "Title: " << getTitle() << endl;
    cout << "Description: " << getDescription() << endl;
}
