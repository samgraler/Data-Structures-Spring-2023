#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

struct Book
{
    string Title;
    string firstName;
    string lastName;
    int WC; // Word Count 
    int LC; // Line Count
    double totalChars; // Used to calculate letter frequency percentages 
    double letterFreq[26]; // Array to hold letter frequencies (only stores # of occurances, percent is calculated later using the variable above)
};

bool exists(const string& fileName) // Returns true if the filename passed in exists (function checks if a string of any kind is present in the file)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

void print_book_data(const string& fileName, Book& b, char& printFrequency, bool& exists) // prints book data to the filename specified
{
    ofstream destFile;

    if (!exists) 
    {
        destFile.open(fileName, std::ios::out); // if the file with the name spcified doesn't exist, a new file with that name is created for writing
    }
    else
    {
        destFile.open(fileName, std::ios::app); // opens the existing file for appending
        destFile << endl;
    }
    // print book data
    destFile << "Title: " << b.Title << endl;
    destFile << "Full Author: " << b.firstName << " " << b.lastName << endl;
    destFile << "Author First Name: " << b.firstName << endl;
    destFile << "Author Last Name: " << b.lastName << endl;
    destFile << "Word Count: " << b.WC << endl;
    destFile << "Line Count: " << b.LC << endl;

    if (printFrequency == 'Y') // If the user indicates they want the frequencies printed
    {
        char c = 97;
        b.Title.erase(remove(b.Title.begin(), b.Title.end(), '\r'), b.Title.end()); // removes carriage return if it exsits so the output formats correctly
        cout << (b.Title + " letter frequency:");
        cout << setprecision(4) << endl; // sets precision of percentages to 4 digits
        for (int i = 0; i < 26; i++) // loop through letterFreq array to calculate and output the percentages
        {
            cout << c << ": " << ((b.letterFreq[i] / b.totalChars) * 100) << "%" << endl;
            c++;
        }
    }
    destFile.close(); // close file
}

