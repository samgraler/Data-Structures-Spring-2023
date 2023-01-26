// This program produces a sales report for DLC, Inc.
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Product.h"
using namespace std;

// Function prototypes
void calcSales(Product[], int);
void showOrder(Product[], int);
void dualSort(Product[], int);
void showTotals(Product[], int);

int main()
{
    string Filename; // Name of the file
    ifstream ProductFile;
    string line = "";
    //string line = "";
    int count = 0;
    int ans = 1;
    int TotalProducts = 0;

    while (ans == 1)
    {
        cout << "Enter Product Filename: ";
        cin >> Filename;

        ProductFile.open(Filename);
        while (!ProductFile)
        {
            ProductFile.close();
            std::cout << "The File with the name provided does not exist or cannot be opened, please enter a valid file name: ";
            std::cin >> Filename;
            ProductFile.open(Filename);
        }

        while (!ProductFile.eof())
        {
            getline(ProductFile, line);
            count++;
        }
        TotalProducts = ((count + 1) / 6);
        if (TotalProducts == 0)
        {
            std::cout << "The File with the name provided is empty, would you like to enter a different name? (0 = No (program will terminate), 1 = Yes): ";
            std::cin >> ans;
            if (ans == 0)
            {
                ProductFile.close();
                return 0;
            }
            ProductFile.close();
        }
        else
        {
            break;
        }
    }

    

    // close file and open it again to reset the curser at the beginning of the file (seekg doesn't work for this particular use)
    ProductFile.close();
    ProductFile.open(Filename);

    Product *ProductArray = new Product[TotalProducts];

    // Input ProductArray from file provided
    for (int i = 0; i < TotalProducts; i++)
    {
        ProductFile >> line;
        ProductFile >> line;
        ProductArray[i].setID(stoi(line));
        
        getline(ProductFile, line, ' ');
        getline(ProductFile, line);
        ProductArray[i].setUnits(stoi(line));

        getline(ProductFile, line, ' ');
        getline(ProductFile, line);
        ProductArray[i].setPrice(stod(line));
     
        getline(ProductFile, line, ' ');
        getline(ProductFile, line);
        ProductArray[i].setDescription(line);

        getline(ProductFile, line, ' ');
        getline(ProductFile, line);
 
        if (line == "False")
        {
            ProductArray[i].setTaxExempt(false);
        }
        else
        {
            ProductArray[i].setTaxExempt(true);
        }
    }

    // Calculate each product's sales.
    calcSales(ProductArray, TotalProducts);

    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    dualSort(ProductArray, TotalProducts);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(ProductArray, TotalProducts);

    // Display total units sold and total sales.
    showTotals(ProductArray, TotalProducts);

    delete [] ProductArray;

    ProductFile.close();

    return 0;
}

//****************************************************************
// Definition of calcSales. Accepts array of products to access  *
// units, prices, and sales. The size of these arrays is passed  *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************
void calcSales(Product p[], int num)
{
    for (int index = 0; index < num; index++)
    {
        p[index].setSales();
    }
}

//***************************************************************
// Definition of function dualSort. Accepts array of products   *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the product array are       *
// exchanged identically as the sales. size is the number       *
// of elements in each array.                                   *
//***************************************************************

void dualSort(Product p[], int size)
{
    int startScan, maxIndex;
    Product line;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        line = p[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (p[index].getSales() > line.getSales())
            {
                line = p[index];
                maxIndex = index;
            }
        }
        p[maxIndex] = p[startScan];
        p[startScan] = line;
    }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(Product p[], int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << p[index].getID() << "\t\t$";
        cout << setw(8) << p[index].getSales() << endl;
    }
    cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts product array       *
// as argument. The size of these arrays is passed into num.      *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(Product p[], int num)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totalUnits += p[index].getUnits();
        totalSales += p[index].getSales();
    }
    if ((totalSales == 0) && (totalUnits == 0))
    {
        std::cout << "File opened was empty." << endl;
        return;
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;
}