/*

// TASK 4 TESTING PROGRAM:

// This .cpp file contains the testing for task 4. Out of the three testing files in this project
// (Task3.cpp, Task4.cpp, Task5.cpp), two must be commented out at all times. To uncomment or comment out the
// the entire file, you need only remove or add the top block comment character.



#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedTable.cpp"
#include "Part.h"
#include <vector>

using namespace std;

vector<Part *> vect;
vector<int> part_vector;

void showMenu()
{
    cout << endl;
    cout << "0: Exit Testing" << endl;
    cout << "1: AddItem(Part*)" << endl;
    cout << "2: RemoveItem(Part*)" << endl;
    cout << "3: GetItem(Part*)" << endl;
    cout << "4: GetLength()" << endl;
    cout << "5: IsEmpty()" << endl;
}

Part *createPart()
{
    int S;
    int P;
    int Q;
    int L;
    string D;
    string U;
    cin.ignore();
    cout << "Please Add Info to Create a Part:" << endl;
    cout << "SKU > ";
    cin >> S;
    cout << endl;
    cout << "Price > ";
    cin >> P;
    cout << endl;
    cout << "Quanity on Hand (optional, enter 0 to skip) > ";
    cin >> Q;
    cout << endl;
    cout << "Lead Time (days to order) > ";
    cin >> L;
    cout << endl;
    cout << "Description > ";
    cin >> D;
    cout << endl;
    cout << "Unit of measure (ft, lb, per, etc...) > ";
    cin >> U;
    cout << endl;
    if (Q == 0)
    {
        return (new Part(D, U, S, P, L));
    }
    return (new Part(D, U, S, P, L, Q));
}

Part *FindPart() // finds part in list of parts the user has already added (prevents the user needing to input an entire part)
{
    int sku = 0;
    cout << "Enter the SKU number of the part you'd like to retrieve / locate. This must be a part you have already created." << endl;
    cout << "> ";
    cin >> sku;
    cout << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i)->GetSKU() == sku)
        {
            return (vect.at(i));
        }
    }
    return (nullptr);
}

int main()
{
    
    int ans = 1;
    int MenuAns = 0;

    LinkedTable<Part> *Table = new LinkedTable<Part>();

    showMenu(); // gives choices
    cout << "> ";
    cin >> MenuAns;

    Part *p = nullptr;
    bool e = true;
    int l = 0;

    while (ans != 0)
    {
        cout << endl;
        switch (MenuAns)
        {
        case 1: // add
            p = createPart();
            vect.push_back(p);
            Table->AddItem(p);
            break;
        case 2: // remove
            p = FindPart();
            if (p == nullptr)
            {
                cout << "This part could not be found in your list." << endl;
            }
            else
            {
                Part *RetPart = Table->RemoveItem(p);
                cout << RetPart->GetPartInfo() << endl;
            }
            break;
        case 3: // get item
            p = FindPart();
            if (p == nullptr)
            {
                cout << "The SKU number does not match a part that you have created." << endl;
            }
            else
            {
                Part *RetPart = Table->GetItem(p);
                cout << RetPart->GetPartInfo() << endl;
            }
            break;
        case 4: // size
            cout << "Your List has " << Table->GetLength() << " parts in it." << endl;
            break;
        case 5: // is empty
            e = Table->isEmpty();
            if (e)
            {
                cout << "Your list is empty." << endl;
            }
            else
            {
                cout << "Your list isn't empty." << endl;
            }
            break;
        default:
            ans = 0;
            break;
        }

        if (ans != 0)
        {
            showMenu(); // gives choices
            cout << "> ";
            cin >> MenuAns;
        }
    }

    delete p;

    return 0;
}

// */