#include "LinkedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    current = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
}

template <class T>
void LinkedList<T>::Insert(T *item) // only changes current if inserting to an empty list
{
    if (isEmpty())
    { // empty list case
        head = new Node<T>(item);
        length++;
        current = head;
    }
    else if ((*item) < (*head->data))
    { // head case
        Node<T> *h = new Node<T>(item);
        h->next = head;
        h->prev = nullptr;
        head->prev = h;
        head = h;
        length++;
    }
    else
    { // insert middle and tail cases
        Node<T> *temp = head;
        while ((temp->next != nullptr) && ((*temp->next->data) < (*item)))
        {
            temp = temp->next;
        }
        if (temp->next == nullptr) // tail case
        {
            Node<T> *newNode = new Node<T>(item);
            newNode->next = nullptr;
            newNode->prev = temp;
            temp->next = newNode;
            length++;
        }
        else // middle case
        {
            Node<T> *newNode = new Node<T>(item);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }
    }
}

template <class T>
T *LinkedList<T>::Remove(T *item)
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (!IsInList(item))
    {
        throw ItemNotFoundException();
    }

    Node<T> *temp = head;

    while ((*temp->data) != (*item))
    {
        temp = temp->next;
    }

    T *ret = temp->data;

    if (temp->prev == nullptr)
    { // head case
        if (length == 1)
        {
            head = nullptr;
            current = nullptr;
            delete temp;
            length--;
            return (ret);
        }

        if (temp->next != nullptr)
        {
            head = temp->next;
            head->prev = nullptr;
        }

        if (temp == current)
        {
            current = temp->next;
        }
    }
    else if (temp->next == nullptr)
    { // tail case
        if (temp == current)
        {
            current = temp->prev;
        }
        temp->prev->next = nullptr;
    }
    else
    { // middle case
        if (temp == current)
        {
            if (temp->next == nullptr)
            {
                current = temp->prev;
            }
            current = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    length--;
    return ret;
}

template <class T>
bool LinkedList<T>::IsInList(T *item)
{
    if (isEmpty())
    {
        return false;
    }
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (*temp->data == *item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return (true);
    }
    return (false);
}

template <class T>
int LinkedList<T>::Size()
{
    return length;
}

template <class T>
T *LinkedList<T>::SeeNext()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (current == nullptr || current->next == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->next;
    return (current->data);
}

template <class T>
T *LinkedList<T>::SeeAt() // not required but makes more sense
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    return (current->data);
}

template <class T>
void LinkedList<T>::Reset()
{
    current = head;
}

template <class T> 
void LinkedList<T>::Print()
{
    if (isEmpty())
    {
        cout << "None" << endl;
        return;
    }
    Node<T> *temp = head;
    while (temp->next != nullptr)
    {
        cout << *(temp->data) << " ";
        temp = temp->next;
    }
    cout << *(temp->data) << endl;
}