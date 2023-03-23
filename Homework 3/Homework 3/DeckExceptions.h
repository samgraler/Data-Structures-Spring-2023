#include <exception>
#include <string>

using namespace std;

class EmptyDeckException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The deck is empty.";
    }
};

class ItemNotFoundException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are looking for could not be found in the list";
    }
};

class EndOfDeckException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have reached the end of the list.";
    }
};