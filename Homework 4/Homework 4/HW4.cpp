#include "HashTable.cpp"
#include "TwoDHash.h"
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "BST.cpp"
#include "BST.h"

using namespace std;

vector<int> vect;

void MakeRandomVector()
{
    srand(time(NULL));
    while (vect.size() < 101)
    {
        int tempInt = (rand() % 10000) + 1;
        vector<int>::iterator it = find(vect.begin(), vect.end(), tempInt);
        if (it != vect.end()){
            continue;
        }
        vect.push_back(tempInt);
    }
}

void showMenu()
{
    cout << endl;
    cout << "0: Exit Testing" << endl;
    cout << "1: Insert(int*)" << endl;
    cout << "2: Find" << endl;
    cout << "3: Remove(int*)" << endl;
    cout << "4: Print()" << endl;
}

int getInt()
{
    int i = 0;
    cout << "Enter the value: " << endl;
    cout << "> ";
    cin >> i;
    return (i);
}

int BinaryChecks, HashChecks, Hash2Checks, TBinaryChecks, THashChecks, THash2Checks; // global check variables

void UpdateChecks(BST<int>* t)
{
    BinaryChecks = t->getChecks();

    TBinaryChecks += BinaryChecks;
    THashChecks += HashChecks;
    THash2Checks += Hash2Checks;

    cout << "Binary Tree Checks: " << BinaryChecks << endl;
    cout << "Hash Table Checks: " << HashChecks << endl;
    cout << "2D Hash Table Checks: " << Hash2Checks << endl;

    BinaryChecks = 0;
    t->ResetChecks();
    HashChecks = 0;
    Hash2Checks = 0;
}

int main()
{
    system("Color 0A");

    //initializes list of random items for all 3 data structures
    MakeRandomVector();

    // split vector into two sets of 50
    vector<int> sub1, sub2;
    for (int i = 0; i < 50; i++) {
        sub1.push_back(vect[i]);
        sub2.push_back(vect[i + 50]); 
    }

    // create data structures
    HashTable<int>* hash = new HashTable<int>();
    TwoDHash* hash2 = new TwoDHash();
    BST<int>* tree = new BST<int>();

    BinaryChecks = HashChecks = Hash2Checks = TBinaryChecks = THashChecks = THash2Checks = 0;

    // insert first 50

    for (int x = 0; x < 50; x++) {
        HashChecks += hash->Insert(new int(sub1[x]));
        Hash2Checks += hash2->Insert(sub1[x]);
        tree->Insert(sub1[x]);
    }
    
    cout << "Initial 50 Insertion" << endl;
    UpdateChecks(tree);

    // remove first 50, only removes  mod 7 =0 values
    for(int i = 0; i < 50; i++){
        if (i % 7 == 0) {
            HashChecks += hash->Remove(new int(sub1[i]));
            Hash2Checks += hash2->Remove(sub1[i]);
            tree->Remove(sub1[i]);
        }
    }

    cout << "\nInitial 50 Removal" << endl;
    UpdateChecks(tree);

    // insert last 50
	for (int x = 0; x < 50; x++) {
        HashChecks += hash->Insert(new int(sub2[x]));
        Hash2Checks += hash2->Insert(sub2[x]);
        tree->Insert(sub2[x]);
    }

    cout << "\nSecondary 50 Insertion" << endl;
    UpdateChecks(tree);

    // find last 50
    for (int x = 0; x < 50; x++) {
        if (x % 9 == 0) {//finds only values where x mod 9 = 0
            HashChecks += hash->Find(new int(sub2[x]));
            Hash2Checks += hash2->Find(sub2[x]);
            tree->Find2(sub2[x]);
        }
    }

    cout << "\nSecondary 50 Find" << endl;
    UpdateChecks(tree);

    // Prints all 3 data structures' total checks
    cout << "\n__Total Checks__" << endl;
    cout << "Hash Table: " << THashChecks << endl;
    cout << "2D Hash Table: " << THash2Checks << endl;
    cout << "Binary Tree: " << TBinaryChecks << endl;

    return 0;
}










/*
int main()
{
    int ans = 1;
    int MenuAns = 0;

    TwoDHash* Table = new TwoDHash();

    int val = 0;
    int checks = 0;



    //while (ans != 0)
    //{
    //    showMenu(); // gives choices
    //    cout << "> ";
    //    cin >> MenuAns;

    //    if (MenuAns != 4)
    //    {
    //        val = getInt();
    //    }
        
    //    cout << endl;
    //    switch (MenuAns)
    //    {
    //    case 1: // add
    //        checks = Table->Insert(val);
    //        cout << "This operation took " << checks << " checks to find the correct location" << endl;
    //        break;
    //    case 2: // Find
    //        checks = Table->Find(val);
    //        break;
    //    case 3: // remove
    //        checks = Table->Remove(val);
    //        break;
    //    case 4: // print
    //        Table->Print();
    //    default:
    //        ans = 0;
    //        break;
    //    }
    //}

    return 0;
}
*/