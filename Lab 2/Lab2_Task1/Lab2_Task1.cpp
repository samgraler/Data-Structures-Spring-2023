#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

void body_function()
{
    string fileName;
    ifstream targetFile;
    cout << "Please Enter the File Name: ";
    cin >> fileName;
    // fileName = "Testing.txt";

    targetFile.open(fileName);

    while (!targetFile)
    {
        cout << "Error: File Name Provided Could Not Be Opened" << endl;
        cout << "Please try again: " << endl;
        cin >> fileName;
        targetFile.open(fileName);
    }

    for (int i = 0; i < 10; i++)
    {
        string lineIn;
        if (targetFile.eof())
        {
            break;
        }

        getline(targetFile, lineIn);
        cout << lineIn << endl;
    }

    targetFile.close(); // Close File
}

int main()
{
    body_function();
    return 0;
}