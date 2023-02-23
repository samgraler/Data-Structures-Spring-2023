#include "MovieShelf.h"
#include <array>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
MovieShelf::MovieShelf()
{
    MovieCount = 0;
}

// Destructor
MovieShelf::~MovieShelf()
{
}

// Getters
int MovieShelf::getMovieCount()
{
    return MovieCount;
}

Movie *MovieShelf::getMovie(int index)
{
    return Movies[index];
}

// Setters
void MovieShelf::setMovie(Movie *m, int index)
{
    Movies[index] = m;
}

// Additional Functions
void MovieShelf::addMovie(Movie *M)
{
    if (MovieCount >= NUM_MOVIES) // When the shelf is full, addMovie throws custom exception
    {
        throw FullShelfException();
    }
    Movies[MovieCount] = M;
    MovieCount++;
}

Movie *MovieShelf::removeMovie() // When the shelf is empty, removeMovie throws custom exception
{
    if (MovieCount <= 0)
    {
        throw EmptyShelfException();
    }
    MovieCount--;
    Movie *returnMovie = Movies[MovieCount];
    return returnMovie;
}
