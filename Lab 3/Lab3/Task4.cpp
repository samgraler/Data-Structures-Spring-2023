#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include "Distance.h"

using namespace std;

void showOperatorMenu()
{
    cout << "Which operation would you like to test? (Enter a number 0-5):" << endl;
    cout << "(0) Addition (+)" << endl;
    cout << "(1) Subtraction (-)" << endl;
    cout << "(2) Multiplication (*)" << endl;
    cout << "(3) Division (/)" << endl;
    cout << "(4) to_string (str)" << endl;
    cout << "(5) Equivalence (==)" << endl;
}

int main()
{
    int ans = 1;
    double x1 = 0;
    double x2 = 0;
    int operation = 0;

    cout << "All calculations are performed according to the value stored for meters." << endl;
    cout << "Because of this, only an x value is needed for input (instead of x for feet and y for inches)" << endl;
    cout << "Feet and inch value are adjusted according to the value for meters." << endl;
    cout << endl;
    cout << "Please enter x for the first distance (in meters): ";
    cin >> x1;
    cout << endl;
    // while (!isdigit(x1))
    // {
    //     cout << "Please enter a numerical x: ";
    //     cin >> x1;
    // }

    Distance D1 = Distance(x1);
    while (ans == 1)
    {
        showOperatorMenu();

        cin >> operation;
        while (!0 && !1 && !2 && !3 && !4 && !5)
        {
            cout << "Please enter a numerical option: ";
            cin >> operation;
        }

        Distance D2 = Distance();

        if (operation != 4)
        {
            cout << "Please enter x for the second distance (in meters): ";
            cin >> x2;
            cout << endl;
            // while (!isdigit(x2))
            // {
            //     cout << "Please enter a numerical x: ";
            //     cin >> x2;
            // }
            D2.setMeters(x2);
        }

        switch (operation)
        {
        case 0:
            D1 + D2;
            break;
        case 1:
            D1 - D2;
            break;
        case 2:
            D1 * D2;
            break;
        case 3:
            D1 / D2;
            break;
        case 4:
            cout << D1;
            break;
        case 5:
            string s = (D1 == D2) ? "True" : "False";
            cout << s << endl;
            break;
        }

        D1.print();

        cout << "Would you like to test another operation? (Enter '1' for Yes, anything else for No): ";
        cin >> ans;
    }

    return 0;
}