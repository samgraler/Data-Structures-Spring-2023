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

    // Rebalance
}

template <class T>
T *BST<T>::Find(T key) // DONE
{
    if (size = 0)
    {
        throw EmptyTreeException();
    }
    Node<T> *temp = root;
    while (true)
    {
        if (temp == nullptr)
        { // not found case
            return nullptr;
        }
        if (temp->data == key)
        { // found case
            return temp;
        }
        if (temp->data > key)
        { // move right case
            temp = temp->right;
        }
        else
        { // move left case
            temp = temp->left;
        }
    }
}

template <class T>
T Remove(T key)
{
    if (isEmpty()) // empty tree case
    {
        throw EmptyTreeException();
    }
    if (Find(key) == nullptr) // not found case
    {
        throw ItemNotFoundException();
    }
    if (root->data == key) // root case
    {
        // probably replace with right or left child
    }

    // Other Cases

    Node<T> *temp = root;
    Node<T> *to_delete = nullptr;
    T retval;

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

    if (temp->left == nullptr && temp->right == nullptr) // LEAF CASE
    {
        if (temp->left != nullptr && temp->left->data == key) // left child is the target
        {
            retval = temp->left->data;
            delete temp->left;
            temp->left = nullptr;
        }
        else // right child is the target
        {
            retval = temp->right->data;
            delete temp->right;
            temp->right = nullptr;
        }
    }
    else if (temp->left != nullptr && temp->right != nullptr) // 2 CHILDREN CASE
    {
        // set to_delete
        if (temp->left != nullptr && temp->left->data == key) // left child is the target
        {
            to_delete = temp->left;
        }
        else // right child is the target
        {
            to_delete = temp->right;
        }

        T replaceval = FindSmallestLarger(to_delete->right);
        T removeval = Remove(replaceval); // will always be a leaf, so recursive remove call should return pretty quickly
        retval = to_delete->data;
        to_delete->data = removeval;
    }
    else // 1 CHILD CASE
    {
        if (key < temp->data) // left child is the target
        {
            to_delete = temp->left;
            if ((to_delete)->left != nullptr) // to_delete has left child
            {
                temp->left = to_delete->left;
                retval = to_delete->data;
                delete to_delete;
            }
            else // to_delete has right child
            {
                temp->left = to_delete->right;
                retval = to_delete->data;
                delete to_delete;
            }
        }
        else // right child is the target
        {
            to_delete = temp->right;
            if ((to_delete)->left != nullptr)
            { // to_delete has left child
                temp->left = to_delete->left;
                retval = to_delete->data;
                delete to_delete;
            }
            else
            { // to_delete has right child
                temp->left = to_delete->right;
                retval = to_delete->data;
                delete to_delete;
            }
        }
    }

    size--;

    // call balancing methods

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
void BST<T>::Print(Node<T> *toprint) // method was written in class (might work but is not necessary for lab)
{
    if (toprint == nullptrptr)
    {
        return;
    }

    cout << toprint->data << " (";
    if (toprint->left != nullptrptr)
    {
        cout << toprint->left->data;
    }
    cout << ", ";
    if (toprint->right != nullptr)
    {
        cout << toprint->right->data;
        cout << " )" << endl;
        print(toprint->left);
    }
    print(toprint->right);
}

template <class T>
int BST<T>::getSize() // Done
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
    if (troot == null)
    {
        return;
    }
    InOrder(troot->left);
    vect.push_back(troot->data);
    InOrder(troot->right);
}

// Methods for Rotation

template <class T>
int BST<T>::Height(Node<T> *current)
{
    if (current = nullptr)
    {
        return 0;
    }
    int L = height(current->left);
    int R = height(current->right);

    if (L-R >= 2){
        // left rotate balance
        L--;
        R++;
    }
    else if(L-R <= -2){
        // right rotate balance
        L++;
        R--;
    }

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
    { // if pivot is the root
      // figure it out
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
    { // if pivot is the root
      // figure it out
    }
    else if (parent->left == pivot)
    { // if pivot is the left child of the parent
        parent->left = pivot->left;
        pivot->left = pivot->left->right;
        parent->left->right = pivot;
    }
    else
    { // if pivot is the right child of the parent
        parent->right = pivot->right;
        pivot->right = pivot->right->left;
        parent->right->left = pivot;
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