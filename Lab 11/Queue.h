#pragma once
#include <string>
#include "QueueExceptions.h"
#include "Node.cpp"

using namespace std;

class Queue
{
private:
    Node<int>* head = nullptr;
    int length = 0;

public:
    Queue();
    ~Queue();

    int Dequeue();
    void Enqueue(int inval);
    int getLength();
    bool isEmpty();
};