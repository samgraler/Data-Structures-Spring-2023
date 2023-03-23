#include <exception>
#include <string>

using namespace std;

class SideDeckUnderflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The side deck is empty.";
    }
};

class SideDeckOverflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The side deck is full.";
    }
};