#include "VideoGame.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
VideoGame::VideoGame()
{
    Title = "";
    Description = "";
}

// Fill constructor
VideoGame::VideoGame(string T, string D)
{
    Title = T;
    Description = D;
}

// Destructor
VideoGame::~VideoGame()
{

}

// Getters
string VideoGame::getTitle()
{
    return (Title);
}

string VideoGame::getDescription()
{
    return (Description);
}

// Setters
void VideoGame::setTitle(string T)
{
    Title = T;
}

void VideoGame::setDescription(string D)
{
    Description = D;
}

// Play definition
void VideoGame::Play()
{
    cout << "VideoGame Play:" << endl;
    cout << "Now Playing: " + Title << endl;
}

// Details
void VideoGame::Details() // uses cout to disply the values of class attributes
{
    cout << "Title: " << getTitle() << endl;
    cout << "Description: " << getDescription() << endl;
}
