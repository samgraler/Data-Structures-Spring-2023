#pragma once
#include "MiddleOrderedList.h"
#include "MiddleOrderedList.cpp"
#include "SpacedOrderedList.h"
#include "SpacedOrderedList.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    /*
    int number = 1;
    int ans = 1;
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    SpacedOrderedList<int> SList = SpacedOrderedList<int>();
    while (ans != 0)
    {
        if (ans == 1)
        {
            cout << "Enter Number to add: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;

            // OList.addItem(number);
            // MList.addItem(number);
            SList.addItem(number);
            cout << SList.Print() << endl;
        }
        else if (ans == 2)
        {
            cout << "Enter Number to remove: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;
            // int x = OList.removeItem(number);
            // int x = MList.removeItem(number);
            int x = SList.removeItem(number);
            cout << SList.Print() << endl;
        }

        cout << "Enter 0 to quit, 1 to add, 2 to remove: " << endl;
        cout << "> ";
        cin >> ans;
        cout << endl;
    }
    */

    vector<int> rVector = {};
    vector<int> eVector = {};
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    SpacedOrderedList<int> SList = SpacedOrderedList<int>();
    int numCheck = 0;
    int x, y, z;

    for (int i = 0; i < 100; i++)
    {
        // cout << "Run " << i << endl; // start of one 'run' of the program
        for (int i = 0; i < 25; i++)
        {
            rVector.push_back((rand() % 101)); // random vector (things to add)
        }

        while (!rVector.empty() || !eVector.empty())
        {
            if (!eVector.empty()) // erase vector (things to remove)
            {
                if (((rand() % 20) + 1) > 10 && !rVector.empty() && !MList.isFull() && !OList.isFull() && !SList.isFull())
                { // Add Item Case
                    numCheck = (rand() % rVector.size());
                    // cout << "Add " << rVector[numCheck] << " Right: " << MList.getRight() << " Left: " << MList.getLeft() << endl;
                    // cout << MList.Print() << endl;
                    MList.addItem(rVector[numCheck]);
                    OList.addItem(rVector[numCheck]);
                    SList.addItem(rVector[numCheck]);
                    // cout << MList.Print() << endl << endl;
                    eVector.push_back(rVector[numCheck]);
                    swap(rVector[numCheck], rVector.back());
                    rVector.pop_back();
                }
                else // Remove Item Case
                {
                    numCheck = (rand() % eVector.size());
                    // cout << "Remove " << eVector[numCheck] << " Right: " << MList.getRight() << " Left: " << MList.getLeft() << endl;
                    // cout << "Cout Check" << endl;
                    // cout << MList.Print() << endl;
                    // cout << "Cout Check" << endl;
                    y = MList.removeItem(eVector[numCheck]);
                    x = OList.removeItem(eVector[numCheck]);
                    z = SList.removeItem(eVector[numCheck]);
                    // cout << MList.Print() << endl << endl;
                    swap(eVector[numCheck], eVector.back());
                    eVector.pop_back();
                }
            }
            else
            {
                numCheck = (rand() % rVector.size());
                // cout << "Add " << rVector[numCheck] << " Right: " << MList.getRight() << " Left: " << MList.getLeft() << endl;
                // cout << MList.Print() << endl << endl;
                MList.addItem(rVector[numCheck]);
                OList.addItem(rVector[numCheck]);
                SList.addItem(rVector[numCheck]);
                // cout << MList.Print() << endl << endl;
                eVector.push_back(rVector[numCheck]);
                swap(rVector[numCheck], rVector.back());
                rVector.pop_back();
            }
        }

        OList.MakeEmpty();
        MList.MakeEmpty();
        SList.MakeEmpty();
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