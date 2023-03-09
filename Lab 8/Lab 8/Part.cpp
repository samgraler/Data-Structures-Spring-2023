#pragma once
#include "Part.h"
#include <cstdio>
#include <cstring>  
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

Part::Part(string d, string uom, int sku, int p, int lt){
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = 0;
};

Part::Part(string d, string uom, int sku, int p, int lt, int qoh){
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = qoh;
};
    
string Part::GetPartInfo(){
    return ("SKU: "+to_string(SKU)+" Desc: " + Desc);
}

int Part::GetPrice(){
    return(Price);
}

int Part::GetSKU()
{
    return(SKU);
}

bool Part::InStock(){
    return(QOH > 0);
}

// need to fix
bool Part::Availaible(string d){ 
    /*if (QOH > 0) {
        return true;
    }

    vector<char> vect;
    
    //time_t ttime = time(0);
    time_t ttime = time(NULL);
    struct tm buf;
    tm *local_time = localtime_s(&ttime, &buf);
    int cmonth = 1 + local_time->tm_mon;
    int cday = local_time->tm_mday;
    int nmonth;
    int nday;

    
    char * ptr;
    while ((*ptr) != ' ')
    {  
        vect.push_back(*ptr);
        ptr += 1;
    }  

    if (nmonth == cmonth && nday-cday < LeadTime){
        return true;
    }
    else{
        return false;
    }
    */

    return(true);
}

bool Part::operator>(Part &P){
    return (this->SKU > P.SKU);
}

bool Part::operator<(Part &P){
    return (this->SKU < P.SKU);
}

bool Part::operator==(Part &P){
    return (this->SKU == P.SKU);
}

bool Part::operator!=(Part &P){
    return (this->SKU != P.SKU);
}