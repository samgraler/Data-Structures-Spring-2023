#include "BST.h"
#include "BST.cpp"
#include "Word.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <random>
#include <fstream>

using namespace std;

BST<Word>* WordTree;

// <Schneider, Adrian> (<03/29/2023>) <Print Binary Tree> (1.0) [Source Code] https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
// The above statement applies for the next 2 functions 
template <class T>
void printBT(const std::string& prefix, const Node<T>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "'--" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

template <class T>
void printBT(const Node<T>* node) 
{
    printBT("", node, false);    
}

bool exists(const string& fileName) // Returns true if the filename passed in exists (function checks if a string of any kind is present in the file)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

void BodyFunction() // created to make main() more efficient and readable
{
    string fileName;
    ifstream targetFile;
    cout << "Please Enter the File Name (with extension): ";
    cin >> fileName;

    targetFile.open(fileName);

    while (!targetFile)
    {
        cout << "Error: The file with the name provided could not be opened." << endl;
        cout << "Please try again: ";
        cin >> fileName;
        targetFile.open(fileName);
    }

    string contentsWatch = ""; // string used to search for "Contents:" so the beginning of the actual text can be found

    while (contentsWatch != "Contents:" && contentsWatch != "Contents: " && contentsWatch != "Contents:\r" && contentsWatch != "Contents: \r")
    {
        getline(targetFile, contentsWatch);
    }

    int flag = 0;
    string w;
    string w1;

    while (!targetFile.eof())
    {
        targetFile >> w;
        w1 = "";
        for (int i = 0; i < w.length(); i++)
        {
			if (!isalpha(w.at(i))){
				continue;
			}
            w.at(i) = tolower(w.at(i));
            w1 += w.at(i);
        }
		Word tempWord = Word(w1, 1);
        try {
            WordTree->Find(tempWord);
        }
		catch(EmptyTreeException ex){
            WordTree->Insert(tempWord);
            continue;
		}
		
        Word* WordLocation = WordTree->Find(tempWord);
        if (WordLocation == nullptr)
        {
            WordTree->Insert(tempWord);
        }
        else
        {
            if (tempWord.getWord() == "me")
            {
                int x = 1;
            }
            WordLocation->setFreq(WordLocation->getFreq() + 1);
        }
    }

    printBT(WordTree->getRoot());
    //WordTree->PrintVect(WordTree->GetAllAscending());

    targetFile.close(); // close file

}

void OptionMenu() {

    int menuans = 0;
    string search = "";
    Word searchword;
    Word* searchloc;
    while (menuans == 0)
    {
        cout << endl;
        cout << "What would you like to do next?" << endl;
        cout << "(0) Search for a word (outputs frequency)" << endl;
        cout << "(1) GetAllAscending (list of elements in alphabetical order)" << endl;
        cout << "(2) GetAllDescending (list of elements in reverse alphabetical order)" << endl;

        cin >> menuans;

        switch (menuans) {
        case 0: // search
            cout << endl;
            cout << "What word would you like to search for?" << endl;
            cout << "> ";
            cin >> search;
            cout << endl;
            searchword = Word(search, 0);
            searchloc = WordTree->Find(searchword);
            if (searchloc == nullptr)
            {
                cout << "The word you searched for was not in the tree." << endl;
            }
            else
            {
                cout << "The given word appeared " << searchloc->getFreq() << " times." << endl;
            }
            break;
        case 1: // ascending
            cout << endl;
            WordTree->PrintVect(WordTree->GetAllAscending());
            break;
        case 2: // descending
            cout << endl;
            WordTree->PrintVect(WordTree->GetAllDescending());
            break;
        }

        cout << endl;
        cout << "Would you like to select another option?" << endl;
        cout << "(0) Yes" << endl;
        cout << "(1) No" << endl;

        cin >> menuans;
    }
}

int main()
{
    WordTree = new BST<Word>();
    char anotherBook = 'Y'; 
   
    BodyFunction();
    OptionMenu();

    cout << endl;
    cout << "Would you like to process another book?(Y/N): ";
    cin >> anotherBook;
    while (anotherBook == 'Y') 
    {
        WordTree->EmptyTree();
        BodyFunction(); 
        OptionMenu();

        cout << endl;
        cout << "Would you like to process another book?(Y/N): ";
        cin >> anotherBook;
        while (anotherBook != 'Y' && anotherBook != 'N') 
        {
            cout << "Please enter Y or N: ";
            cin >> anotherBook;
        }
    }
    
    return 0;
}