#include "Show.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Show::Show()
{
    Title = "";
    Description = "";
}

// Fill constructor
Show::Show(string T, string D)
{
    Title = T;
    Description = D;
}

// Destructor
Show::~Show()
{

}

// Getters
string Show::getTitle()
{
    return (Title);
}

string Show::getDescription()
{
    return (Description);
}

// Setters
void Show::setTitle(string T)
{
    Title = T;
}

void Show::setDescription(string D)
{
    Description = D;
}

// Play definition
void Show::Play()
{
    cout << "Show Play:" << endl;
    cout << "Now Playing: " + Title << endl;
}

// Details
void Show::Details() // uses cout to disply the values of class attributes
{
    cout << fixed << setprecision(2);
    cout << "Show Details:" << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Description: " << getDescription() << endl;
}
