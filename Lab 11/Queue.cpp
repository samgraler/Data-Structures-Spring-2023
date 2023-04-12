#pragma once
#include "Queue.h"

Queue::Queue()
{
    head = nullptr;
}

Queue::~Queue()
{
}

void Queue::Enqueue(int inVal)
{
    if (isEmpty())
    {
        head = new Node<int>(new int(inVal));
    }
    else
    {
        Node<int>* h = new Node<int>(new int(inVal));
        h->next = head;
        head = h;
    }
    length++;
}

int Queue::Dequeue()
{
    if (isEmpty())
    {
        throw EmptyQueueException();
    }
    if (length == 1)
    {
        int retval = head->getData();
        delete head;
        head = nullptr;
        length--;
        return retval;
    }
    Node<int>* temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    int retval = temp->next->getData();
    delete temp->next;
    temp->next = nullptr;
    length--;
    return retval;
}

bool Queue::isEmpty()
{
    if (length == 0)
    {
        return true;
    }
    return false;
}

int Queue::getLength() {
    return length;
}
