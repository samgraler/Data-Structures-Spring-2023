#pragma once
#include "Show.h"
#include <string>
#include <iostream>
using namespace std;

class TvShow : public Show
{
private:
    string Episodes[100][100];

public:
    TvShow(); // Default Constructor
    TvShow(string T, string D, int s, int e); // Fill constructor
    ~TvShow(); // destructor

    // new Getter
    string getEpisode(int s, int e);

    // new Setter
    void setEpisodes(int s, int e); // resets the entire array to the new dimensions passed in

    void Play(); // virtual play definitino
    void Details(); // details overide
    void InitializeArray(); // initializes episode array to "0"
};