//Gaddis Program 8-6 (begins on line 4) *modified to use structure


// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

struct product
{
    int id;
    int units;
    double prices;
    double sales;
};

// Function prototypes
void calcSales(product[], int);
void showOrder(product[], int);
void dualSort(product[], int);
void showTotals(product[], int);

int main()
{
    // OLD ARRAYS: used to initialize array of structures to avoid extra typing
    // Array with product ID numbers
    int id[NUM_PRODS] = { 914, 915, 916, 917, 918, 919, 920,
                         921, 922 };

    // Array with number of units sold for each product
    int units[NUM_PRODS] = { 842, 416, 127, 514, 437, 269, 97,
                            492, 212 };

    // Array with product prices
    double prices[NUM_PRODS] = { 12.95, 14.95, 18.95, 16.95, 21.95,
                                31.95, 14.95, 14.95, 16.95 };
    
    //Array of products to hold id, units, prices, and sales for each product 
    product ProductArray[NUM_PRODS];
    //Initialize ProductArray with values from old arrays
    for (int i = 0; i < NUM_PRODS; i++)
    {
        ProductArray[i].id = id[i];
        ProductArray[i].units = units[i];
        ProductArray[i].prices = prices[i];
    }

    // Calculate each product's sales.
    calcSales(ProductArray, NUM_PRODS);

    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    dualSort(ProductArray, NUM_PRODS);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(ProductArray, NUM_PRODS);

    // Display total units sold and total sales.
    showTotals(ProductArray, NUM_PRODS);
    return 0;
}

//****************************************************************
// Definition of calcSales. Accepts array of products to access  *
// units, prices, and sales. The size of these arrays is passed  *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(product p[], int num)
{
    for (int index = 0; index < num; index++)
        p[index].sales = p[index].units * p[index].prices;
}

//***************************************************************
// Definition of function dualSort. Accepts array of products   *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the product array are       *
// exchanged identically as the sales. size is the number       *
// of elements in each array.                                   *
//***************************************************************

void dualSort(product p[], int size)
{
    int startScan, maxIndex;
    product temp;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        temp = p[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (p[index].sales > temp.sales)
            {
                temp = p[index];
                maxIndex = index;
            }
        }
        p[maxIndex] = p[startScan];
        p[startScan] = temp;
    }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(product p[], int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << p[index].id << "\t\t$";
        cout << setw(8) << p[index].sales << endl;
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

void showTotals(product p[], int num)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totalUnits += p[index].units;
        totalSales += p[index].sales;
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;
} 
