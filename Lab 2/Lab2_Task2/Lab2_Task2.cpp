// This program demonstrates a two-dimensional array.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool exists(const string& fileName)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

const int NUM_DIVS = 3; // Number of divisions
const int NUM_QTRS = 4; // Number of quarters

void printInfo(double sales1[NUM_DIVS][NUM_QTRS], double total)
{
    ofstream targetFile;
    string fileName = "";

    // Get name of the file from user
    cout << "Please enter the name of the file you wish to print to: ";
    cin >> fileName;

    // fileName = "NewFile.txt";

    // check to see if the file with the name given exists, if it doesn't, create it for writing. If it does exist, open it for appending
    if (!exists(fileName))
    {
        targetFile.open(fileName, std::ios::out);
    }
    else
    {
        targetFile.open(fileName, std::ios::app);
        targetFile << endl;
    }

    targetFile << fixed << showpoint << setprecision(2) << setw(8);
    targetFile << "The sales for the company is: $" << endl;
    targetFile << "Div"
        << "\t"
        << "Q1"
        << "\t"
        << "Q2"
        << "\t"
        << "Q3"
        << "\t"
        << "Q4" << endl;

    // Nested loops to display the quarterly sales figures for each division.
    for (int div = 0; div < NUM_DIVS; div++)
    {
        targetFile << div + 1 << "\t";
        for (int qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            targetFile << "$" << sales1[div][qtr] << " ";
        }
        targetFile << endl; // Print blank line.
    }

    targetFile << endl;
    targetFile << "The total sales for the company are: $";
    targetFile << total << endl;

    std::cout << endl;
    std::cout << "Data has been successfully added to the file with the name specified.";
    std::cout << endl;

    targetFile.close();
}

int main()
{
    double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
    double totalSales = 0;            // To hold the total sales.
    int div, qtr;                     // Loop counters.

    cout << "This program will calculate the total sales of\n";
    cout << "all the company's divisions.\n";
    cout << "Enter the following sales information:\n\n";

    // Nested loops to fill the array with quarterly
    // sales figures for each division.
    for (div = 0; div < NUM_DIVS; div++)
    {
        for (qtr = 0; qtr < NUM_QTRS; qtr++)
        {
            cout << "Division " << (div + 1);
            cout << ", Quarter " << (qtr + 1) << ": $";
            cin >> sales[div][qtr];
            totalSales += sales[div][qtr];
        }
        cout << endl; // Print blank line.
    }

    // for (div = 0; div < NUM_DIVS; div++)
    // {
    //     for (qtr = 0; qtr < NUM_QTRS; qtr++)
    //     {
    //         sales[div][qtr] = 1;
    //         totalSales += sales[div][qtr];
    //     }
    // }

    printInfo(sales, totalSales);

    return 0;
}
