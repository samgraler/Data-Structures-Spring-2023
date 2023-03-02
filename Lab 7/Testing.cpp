#pragma once
#include "MiddleOrderedList.h"
#include "MiddleOrderedList.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    int number = 1;

    while (number != 0)
    {

        cout << "Enter Number for List: " << endl;
        cout << "> ";
        cin >> number;
        cout << endl;

        OList.addItem(number);
        // MList.addItem(number);
        cout << OList.Print() << endl;
    }
}