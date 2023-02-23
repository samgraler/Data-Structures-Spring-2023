#pragma once
#include <exception>
#include <string>

using namespace std;

class StackOverflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Stack is Full! You cannot add something to a full stack.";
    }
};

class StackUnderflowException : public std::exception
{
public:
    string what() // overrides what() virtual function from exception that returns an explanatory string
    {
        return "The Stack is Empty! You cannot remove something from an empty stack / there is no top item to peek at.";
    }
};