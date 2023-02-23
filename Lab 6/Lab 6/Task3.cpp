#pragma once
#include "Stack.cpp"
#include "Queue.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int numWords = 0;
    const int maxChars = 50;
    char InputChoice = '0';
    string textline;
    string FileName;

    cout << "Enter 0 for File / Enter 1 for Terminal: " << endl;
    cout << "> ";
    cin >> InputChoice;
    cout << endl;

    while (InputChoice == '0' || InputChoice == '1' )
    {
        if (InputChoice == '0')
        {
            char c;
            string word;
            string line;
            std::stringstream lineStream;
            cout << "Please enter the file name: " << endl;
            cout << "> ";
            cin >> FileName;

            ifstream targetFile;
            targetFile.open(FileName);

            while (!targetFile)
            {
                cin.ignore();
                cout << "Error: File Name Provided Could Not Be Opened" << endl;
                cout << "Please try again: " << endl;
                cout << "> ";
                cin >> FileName;
                cout << endl;
                targetFile.open(FileName);
            }

            while (getline(targetFile, line))
            {
                stringstream lineStream(line);
                while (getline(lineStream, line, ' '))
                {
                    ++numWords;
                }
                ++numWords;
            }

            targetFile.close();
        }
        else
        {
            cin.ignore();
            cout << "Please enter your line of text: " << endl;
            cout << "> ";
            getline(std::cin, textline);
            cout << endl;
            for (int i = 0; i < textline.size(); i++)
            {
                // check if current character is a space
                if (textline[i] == ' ')
                {
                    // if it is a space, increment word count
                    numWords++;
                }
            }
            if (textline.size())
            {
                numWords++;
            }
        }
        // figure out num words
        Queue<string> WordQueue = Queue<string>(numWords);
        // now put words into queue

        if (InputChoice == '0')
        {
            string word = "";
            string line;
            ifstream targetFile;
            targetFile.open(FileName);
            while (!targetFile.eof())
            {
                word = "";
                targetFile >> word;
                WordQueue.Enqueue(new string(word));
            }
        }
        else
        {
            string word;
            char c;
            for (int i = 0; i < textline.size(); i++)
            {
                // check if current character is a space
                c = textline[i];

                if (c == ' ')
                {
                    // if it is a space, add word to queue
                    WordQueue.Enqueue(new string(word));
                    word = "";
                }
                else
                {
                    word = word + c;
                }
            }
            WordQueue.Enqueue(new string(word)); // add final word
        }

        // Begin letter reversal section
        Stack<char> LetterStack = Stack<char>(50); // stack size of 50 is long enough to hold longest word in english language
        string AnswerString = "";
        string *CurrentWord = new string("");
        while (WordQueue.Length() > 0)
        {
            try
            {
                CurrentWord = WordQueue.Dequeue();
            }
            catch (QueueUnderflowException que)
            {
                cout << "Caught QueueUnderflowException" << endl;
                cout << que.what();
                cout << endl;
            }

            
            for (int i = 0; i < (*CurrentWord).length(); i++)
            {
                try
                {
                    char* cp = new char((*CurrentWord)[i]);
                    cp[1] = '\0'; // add null terminator to ensure only 1 character is pushed
                    LetterStack.Push(cp);
                }
                catch (StackOverflowException soe)
                {
                    cout << "Caught StackOverflowException" << endl;
                    cout << soe.what();
                    cout << endl;
                }
            }
             
            for (int j = 0; j < (*CurrentWord).length(); j++)
            {
                try
                {
                    AnswerString.append((LetterStack.Pop()));
                }
                catch (StackUnderflowException sue)
                {
                    cout << "Caught StackUnderflowException" << endl;
                    cout << sue.what();
                    cout << endl;
                }
            }
            AnswerString.append(" ");
        }
        cout << "Reversed String: " << endl
             << AnswerString << endl
             << endl;

        cout << "Would you like to continue?" << endl;
        cout << "Enter 0 for File / Enter 1 for Terminal (Anything else to quit): ";
        cin >> InputChoice;
        cout << endl;
        if (InputChoice != '0' && InputChoice != '1')
        {
           WordQueue.Empty();
           LetterStack.Empty();
        }

    }
    return 0;
}