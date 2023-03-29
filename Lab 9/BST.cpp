#pragma once
#include "BST.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
BST<T>::BST()
{
    root = nullptr;
    size = 0;
}

template <class T>
BST<T>::~BST()
{
}

template <class T>
bool BST<T>::isEmpty()
{
    if (this->size == 0)
    {
        return true;
    }
    return false;
}

template <class T>
Node<T> *BST<T>::getRoot()
{
    return (root);
}

template <class T>
void BST<T>::Insert(T inVal)
{
    if (root == nullptr)
    {
        Node<T> *temp = new Node<T>(inVal);
        root = temp;
    }
    else
    {
        Node<T> *temp = new Node<T>(inVal);
        temp = root;
        while (((inVal < temp->data) && (temp->left != nullptr)) || ((inVal >= temp->data) && (temp->right != nullptr)) && (inVal != temp->data))
        {
            if (inVal < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (inVal == temp->data)
        {
            throw DuplicateItemException();
        }

        if (inVal < temp->data)
        {
            temp->left = new Node<T>(inVal);
        }
        else
        {
            temp->right = new Node<T>(inVal);
        }
    }
    size++;

    Height(root, nullptr);

}

template <class T>
T *BST<T>::Find(T key) // returns pointer to data of the node (could be edited to return entire node if needed
{
    if (size == 0)
    {
        throw EmptyTreeException();
    }
    Node<T> *temp = root;
    T *retval;
    while (true)
    {
        if (temp == nullptr)
        { // not found case
            return nullptr;
        }
        if (temp->data == key)
        { // found case
            retval =  &(temp->data);
            return retval;
        }
        if (temp->data > key)
        { // move right case
            temp = temp->left;
        }
        else
        { // move left case
            temp = temp->right;
        }
    }
}

template <class T>
T BST<T>::Remove(T key)
{
    if (isEmpty()) // empty tree case
    {
        throw EmptyTreeException();
    }
    if (Find(key) == nullptr) // not found case
    {
        throw ItemNotFoundException();
    }

    Node<T> *temp = root;
    Node<T> *to_delete = nullptr;
    T retval;

    if (root->data == key) // root case
    {
        retval = root->data;
        if (root->right != nullptr) // right child exists
        {
            T replaceval = FindSmallestLarger(root->right);
            T removeval = Remove(replaceval);
            size++;
            root->data = removeval;
        }
        else if (root->left != nullptr) // left child exists
        {
            T replaceval = FindLargestSmaller(root->left);
            T removeval = Remove(replaceval);
            size++;
            root->data = removeval;
        }
        else // no children
        {
            EmptyTree();
        }

        Height(root, nullptr);

        size--;
        return (retval);
    }

    // Other cases

    // While loop to find the parent of the Node<T> we wish to remove
    while ((temp->left != nullptr && temp->left->data != key) || (temp->right != nullptr && temp->right->data != key))
    {
        if (temp->data < key && temp->right->data != key)
        {
            temp = temp->right;
        }
        else if (temp->data > key && temp->left->data != key)
        {
            temp = temp->left;
        }
        else
        {
            break;
        }
    }

    // Figure out how many children our target Node<T> has and run appropriate remove procedure

    if (temp->left != nullptr && temp->left->data == key) // Left child is the target
    {
        if (temp->left->left == nullptr && temp->left->right == nullptr) // leaf case
        {
            retval = temp->left->data;
            delete temp->left;
            temp->left = nullptr;
        }
        else if (temp->left->left != nullptr && temp->left->right != nullptr) // two children case
        {
            to_delete = temp->left;
            T replaceval = FindSmallestLarger(to_delete->right);
            T removeval = Remove(replaceval); // will always be a leaf, so recursive remove call should return pretty quickly
            size++;
            retval = to_delete->data;
            to_delete->data = removeval;
        }
        else // one child case
        {
            to_delete = temp->left;
            if ((to_delete)->left != nullptr) // to_delete has left child
            {
                temp->left = to_delete->left;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
            else // to_delete has right child
            {
                temp->left = to_delete->right;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
        }
    }
    else // Right child is the target
    {
        if (temp->right->left == nullptr && temp->right->right == nullptr) // leaf case
        {
            retval = temp->right->data;
            delete temp->right;
            temp->right = nullptr;
        }
        else if (temp->right->left != nullptr && temp->right->right != nullptr) // two children case
        {
            to_delete = temp->right;
            T replaceval = FindSmallestLarger(to_delete->right);
            T removeval = Remove(replaceval); // will always be a leaf, so recursive remove call should return pretty quickly
            size++;
            retval = to_delete->data;
            to_delete->data = removeval;
        }
        else // one child case
        {
            to_delete = temp->right;
            if ((to_delete)->left != nullptr)
            { // to_delete has left child
                temp->left = to_delete->left;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
            else
            { // to_delete has right child
                temp->left = to_delete->right;
                retval = to_delete->data;
                to_delete->left = nullptr;
                to_delete->right = nullptr;
                delete to_delete;
            }
        }
    }

    size--;

    Height(root, nullptr);

    return retval;
}

template <class T>
T BST<T>::FindSmallestLarger(Node<T> *temp)
{
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp->data;
}

template <class T>
T BST<T>::FindLargestSmaller(Node<T> *temp)
{
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp->data;
}

template <class T>
void BST<T>::Print(Node<T> *toprint) // method was written in class (might work but is not necessary for lab)
{
    if (toprint == nullptr)
    {
        return;
    }

    cout << toprint->data << " (";
    if (toprint->left != nullptr)
    {
        cout << toprint->left->data;
    }
    cout << ", ";
    if (toprint->right != nullptr)
    {
        cout << toprint->right->data;
        cout << " )" << endl;
        Print(toprint->left);
    }
    else
    {
        cout << " )" << endl;
    }
    Print(toprint->right);
}

template <class T>
void BST<T>::PrintVect(vector<T> vects)
{
    for (int i = 0; i < vects.size(); i++)
    {
        cout << vects.at(i) << " ";
    }
}

template <class T>
int BST<T>::getSize()
{
    return (size);
}

template <class T>
vector<T> BST<T>::GetAllAscending()
{
    vect.clear();
    InOrder(root);
    return vect;
}

template <class T>
vector<T> BST<T>::GetAllDescending()
{
    vect.clear();
    InOrder(root);
    reverse(vect.begin(), vect.end());
    return vect;
}

template <class T>
void BST<T>::EmptyTree() // theoretically works by relying on a cascading destructor call caused by Node's destructor
{
    delete root;
}

template <class T>
void BST<T>::InOrder(Node<T> *troot) // function to traverse tree and insert nodes in least to greatest order in the vect member
{
    if (troot == nullptr)
    {
        return;
    }
    InOrder(troot->left);
    vect.push_back(troot->data);
    InOrder(troot->right);
}

// Methods for Rotation

template <class T>
int BST<T>::Height(Node<T> *current, Node<T> *parent)
{
    // base case
    if (current == nullptr)
    {
        return 0;
    }

    int L = Height(current->left, current);
    int R = Height(current->right, current);

    // logic to know when to rotate
    if (L - R >= 2)
    {
        if (current->left->left != nullptr)
        {
            RotateRight(parent, current);
            L--;
            R++;
        }
        else
        {
            RotateLeftRight(parent, current);
            L--;
            R++;
        }
    }
    else if (L - R <= -2)
    {
        if (current->right->right != nullptr)
        {
            RotateLeft(parent, current);
            L++;
            R--;
        }
        else
        {
            RotateRightLeft(parent, current);
            L++;
            R--;
        }
    }

    // more base cases
    if (L > R)
    {
        return L + 1;
    }
    return R + 1;
}

template <class T>
void BST<T>::RotateLeft(Node<T> *parent, Node<T> *pivot) // written in class, should work
{
    if (pivot == root)
    {
        root = pivot->right;
        pivot->right = root->left;
        root->left = pivot;
    }
    else if (parent->left == pivot)
    { // if pivot is the left child of the parent
        parent->left = pivot->right;
        pivot->right = pivot->right->left;
        parent->left->left = pivot;
    }
    else
    { // if pivot is the right child of the parent
        parent->right = pivot->right;
        pivot->right = pivot->right->left;
        parent->right->left = pivot;
    }
}

template <class T>
void BST<T>::RotateRight(Node<T> *parent, Node<T> *pivot) // inverse of what was written in class
{
    if (pivot == root)
    {
        root = pivot->left;
        pivot->left = root->right;
        root->right = pivot;
    }
    else if (parent->left == pivot)
    { // if pivot is the left child of the parent
        parent->left = pivot->left;
        pivot->left = pivot->left->right;
        parent->left->right = pivot;
    }
    else
    { // if pivot is the right child of the parent
        parent->right = pivot->left;
        pivot->left = pivot->left->right;
        parent->right->right = pivot;
    }
}

template <class T>
void BST<T>::RotateRightLeft(Node<T> *parent, Node<T> *pivot)
{
    if (pivot == root) // NOT DONE IN CLASS
    {
        root = pivot->right->left;
        pivot->right->left = root->right; // root->right to root->left
        root->right = pivot->right;
        pivot->right = root->left;
        root->left = pivot;
    }
    else if (pivot == parent->left) // pivot is left child of parent (in class)
    {
        parent->left = pivot->right->left; // start of case where pivot is the left of parent
        pivot->right->left = parent->left->right;

        parent->left->right = pivot->right;
        pivot->right = parent->left->left;

        parent->left->left = pivot;
    }
    else // pivot is right child of parent
    {
        parent->right = pivot->right->left; // start of case where pivot is the right of parent
        pivot->right->left = parent->right->right;

        parent->right->right = pivot->right;
        pivot->right = parent->right->left;

        parent->right->left = pivot;
    }
}

template <class T>
void BST<T>::RotateLeftRight(Node<T> *parent, Node<T> *pivot)
{
    if (pivot == root) // pivot is root (in class)
    {
        root = pivot->left->right;
        pivot->left->right = root->left;
        root->left = pivot->left;
        pivot->left = root->right;
        root->right = pivot;
    }
    else if (pivot == parent->left) // pivot is left child of parent
    {
        parent->left = pivot->left->right; // start of case where pivot is the left of parent
        pivot->left->right = parent->left->right;

        parent->left->left = pivot->left;
        pivot->left = parent->left->right;

        parent->left->right = pivot;
    }
    else // pivot is right child of parent
    {
        parent->right = pivot->left->right; // start of case where pivot is the right of parent
        pivot->left->right = parent->right->left;

        parent->right->left = pivot->left;
        pivot->left = parent->right->right;

        parent->right->right = pivot;
    }
}



// template <class T>
// void BST<T>::Flatten(Node<T> &troot)
// {
//     // base condition- return if root is nullptr or if it is a
//     // leaf node
//     if (troot == nullptr || troot->left == nullptr && troot->right == nullptr)
//         return;

//     // if root->left exists then we have to make it
//     // root->right
//     if (troot->left != nullptr)
//     {
//         // move left recursively
//         flatten(troot->left);
//         // store the node root->right
//         Node<T> *tmpRight = troot->right;
//         troot->right = troot->left;
//         delete troot->left;
//         troot->left = nullptr;

//         // find the position to insert the stored value
//         Node<T> *NInsert = troot->right;
//         while (NInsert->right != nullptr)
//             NInsert = NInsert->right;

//         // insert the stored value
//         NInsert->right = tmpRight;
//     }
//     // now call the same function for root->right
//     flatten(troot->right);
// }