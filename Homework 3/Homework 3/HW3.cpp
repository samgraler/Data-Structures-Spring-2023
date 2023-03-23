#pragma once
#include "Player.h"
#include "Card.h"
#include <algorithm>
#include <array>
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

// global instances of player and cpu
Player* p;
Player* cpu;

Deck* GenerateDeck() // This funtion creates a complete deck of cards, shuffles it, and then returns the shuffled deck
{
    array<Card, 52> InitialDeck; // create a card array to allow for use of standard shuffling algorithm
    for (int i = 0; i < 13; i++)
    {
        InitialDeck[i] = Card(i + 2, "Hearts");
        InitialDeck[i + 13] = Card(i + 2, "Spades");
        InitialDeck[i + 26] = Card(i + 2, "Diamonds");
        InitialDeck[i + 39] = Card(i + 2, "Clubs");
    }

    // Shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(InitialDeck.begin(), InitialDeck.end(), default_random_engine(seed));

    // Declare deck
    Deck* D = new Deck();

    // Enqueue shuffled cards into deck
    for (int i = 0; i < 52; i++)
    {
        D->Enqueue(new Card(InitialDeck[i]));
    }

    // Return Shuffled Deck
    return D;
}

void Deal(Deck* d) // deals the cards to the player
{
    for (int i = 0; i < 26; i++)
    {
        p->getDeck()->Enqueue(d->Dequeue());
        cpu->getDeck()->Enqueue(d->Dequeue());
    }
}

int c = 1; // global number of rounds

void PlayRound()
{
    string ans;
    cout << "Would you like to peek at your card? (Yes = 1, No = 0)" << endl;
    cout << "> ";
    cin >> ans;
    cout << endl;

    if (ans == "1")
    {
        cout << "Your card is the " << to_string(p->getDeck()->Peek()->getData()) << " of " << p->getDeck()->Peek()->getSuit() << endl << endl;
    }

    // get next option

    cout << "What would you like to do next? " << endl
        << "(1) Play your card alone" << endl
        << "(2) Place your card on your side deck and play the next one" << endl
        << "(3) See how many cards you have left (total)" << endl
        << "(4) See how many cards you have in your side deck" << endl
        << "(5) See how many cards the CPU has left (main deck)" << endl
        << "(6) Play your card with the top card from your side deck?" << endl;
    cout << "> ";
    cin >> ans;
    cout << endl;

    Card* PlayerCard;
    Card* PlayerCard1;
    Card* CpuCard;
    switch (stoi(ans))
    {
    case 1: // play top card alone
        PlayerCard = p->getDeck()->Dequeue();
        CpuCard = cpu->getDeck()->Dequeue();

        cout << "Your card is the " << to_string(PlayerCard->getData()) << " of " << PlayerCard->getSuit() << "." << endl;
        cout << "The CPU's card is the " << to_string(CpuCard->getData()) << " of " << CpuCard->getSuit() << "." << endl;

        if (PlayerCard->getData() > CpuCard->getData())
        {
            cout << endl << "You won this round!" << endl;
            p->getDeck()->Enqueue(PlayerCard);
            p->getDeck()->Enqueue(CpuCard);
        }
        else
        {
            cout << endl << "You lost this round!" << endl;
            cpu->getDeck()->Enqueue(PlayerCard);
            cpu->getDeck()->Enqueue(CpuCard);
        }
        c++;
        break;
    case 2: // place card on side deck
        if (p->getSideDeck()->getLength() > 4)
        {
            cout << "Your side deck is full!" << endl;
            break;
        }

        PlayerCard = p->getDeck()->Dequeue();
        p->getSideDeck()->Push(PlayerCard);
        cout << "Your added the " << to_string(PlayerCard->getData()) << " of " << PlayerCard->getSuit() << " to your side deck!" << endl;

        PlayerCard = p->getDeck()->Dequeue();
        CpuCard = cpu->getDeck()->Dequeue();

        cout << "Your new card is the " << to_string(PlayerCard->getData()) << " of " << PlayerCard->getSuit() << "." << endl;
        cout << "The CPU's card is the " << to_string(CpuCard->getData()) << " of " << CpuCard->getSuit() << "." << endl;

        if (PlayerCard->getData() > CpuCard->getData())
        {
            cout << endl << "You won this round!" << endl;
            p->getDeck()->Enqueue(PlayerCard);
            p->getDeck()->Enqueue(CpuCard);
        }
        else
        {
            cout << endl << "You lost this round!" << endl;
            cpu->getDeck()->Enqueue(PlayerCard);
            cpu->getDeck()->Enqueue(CpuCard);
        }
        c++;
        break;
    case 3: // player deck
        cout << "You have " << p->getDeck()->getLength() + p->getSideDeck()->getLength() << " total cards in your deck." << endl;
        break;
    case 4: // player side deck
        cout << "You have " << p->getSideDeck()->getLength() << " cards in your side deck." << endl;
        break;
    case 5: // CPU main deck
        cout << "The computer has " << cpu->getDeck()->getLength() + cpu->getSideDeck()->getLength() << " cards in their deck." << endl;
        break;
    case 6: // play card with the top card of the side deck
        if (p->getSideDeck()->isEmpty())
        {
            cout << "Your side deck is empty!" << endl;
            break;
        }

        PlayerCard = p->getDeck()->Dequeue();
        PlayerCard1 = p->getSideDeck()->Pop();
        CpuCard = cpu->getDeck()->Dequeue();

        cout << "Your cards are the " << to_string(PlayerCard->getData()) << " of " << PlayerCard->getSuit() << ", and the " << to_string(PlayerCard1->getData()) << " of " << PlayerCard1->getSuit() << "." << endl;
        cout << "The CPU's card is the " << to_string(CpuCard->getData()) << " of " << CpuCard->getSuit() << "." << endl;

        if ((PlayerCard->getData() + PlayerCard1->getData()) > CpuCard->getData())
        {
            cout << endl << "You won this round!" << endl;
            p->getDeck()->Enqueue(PlayerCard);
            p->getDeck()->Enqueue(PlayerCard1);
            p->getDeck()->Enqueue(CpuCard);
        }
        else
        {
            cout << endl << "You lost this round!" << endl;
            cpu->getDeck()->Enqueue(PlayerCard);
            cpu->getDeck()->Enqueue(PlayerCard1);
            cpu->getDeck()->Enqueue(CpuCard);
        }
        c++;
        break;
    default:

        break;
    }
    cout << endl;
}

