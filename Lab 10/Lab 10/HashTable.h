#pragma once
#ifndef _LHT_
#define _LHT_
#include <string>
#include <vector>

using namespace std;

template <class T>
class HashTable
{

protected:
    int MAX_SIZE = 100;
    T **arr;
    bool *deleted; // initialize to false
    int numItems = 0;
    int comparisons = 0;

public:
    HashTable(int s = 100);
    ~HashTable();
    int Hash(string s);
    void AddItem(T *inval);
    T *RemoveItem(T *key);
    int Find(T *key);
    T *GetItem(T *key);
    int GetLength();
    bool isEmpty();
    int getComps();
};

#endif