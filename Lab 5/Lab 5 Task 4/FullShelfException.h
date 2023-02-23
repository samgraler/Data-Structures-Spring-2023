#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class FullShelfException : public std::exception
{
public:
    string what() // overrides what() virtual function from std::exception that returns an explanatory string
    {
        return ("The Shelf Was Full! You cannot add a movie to a full shelf.");
    }
};