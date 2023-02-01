#pragma once
#include <string>
#include <iostream>
using namespace std;

class Distance
{
private:
    int Feet;
    int Inches;
    double Meters;

public:
    // Constructors / destructor
    Distance();             // Default Constructor
    Distance(int f, int i); // Fill constructor for imperial units
    Distance(double m);     // Fill constructor for metric units
    ~Distance();            // Destructor

    // Getters
    int getFeet();
    int getInches();
    double getMeters();

    // Setters
    void setFeet(int f);
    void setInches(int i);
    void setMeters(double m);

    // Other Member Functions
    void print(); // uses cout to disply the values of class attributes

    // Additions prompted by Task 2
    void UpdateImperial(); // updates the feet and inches according to the current value of meters
    void UpdateMetric();   // updates meters based on the current value of feet and inches

    // Task 3 Operator Overloads
    void operator+(Distance& D);
    void operator-(Distance& D);
    void operator*(Distance& D);
    void operator/(Distance& D);
    bool operator==(Distance& D);

    // return distance in meters
    double returnDistance() { return Meters; }

    // << overload
    friend std::ostream& operator<<(ostream& os, Distance& D);
};