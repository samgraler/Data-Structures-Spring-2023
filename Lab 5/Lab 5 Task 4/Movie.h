#pragma once
#include <string>
#include <iostream>
using namespace std;

class Movie
{
protected:
    string Title;
    string Description;

public:
    Movie(); // Default Constructor
    Movie(string T, string D); // Fill constructor 
    ~Movie(); // Destructor

    // Getters
    string getTitle();
    string getDescription();

    // Setters
    void setTitle(string T);
    void setDescription(string D);

    // Play Function
    void Play();

    // Details Function
    void Details();
};