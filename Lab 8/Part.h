#pragma once
#ifndef _Part_
#define _Part_

#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class Part
{
private:
    int SKU;
    int Price;
    int QOH;
    int LeadTime;

    string Desc;
    string UOM;

public:
    // Constructor
    Part(string d, string uom, int sku, int p, int lt);
    Part(Part* CPart);
    Part(string d, string uom, int sku, int p, int lt, int qoh);

    string GetPartInfo();
    int GetPrice();
    int GetSKU();
    int GetQOH();
    bool InStock();
    bool Availaible(string d);

    bool operator>(Part& P);
    bool operator<(Part& P);
    bool operator==(Part& P);
    bool operator!=(Part& P);

    void Display();
    void ascii_art(string I);
};

#endif