void body_function() // created to make main() more efficient and readable
{
    string fileName;
    ifstream targetFile;
    cout << "Please Enter the File Name (with extension): ";
    cin >> fileName; // getting filename from user

    targetFile.open(fileName); // open specified file for reading (open permissions already defined by ifstream object)

    while (!targetFile) // ensures the file was opened successfully, prompts user to enter another file name if unsuccessful
    {
        cout << "Error: The file with the name provided could not be opened." << endl;
        cout << "Please try again: ";
        cin >> fileName;
        targetFile.open(fileName);
    }

    Book b = { "", "", "", 0, 0, 0, {} }; // create instance of book

    memset(b.letterFreq, 0, sizeof(b.letterFreq)); // ensures memory for the letterFreq array is allocated and initialized to 0

    getline(targetFile, b.Title); // gets entire title line
    getline(targetFile, b.firstName, ' '); // gets name until a space is reached (first name)
    getline(targetFile, b.lastName, '\n'); // gets rest of authors name (last name)

    string contentsWatch = ""; // string used to search for "Contents:" so the beginning of the section can be identified

    while (contentsWatch != "Contents:" && contentsWatch != "Contents: " && contentsWatch != "Contents:\r" && contentsWatch != "Contents: \r")
    {
        getline(targetFile, contentsWatch); // gets next line in file provided that "Contents:" and other versions are not included
    }

    char c;
    int flag = 0; // flag to represent if previous character was a newline character

    while (!targetFile.eof()) // while the cursor is not at the end of the file
    {
        targetFile.get(c); // input next character into c
        // makes c lowercase if it isn't already
        if (c >= 65 && c <= 92)
        {
            c += 32;
        }
        // makes sure final character of file isn't counted twice 
        if (targetFile.eof())
        {
            break;
        }
        // if the character before c wsa a newline, and c is now a letter, add one to the word count and reset flag. This makes sure that 2 words seperated by a newline character and not a space are still counted as 2 words
        if (flag == 1)
        {
            if (c >= 97 && c <= 122)
            {
                b.WC++;
                flag = 0;
            }
        }
        // switch case to determine the character and increment the appropriate location in the letterFreq array
        switch (c)
        {
        case 10: // tests for newline characters to increment the line count
            b.LC++;
            flag = 1;
            break;
        case 32: // tests for spaces to increment the word count
            b.WC++;
            break;
        case 97: // 'a'
            b.letterFreq[0]++;
            b.totalChars++;
            break;
        case 98: // 'b'
            b.letterFreq[1]++;
            b.totalChars++;
            break;
        case 99: // 'c'
            b.letterFreq[2]++;
            b.totalChars++;
            break;
        case 100: // 'd'
            b.letterFreq[3]++;
            b.totalChars++;
            break;
        case 101: // 'e'
            b.letterFreq[4]++;
            b.totalChars++;
            break;
        case 102: // 'f'
            b.letterFreq[5]++;
            b.totalChars++;
            break;
        case 103: // 'g'
            b.letterFreq[6]++;
            b.totalChars++;
            break;
        case 104: // 'h'
            b.letterFreq[7]++;
            b.totalChars++;
            break;
        case 105: // 'i'
            b.letterFreq[8]++;
            b.totalChars++;
            break;
        case 106: // 'j'
            b.letterFreq[9]++;
            b.totalChars++;
            break;
        case 107: // 'k'
            b.letterFreq[10]++;
            b.totalChars++;
            break;
        case 108: // 'l'
            b.letterFreq[11]++;
            b.totalChars++;
            break;
        case 109: // 'm'
            b.letterFreq[12]++;
            b.totalChars++;
            break;
        case 110: // 'n'
            b.letterFreq[13]++;
            b.totalChars++;
            break;
        case 111: // 'o'
            b.letterFreq[14]++;
            b.totalChars++;
            break;
        case 112: // 'p'
            b.letterFreq[15]++;
            b.totalChars++;
            break;
        case 113: // 'q'
            b.letterFreq[16]++;
            b.totalChars++;
            break;
        case 114: // 'r'
            b.letterFreq[17]++;
            b.totalChars++;
            break;
        case 115: // 's'
            b.letterFreq[18]++;
            b.totalChars++;
            break;
        case 116: // 't'
            b.letterFreq[19]++;
            b.totalChars++;
            break;
        case 117: // 'u'
            b.letterFreq[20]++;
            b.totalChars++;
            break;
        case 118: // 'v'
            b.letterFreq[21]++;
            b.totalChars++;
            break;
        case 119: // 'w'
            b.letterFreq[22]++;
            b.totalChars++;
            break;
        case 120: // 'x'
            b.letterFreq[23]++;
            b.totalChars++;
            break;
        case 121: // 'y'
            b.letterFreq[24]++;
            b.totalChars++;
            break;
        case 122: // 'z'
            b.letterFreq[25]++;
            b.totalChars++;
            break;
        default: // ignores everything except letters, spaces, and newline characters
            break;
        }
    }
    targetFile.close(); // close file

    b.WC++; // account for last word w/out a space.

    char frequencyBool;

    cout << "Would you like to see letter frequency? (Y/N): "; // asks user if they want letter frequency printed to file
    cin >> frequencyBool;

    while (frequencyBool != 'Y' && frequencyBool != 'N') // ensure either 'Y' or 'N' was entered
    {
        cout << "Please enter Y or N: ";
        cin >> frequencyBool;
    }

    bool fileExists = exists("CardCatalog.txt"); // checks if "CardCatalog.txt" exists

    print_book_data("CardCatalog.txt", b, frequencyBool, fileExists); // uses b (instance of Book), frequencyBool (answer to if the user wants the frequencies printed), and fileExists (bool for is card catalog exists) to print book datat to "CardCatalog.txt"
}

int main()
{
    char anotherBook = 'Y'; // initialize asnwer to another book question to yes
    body_function(); // Runs body_function() once to enter first book

    cout << "Would you like to process another book?(Y/N): "; // ask if user wants to enter another book
    cin >> anotherBook;

    while (anotherBook == 'Y') // continues adding books until user enters 'N'
    {
        body_function(); // runs body_function() to add book and print data
        cout << "Would you like to process another book?(Y/N): ";
        cin >> anotherBook;
        while (anotherBook != 'Y' && anotherBook != 'N') // ensures only 'Y' or 'N' was entered
        {
            cout << "Please enter Y or N: ";
            cin >> anotherBook;
        }
    }

    return 0;
}