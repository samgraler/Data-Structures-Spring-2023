#include "Player.h"

// Helpers.cpp contains 3 helper functions seperated from the main testing .cpp file in order to increase readability

Player *InitializePlayer() // this function gets information from the user to create a player instance
{
    string n;
    int t, max;
    int min = 1;
    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, n);
    cout << "Please enter the amount of money you wish to play with: ";
    cin >> t;
    cout << "Please enter the numer of values on the wheel: ";
    cin >> max;
    while (max > 20 || max < 6)
    {
        cout << "Please enter a Value Between 6 and 20: ";
        cin >> max;
    }

    Player *p = new Player(new Wheel(min, max), t, n);
    return (p);
}

void HousePlay(int betType, Player *House, Player *Player1, int bet) // rolls for the house, called in GamePlay()
{
    int spin1 = 0;
    int spin2 = 0;
    int pspin = Player1->getWheel()->getBallValue();
    House->getWheel()->Spin(pspin, Player1->getWheel()->getMax());
    spin1 = House->getLastSpin(); // get first spin of wheel

    if (betType != 1) // if the player edits their bet in anyway
    {
        House->getWheel()->Spin(pspin, Player1->getWheel()->getMax());
        spin2 = House->getLastSpin(); // get a second spin
        cout << "The House Rolled a " << spin1 << " and a " << spin2 << "." << endl; // output both spins
        cout << endl;
    }
    else // otherwise just output the first spin
    {
        cout << endl
             << "The House Rolled a " << spin1 << "." << endl;
        cout << endl;
    }
    cout << endl;
    if (betType == 1) // no special win conditions if player didn't edit their bet
    {
        if (Player1->getLastSpin() > spin1)
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + bet);
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - bet);
        }
    }
    else if (betType == 2) // if the player doubles their bet, the house must win only one spin to win
    {
        if ((Player1->getLastSpin() > spin1) && (Player1->getLastSpin() > spin2))
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + (bet)); //(2 * bet)
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - (bet)); //(2 * bet)
        }
    }
    else // if the player halves their bet, the house must win BOTH spins
    {
        if ((Player1->getLastSpin() > spin1) || (Player1->getLastSpin() > spin2))
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + (bet)); //(bet / 2)
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - (bet)); //(bet / 2)
        }
    }
}

void GamePlay(Player* Player1, Player* House)
{
    int betChangeNumber;
    int bet = 0;
    cout << "Please enter your bet: ";
    cin >> bet; // input bet
    while (bet <= 0 || bet > Player1->getTotal())
    {
        if (bet <= 0)
        {
            cout << "Please enter a positive number for your bet: ";
        }
        else
        {
            cout << "You cannot bet more than you have... Please enter a different bet: ";
        }
        cin >> bet;
    }
    Player1->getWheel()->Spin(0, 0); // spin for the player (parameters don't matter for the player's spin

    cout << "You spun a " << Player1->getWheel()->getBallValue() << "!" << endl
        << endl;

    cout << "Enter 1 to keep your bet." << endl;
    cout << "Enter 2 to double your bet." << endl;
    cout << "Enter 3 to half your bet." << endl;
    cout << endl;
    cout << "Bet type: ";
    cin >> betChangeNumber; // input bet change option 
    cout << endl;
    while (betChangeNumber != 1 && betChangeNumber != 2 && betChangeNumber != 3)
    {
        cout << "Please enter 1, 2, or 3: ";
        cin >> betChangeNumber;
    }
    switch (betChangeNumber) { // performs math on the bet before passing it into HousePlay() so output is correct
        case 2:
            bet *= 2;
            break;
        case 3:
            bet /= 2;
            break;
        default:
            break;
    }

    cout << "You are betting " << bet << " after rolling " << Player1->getLastSpin() << endl;

    HousePlay(betChangeNumber, House, Player1, bet); // calls HousePlay to execute the rest of the turn

    cout << "Your Total is Now: " << Player1->getTotal() << endl;
    cout << endl;
}