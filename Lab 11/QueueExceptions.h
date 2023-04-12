#include <exception>
#include <string>

using namespace std;

class EmptyQueueException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Queue is empty.";
    }
};

class ItemNotFoundExceptionQ : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The item you are looking for could not be found in the queue.";
    }
};

class EndOfQueueException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "You have reached the end of the queue.";
    }
};