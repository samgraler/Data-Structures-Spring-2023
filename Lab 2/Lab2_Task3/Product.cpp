#pragma once
#include <string>
#include "Product.h"

using namespace std;

// Default constructor
Product::Product()
{
    ID = 0;
    Units = 0;
    Price = 0;
    Description = "";
    TaxExempt = false;
}
// Fill constructor
Product::Product(int id, int u, double p, string d, bool t)
{
    ID = id;
    Units = u;
    Price = p;
    Description = d;
    TaxExempt = t;
}

Product::~Product()
{

}

// Setters
void Product::setID(int id)
{
    ID = id;
}
void Product::setUnits(int u)
{
    Units = u;
}
void Product::setPrice(double p)
{
    Price = p;
}
void Product::setDescription(string d)
{
    Description = d;
}
void Product::setTaxExempt(bool t)
{
    TaxExempt = t;
}
void Product::setSales()
{
    Sales = calcSales();
}

// Getters
int Product::getID() { return ID; }
int Product::getUnits() { return Units; }
double Product::getPrice() { return Price; }
string Product::getDescription() { return Description; }
bool Product::getTaxExempt() { return TaxExempt; }
double Product::getSales() { return Sales; }

// Other member functions
double Product::calcSales()
{
    return(Units * Price);
}