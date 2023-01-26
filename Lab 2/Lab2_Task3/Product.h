#pragma once
#include <string>
using namespace std;

class Product
{
private:
    int ID;
    int Units;
    double Price;
    string Description;
    bool TaxExempt;
    double Sales;
    double calcSales(); // private member to calculate sales, used in setSales()

public:
    //Constructors / destructor
    Product(int id, int u, double p, string d, bool t);
    Product();
    ~Product();

    //Getters
    int getID();
    int getUnits();
    double getPrice();
    string getDescription();
    bool getTaxExempt();
    double getSales();

    //Setters
    void setID(int id);
    void setUnits(int u);
    void setPrice(double p);
    void setDescription(string d);
    void setTaxExempt(bool t);
    void setSales(); // does not allow programmer to pass in sales because it depends on price and units (setSales() calls calcSales())

};