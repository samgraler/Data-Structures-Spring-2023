#pragma once
#include <string>
using namespace std;

class Card
{
public:
    int data; // value of card
    string suit;
    Card* next; // pointer to next card in the deck
    // Constructor (Takes an invalue of type 'int')
    Card();
    Card(int inval, string s);

    void setData(int inval);
    void setNext(Card* n);
    void setSuit(string s);

    int getData();
    Card* getNext();
    string getSuit();
};