int main()
{
    string name;
    cout << "Please Enter your name: " << endl;
    cout << "> ";
    cin >> name;

    int numrounds = 0;
    cout << "Enter how many rounds you'd like to play (enter 0 until natural win / loss): " << endl;
    cout << "> ";
    cin >> numrounds;
    cout << endl;

    string ans = "Y";
    while (ans == "Y")
    {
        // instances fall out of scope at the end of each game and can be recreated with fresh decks
        cpu = new Player("CPU");
        p = new Player(name);
        Deal(GenerateDeck()); // generates a shuffled deck of cards and deals them to the players

        if (numrounds == 0)
        {
            c = 1;
            while ((p->getDeck()->getLength() + p->getSideDeck()->getLength() > 0) && (cpu->getDeck()->getLength() + cpu->getSideDeck()->getLength() > 0))
            {
                cout << "Round " << c << endl << endl;
                PlayRound();
            }

            // win / lose case

            if (p->getDeck()->getLength() <= 0 && p->getSideDeck()->getLength() <= 0)
            {
                cout << "You lost!!" << endl;
                cout << "The computer won all your cards!" << endl << endl;
            }
            else
            {
                cout << "You won!!" << endl;
                cout << "Congrats on having the patience to win all the cards!" << endl << endl;
            }
        }
        else
        {
            c = 1;
            for (int i = 0; i < numrounds; i++)
            {
                cout << "Round " << c << endl << endl;
                PlayRound();
            }

            // win / lose case

            if (p->getDeck()->getLength() + p->getSideDeck()->getLength() <= cpu->getDeck()->getLength())
            {
                cout << "You lost the game!!" << endl;
                cout << "The computer had " << cpu->getDeck()->getLength() << " cards." << endl;
                cout << "You had " << p->getDeck()->getLength() + p->getSideDeck()->getLength() << " cards." << endl << endl;
            }
            else
            {
                cout << "You won the game!!" << endl << endl;
                cout << "The computer had " << cpu->getDeck()->getLength() << " cards." << endl;
                cout << "You had " << p->getDeck()->getLength() + p->getSideDeck()->getLength() << " cards." << endl << endl;
            }
        }

        // empty both decks

        cout << "Play again(Y/N)" << endl;
        cin >> ans;
        cout << endl;
    }

    delete p;
    delete cpu;

    return 0;
}