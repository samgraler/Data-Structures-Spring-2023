#pragma once
#ifndef _BST_
#define _BST_
#include <string>
#include "Node.h"
#include <vector>

using namespace std;

template <class T>
class BST
{

private:
    Node<T> *root;
    int size;
    vector<T> vect;

public:
    // Constructor
    BST();
    // Destructor
    ~BST();

    // Other methods
    T *Find(T key);

    void Insert(T inVal);

    // Remove Function
    T Remove(T key);

    // helper for remove
    T FindSmallestLarger(Node<T> *temp);

    int getSize(); // Finished

    vector<T> GetAllAscending();
    vector<T> GetAllDescending();
    void EmptyTree();
    void Print(Node<T> *temp); // Finished
    // void Flatten(Node<T> &troot);
    void InOrder(Node<T> *troot);

    // Methods for Balancing
    int Height(Node<T> *current);
    void RotateLeft(Node<T> *parent, Node<T> *pivot);
    void RotateRight(Node<T> *parent, Node<T> *pivot);
};

#endif