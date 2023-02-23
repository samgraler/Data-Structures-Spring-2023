#pragma once
#include <exception>
#include <string>

using namespace std;

class QueueOverflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Queue is Full! You cannot add something to a full Queue.";
    }
};

class QueueUnderflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Queue is Empty! You cannot remove something from an empty Queue / there is no top item to peek at.";
    }
};