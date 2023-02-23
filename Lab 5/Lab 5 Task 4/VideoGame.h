#pragma once
#include <string>
#include <iostream>
using namespace std;

class VideoGame
{
protected:
    string Title;
    string Description;

public:
    VideoGame(); // Default Constructor
    VideoGame(string T, string D); // Fill constructor 
    ~VideoGame(); // Destructor

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