#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class EmptyShelfException : public std::exception
{
public:
    string what() // overrides what() virtual function from std::exception that returns an explanatory string
    {
        return "The Shelf Was Empty! You cannot remove a movie from an empty shelf.";
    }
};