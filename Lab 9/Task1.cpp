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

void body_function() // created to make main() more efficient and readable
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

int main()
{
	WordTree = new BST<Word>();
    char anotherBook = 'Y'; 
    body_function(); 

    cout << "Would you like to process another book?(Y/N): ";
    cin >> anotherBook;

    while (anotherBook == 'Y') 
    {
        body_function(); // runs body_function() to add words and print data
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