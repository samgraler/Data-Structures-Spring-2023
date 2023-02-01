#pragma once
#include "Distance.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

// Default constructor
Distance::Distance()
{
    Meters = 0.0;
    Feet = 0;
    Inches = 0;
}

// Fill constructor for imperial units
Distance::Distance(int f, int i)
{
    Feet = f;
    Inches = i;
    Meters = 0;
    if (i > 12)
    {
        Feet += floor(i / 12);
        Inches = i % 12;
    }
    UpdateMetric();
}

// Fill constructor for metric units
Distance::Distance(double m)
{
    Meters = m;
    Inches = 0;
    Feet = 0;
    UpdateImperial();
}

// Destructor
Distance::~Distance()
{
}

// Getters
int Distance::getInches()
{
    return (Inches);
}

int Distance::getFeet()
{
    return (Feet);
}
double Distance::getMeters()
{
    return (Meters);
}

// Setters
void Distance::setInches(int i)
{
    Inches = i;
    if (i > 12)
    {
        Feet += floor(i / 12);
        Inches = i % 12;
    }
    UpdateMetric();
}

void Distance::setFeet(int f)
{
    Feet = f;
    UpdateMetric();
}

void Distance::setMeters(double m)
{
    Meters = m;
    UpdateImperial();
}

// Additional Member Functions

void Distance::UpdateImperial() // updates the feet and inches according to the current value of meters
{
    Inches = 39.3701 * Meters;
    Feet = floor(Inches / 12);
    Inches = Inches % 12;
}

void Distance::UpdateMetric() // updates meters according to the current value of feet and inches
{
    Meters = (Inches + (Feet * 12)) * 0.0254;
}

void Distance::print() // uses cout to disply the values of class attributes
{
    cout << "Meters: " << Meters << endl;
    cout << "Feet: " << Feet << endl;
    cout << "Inches: " << Inches << endl;
}

// Operator Overloads

void Distance::operator+(Distance& D)
{
    Meters += D.getMeters();
    UpdateImperial();
}

void Distance::operator-(Distance& D)
{
    this->Meters -= D.Meters;
    this->UpdateImperial();
}

void Distance::operator*(Distance& D)
{
    this->Meters *= D.Meters;
    this->UpdateImperial();
}

void Distance::operator/(Distance& D)
{
    this->Meters /= D.Meters;
    this->UpdateImperial();
}

bool Distance::operator==(Distance& D)
{
    return (this->Meters == D.Meters && this->Inches == D.Inches && this->Feet == D.Inches);
}

/* string Distance::operator<<(const Distance &D)
{
    return (to_string(this->Meters) + " meters / " + to_string(this->Feet) + " feet " + to_string(this->Inches) + " inches ");
} */

std::ostream& operator<<(ostream& os, Distance& D)
{
    os << to_string(D.getMeters()) << " meters / " << to_string(D.getFeet()) + " feet " << to_string(D.getInches()) << " inches ";
    return os;
} 