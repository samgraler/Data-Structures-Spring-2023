#pragma once
#include "Distance.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Distance::Distance()
{
    Meters = 0.0;
    Feet = 0;
    Inches = 0;
}

// Fill constructor for imperial units
Distance::Distance(double f, double i)
{
    Feet = f;
    Inches = i;
    Meters = 0;
    if (i > 12)
    {
        Feet += floor(i / 12);
        Inches = Inches - (Feet * 12);
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
double Distance::getInches()
{
    return (Inches);
}

double Distance::getFeet()
{
    return (Feet);
}
double Distance::getMeters()
{
    return (Meters);
}

// Setters
void Distance::setInches(double i)
{
    Inches = i;
    if (i > 12)
    {
        Feet += floor(i / 12);
        Inches = Inches - (Feet * 12);
    }
    UpdateMetric();
}

void Distance::setFeet(double f)
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
    Inches = Inches - (Feet * 12);
}

void Distance::UpdateMetric() // updates meters according to the current value of feet and inches
{
    Meters = (Inches + (Feet * 12)) * 0.0254;
}

void Distance::print() // uses cout to disply the values of class attributes
{
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Meters: " << Meters << endl;
    cout << "Feet: " << Feet << endl;
    cout << "Inches: " << Inches << endl;
    cout << endl;
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
    return (this->Meters == D.Meters || (this->Inches == D.Inches && this->Feet == D.Inches));
}

std::ostream& operator<<(ostream& os, Distance& D)
{
    os << to_string(D.getMeters()) << " meters / " << to_string(D.getFeet()) + " feet " << to_string(D.getInches()) << " inches ";
    return os;
}