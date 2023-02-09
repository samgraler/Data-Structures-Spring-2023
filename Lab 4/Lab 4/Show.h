#pragma once
#include <string>
#include <iostream>
using namespace std;

class Show
{
protected:
    string Title;
    string Description;

public:
    Show(); // Default Constructor
    Show(string T, string D); // Fill constructor 
    ~Show(); // Destructor

    // Getters
    string getTitle();
    string getDescription();

    // Setters
    void setTitle(string T);
    void setDescription(string D);

    // Virtual Play Function
    virtual void Play();

    // Details Function
    void Details();
};