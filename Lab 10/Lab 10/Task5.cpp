

// TASK 5 TESTING PROGRAM:

// This .cpp file contains the testing for task 3. Out of the three testing files in this project
// (Task3.cpp, Task4.cpp, Task5.cpp), two must be commented out at all times. To uncomment or comment out the
// the entire file, you need only remove or add the top block comment character.


#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedTable.cpp"
#include "Part.h"
#include <vector>
#include <cstdlib>

using namespace std;

vector<Part*> sku_vector;

int main()
{
    char ans1 = 'Y';

    while (ans1 == 'Y')
    {
        int ans = 1;

        cout << "Desired number of parts:" << endl;
        cout << "> ";
        cin >> ans;

        LinkedTable<Part>* Table1 = new LinkedTable<Part>(ans);
        HashTable<Part>* Table2 = new HashTable<Part>(ans);

        srand((unsigned)time(NULL));

        Part* p = nullptr;
        for (int i = 0; i < ans; i++) {
            int RSKU = 10000000 + (rand() % 99999999);
            string D = "Part_";
            D += to_string(i);
            p = new Part(D, "Ft", RSKU, i, 2, 1);
            sku_vector.push_back(p);
            Table1->AddItem(p);
            Table2->AddItem(p);
        }

        for (int i = 0; i < ans; i++) {
            p = Table1->GetItem(sku_vector.front());
            p = Table2->GetItem(sku_vector.front());
            sku_vector.erase(sku_vector.begin());
        }

        cout << "Linked Hash Table Comparisons for " << ans << " items: " << Table1->getComps() << endl;
        cout << "Hash Table Comparisons for " << ans << " items: " << Table2->getComps() << endl << endl;;
        cout << "Run again? (Y/N):" << endl;
        cout << "> ";
        cin >> ans1;
        cout << endl;

        Table1->ResetComps();

        delete Table1;
        delete Table2;
    }
    return 0;
}

// */