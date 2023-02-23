#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "EntertainmentCollection.h"
#include "VideoGame.h"
#include "Movie.h"

using namespace std;

void showMenu()
{
    cout << endl;
    cout << "Movie shelf and Video Game shelf are both instances of EntertainmentCollection" << endl;
    cout << "Enter 1 to add a movie to the Movie shelf." << endl;
    cout << "Enter 2 to add a video game to the video game shelf." << endl;
    cout << "Enter 3 remove a movie from the movie shelf." << endl;
    cout << "Enter 4 remove a video game from the video game shelf." << endl;
    cout << "Enter 5 see how many items are currently on the shelves." << endl;
    cout << "Enter 6 to quit." << endl;
}

int main()
{
    // make an instance of entertainment collection for two different types
    EntertainmentCollection<VideoGame> *VideoGameShelf = new EntertainmentCollection<VideoGame>();
    EntertainmentCollection<Movie> *MovieShelf = new EntertainmentCollection<Movie>();
    int ans = 1;
    while (ans == 1)
    {
        int MenuAns;
        showMenu(); // gives choices
        cin >> MenuAns;
        cout << endl;
        if (MenuAns == 1) // add movie
        {
            // user input
            cin.ignore();
            string Title;
            string Description;
            cout << "Please enter the Movie's Title: ";
            getline(cin, Title);
            cout << "Please enter the Movie's Description: ";
            getline(cin, Description);
            cout << endl;

            // dynamically create instance
            try
            {
                MovieShelf->addItem(new Movie(Title, Description));
            }
            catch (FullShelfException fse)
            {
                cout << "Caught FullShelfException" << endl;
                cout << fse.what();
                cout << endl;
            }
        }
        else if (MenuAns == 2) // add video game
        {
            // user input
            cin.ignore();
            string Title;
            string Description;
            cout << "Please enter the Game's Title: ";
            getline(cin, Title);
            cout << "Please enter the Game's Description: ";
            getline(cin, Description);
            cout << endl;

            // dynamically create instance
            try
            {
                VideoGameShelf->addItem(new VideoGame(Title, Description));
            }
            catch (FullShelfException fse)
            {
                cout << "Caught FullShelfException" << endl;
                cout << fse.what();
                cout << endl;
            }
        }
        else if (MenuAns == 3) // remove movie
        {
            try
            {
                Movie *RemovedMovie = MovieShelf->removeItem();
                cout << "You're now holding: " << endl;
                RemovedMovie->Details();
            }
            catch (EmptyShelfException ese)
            {
                cout << "Caught EmptyShelfException" << endl;
                cout << ese.what();
                cout << endl;
            }
        }
        else if (MenuAns == 4) // remove video game
        {
            try
            {
                VideoGame *RemovedGame = VideoGameShelf->removeItem();
                cout << "You're now holding: " << endl;
                RemovedGame->Details();
            }
            catch (EmptyShelfException ese)
            {
                cout << "Caught EmptyShelfException" << endl;
                cout << ese.what();
                cout << endl;
            }
        }
        else if (MenuAns == 5) // show both collection counts count
        {
            cout << "There are " << MovieShelf->getCount() << " movie(s) on the movie shelf." << endl;
            cout << "There are " << VideoGameShelf->getCount() << " game(s) on the video game shelf." << endl;
        }
        else // quit
        {
            ans = 0;
        }
    }

    return 0;
}