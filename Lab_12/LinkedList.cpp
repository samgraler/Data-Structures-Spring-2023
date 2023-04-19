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
void LinkedList<T>::AddItem(T *item) // only changes current if inserting to an empty list
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
T *LinkedList<T>::GetItem(T *item)
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

    T *ret = new T(temp->data);

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
        throw EmptyListException();
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
T *LinkedList<T>::SeePrev()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (current == nullptr || current->prev == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->prev;
    return (current->data);
}

template <class T>
T *LinkedList<T>::SeeAt(int l)
{
    if (l >= length)
    {
        throw EndOfListException();
    }
    if (isEmpty())
    {
        throw EmptyListException();
    }
    Node<T> *temp = head;
    for (int i = 0; i < l; i++)
    {
        temp = temp->next;
    }
    return (temp);
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

// swaps elements at 'index' i and j so the indexing for sorts can still be used
template <class T>
void LinkedList<T>::Swap(int i, int j)
{
    if (i >= length || j >= length)
    {
        throw EndOfListException();
    }
    if (isEmpty())
    {
        throw EmptyListException();
    }
    Node<T>* temp1 = head;
    Node<T>* temp2 = head;
    for (int k = 0; k < i; k++)
    {
        temp1 = temp1->next;
    }
    for (int k = 0; k < i; k++)
    {
        temp2 = temp2->next;
    }
    T* temp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = temp;
}

template <class T>
void LinkedList<T>::BubbleSort(int key, bool ascending){
    if (isEmpty())
    {
        throw EmptyListException();
    }
    if (length == 1)
    {
        return;
    }
    bool swapped;
    for (int i = 0; i < length; i++)
    {
        swapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            Node<T>* temp1 = head;
            Node<T>* temp2 = head;
            for (int k = 0; k < j; k++)
            {
                temp1 = temp1->next;
            }
            for (int k = 0; k < j + 1; k++)
            {
                temp2 = temp2->next;
            }
            if (temp1->data->getData(key) > temp2->data->getData(key))
            {
                if (ascending)
                {
                    Swap(j, j + 1);
                    swapped = true;
                }
            }
            else
            {
                if (!ascending)
                {
					Swap(j, j + 1);
                    swapped = true;
				}
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}