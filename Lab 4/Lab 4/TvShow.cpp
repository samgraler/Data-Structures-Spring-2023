#pragma once
#include "TvShow.h"
#include <string>
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

// Default constructor
TvShow::TvShow()
{
    Title = "";
    Description = "";
    InitializeArray();
}

// Fill constructor
TvShow::TvShow(string T, string D, int s, int e)
{
    Title = T;
    Description = D;
    InitializeArray();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < e; j++)
        {
            Episodes[i][j] = "Season: " + to_string(i+1) + " Episode: " + to_string(j+1);
        }
    }
}

// Destructor
TvShow::~TvShow()
{

}

// new Getter
string TvShow::getEpisode(int s, int e)
{
    return Episodes[s - 1][e - 1];
}

// new Setter (passes in nuumber of seasons, and number of episodes (same number of episodes in all seasons))
void TvShow::setEpisodes(int s, int e)
{
    InitializeArray(); // resets all spots in array to "0" so the old episodes don't remain
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < e; j++)
        {
            Episodes[i][j] = "Season: " + to_string(i+1) + " Episode: " + to_string(j+1);
        }
    }
}

// Play
void TvShow::Play()
{
    int s, e;
    cout << "TV Show Play:" << endl;
    cout << "Please enter the Season you'd like to play: ";
    cin >> s;
    cout << "Please enter the Episode you'd like to play: ";
    cin >> e;
    cout << endl;
    if (Episodes[s - 1][e - 1] == "0") // checks to see if the episode exists
    {
        cout << "This episode does not exist." << endl; // if it doesn't, it prints the message explaining that it doesn't
    }
    else
    {
        cout << "Now Playing: " + Episodes[s - 1][e - 1] << " of " + Title << endl; // prints the episode they chose and the title of the show
    }
}

// Details
void TvShow::Details()
{
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "TV Show Details:" << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Description: " << getDescription() << endl;
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
        if (Episodes[i][0] == "0")
        {
            break;
        }
        counter++;
    }
    cout << "Number of Seasons: " << counter << endl;
}

// Function to initialize all spots in the 100 x 100 array to "0"
void TvShow::InitializeArray()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            Episodes[i][j] = "0";
        }
    }
}