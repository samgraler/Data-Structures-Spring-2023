#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Part.h"
#include <vector>

using namespace std;

vector<Part*> vect;

void showMenu()
{
    cout << endl;
    cout << "0: Exit Testing" << endl;
    cout << "1: AddItem(Part*)" << endl;
    cout << "2: GetItem(Part*)" << endl; // need to fix
    cout << "3: IsInList(Part*)" << endl;
    cout << "4: isEmpty()" << endl;
    cout << "5: Size()" << endl;
    cout << "6: SeeNext()" << endl;
    cout << "7: SeePrev()" << endl;
    cout << "8: SeeAt(int)" << endl; // need to fix
    cout << "9: Reset()" << endl;
    cout << "10: PrintAll() (display function)" << endl;
}

Part* createPart()
{
    int S;
    int P;
    int Q;
    int L;
    string D;
    string U;
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
    cin.ignore();
    getline(cin, D);
    cout << endl;
    cout << "Unit of measure (ft, lb, per, etc...) > ";
    cin >> U;
    cout << endl;
    if (Q == 0)
    {
        return(new Part(D, U, S, P, L));
    }
    return(new Part(D, U, S, P, L, Q));
}

Part* FindPart()
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
            return(vect.at(i));
        }
    }
    return (nullptr);
}

int main()
{
    int ans = 1;
    int MenuAns = 0;

    LinkedList<Part>* LList = new LinkedList<Part>();
    showMenu(); // gives choices
    cin >> MenuAns;

    Part* p = nullptr;
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
            LList->AddItem(p);
            break;
        case 2: // get
            p = FindPart();
            if (p == nullptr)
            {
                cout << "The SKU number does not match a part that you have created." << endl;
            }
            else {
                Part* RetPart = nullptr;
                try {
                    RetPart = LList->GetItem(p);
                    cout << RetPart->GetPartInfo() << endl;
                }
                catch (EmptyListException ex)
                {
                    cout << ex.what();
                }
                catch (ItemNotFoundException ex)
                {
                    cout << ex.what();
                }
            }
            break;
        case 3: // is in list
            try {
                e = LList->IsInList(FindPart());
                if (e) {
                    cout << "Your part exists in the system." << endl;
                }
                else {
                    cout << "Your part doesn't exist in the system." << endl;
                }
            }
            catch (EmptyListException ex)
            {
                cout << ex.what();
            }
            break;
        case 4: // is empty
            e = LList->isEmpty();
            if (e) {
                cout << "Your list is empty." << endl;
            }
            else {
                cout << "Your list isn't empty." << endl;
            }
            break;
        case 5: // size
            cout << "Your List has " << LList->Size() << " parts in it." << endl;
            break;
        case 6: // see next
            try {
                p = LList->SeeNext();
                if (p == nullptr)
                {
                    cout << "You have reached past the tail of the list" << endl;
                    break;
                }
                cout << p->GetPartInfo() << endl;
            }
            catch (EmptyListException ex) {
                cout << ex.what();
            }
            break;
        case 7: // see prev
            try {
                p = LList->SeePrev();
                if (p == nullptr)
                {
                    cout << "You have reached past the head of the list" << endl;
                    break;
                }
                cout << p->GetPartInfo() << endl;
            }
            catch (EmptyListException ex) {
                cout << ex.what();
            }
            break;
        case 8: // see at
            cout << "Enter the location in the list you'd like to see (index). Size of linked list is " << LList->Size() << endl;
            cin >> l;
            try {
                p = LList->SeeAt(l);
                cout << p->GetPartInfo() << endl;
            }
            catch (EndOfListException ex)
            {
                ex.what();
            }
            catch (EmptyListException ex)
            {
                ex.what();
            }
            break;
        case 9: // reset
            LList->Reset();
            break;
        case 10: // print all
            try {
                LList->PrintAll();
            
            }
            catch (EmptyListException ex)
            {
                ex.what();
            }
            break;
        default:
            ans = 0;
            break;
        }

        if (ans != 0) {
            showMenu(); // gives choices
            cin >> MenuAns;
        }
    }

    delete p;

    return 0;
}