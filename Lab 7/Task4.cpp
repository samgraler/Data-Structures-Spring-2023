#pragma once
#include "MiddleOrderedList.h"
#include "MiddleOrderedList.cpp"
#include "SpacedOrderedList.h"
#include "SpacedOrderedList.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> rVector = {};
    vector<int> eVector = {};
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    SpacedOrderedList<int> SList = SpacedOrderedList<int>();
    int numCheck = 0;

    for (int i = 0; i < 100; i++)
    {
        // start of one 'run' of the program

        for (int i = 0; i < 25; i++)
        {
            rVector.push_back((rand() % 101)); // random vector (things to add)
        }

        while (!rVector.empty())
        {
            if (!eVector.empty()) // erase vector (things to remove)
            {
                if (((rand() % 1)) == 1)
                { // Add Item Case
                    numCheck = (rand() % rVector.size());
                    OList.addItem(rVector[numCheck]);
                    MList.addItem(rVector[numCheck]);
                    SList.addItem(rVector[numCheck]);
                    eVector.push_back(rVector[numCheck]);
                    swap(rVector[numCheck], rVector.back());
                    rVector.pop_back();
                }
                else // Remove Item Case
                {
                    numCheck = (rand() % eVector.size());
                    OList.removeItem(eVector[numCheck]);
                    MList.removeItem(eVector[numCheck]);
                    SList.removeItem(eVector[numCheck]);
                    swap(eVector[numCheck], eVector.back());
                    eVector.pop_back();
                }
            }
            else
            {
                numCheck = (rand() % rVector.size());
                OList.addItem(rVector[numCheck]);
                MList.addItem(rVector[numCheck]);
                SList.addItem(rVector[numCheck]);
                eVector.push_back(rVector[numCheck]);
                swap(rVector[numCheck], rVector.back());
                rVector.pop_back();
            }
        }
    }
    cout << "OrderedList Stats: " << endl;
    cout << OList.PrintStats() << endl
         << endl;
    cout << "MiddleOrderedList Stats: " << endl;
    cout << MList.PrintStats() << endl
         << endl;
    cout << "SpacedOrderedList Stats: " << endl;
    cout << SList.PrintStats() << endl
         << endl;
}