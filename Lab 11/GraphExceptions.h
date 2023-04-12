#pragma once
#include <exception>
#include <string>

using namespace std;

class IndexOutOfBoundsException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have entered an index that is not within the bounds of the graph";
    }
};

class DuplicateEdgeException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The edge you are attempting to add already exists";
    }
};