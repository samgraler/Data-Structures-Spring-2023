#pragma once
#ifndef _Part_
#define _Part_

#include <string>
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
    Part(string d, string uom, int sku, int p, int lt, int qoh);
    
    string GetPartInfo();
    int GetPrice();
    bool InStock();
    bool Availaible(string d);
    int GetSKU();

    bool operator>(Part &P);
    bool operator<(Part &P);
    bool operator==(Part &P);
    bool operator!=(Part &P);
};

#endif