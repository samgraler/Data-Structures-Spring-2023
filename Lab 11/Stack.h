#pragma once
#include <string>

using namespace std;

class Stack
{
protected:
    int Top = 0;
    int* StackArray;

public:
    Stack(int MaxSize = 0);  // Default Constructor
    ~Stack(); // Destructor

    int Pop();

    void Push(int c);

    int getLength();

    bool isEmpty();
};