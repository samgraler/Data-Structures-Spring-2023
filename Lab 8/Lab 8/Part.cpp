#pragma once
#include "Part.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <time.h>
#include <ctime>

using namespace std;

Part::Part(string d, string uom, int sku, int p, int lt)
{
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = 0;
};

Part::Part(string d, string uom, int sku, int p, int lt, int qoh)
{
    Desc = d;
    UOM = uom;
    SKU = sku;
    Price = p;
    LeadTime = lt;
    QOH = qoh;
};

Part::Part(Part *CPart)
{
    Desc = CPart->Desc;
    UOM = CPart->UOM;
    SKU = CPart->SKU;
    Price = CPart->Price;
    LeadTime = CPart->LeadTime;
    QOH = CPart->QOH;
}

string Part::GetPartInfo()
{
    return ("SKU: " + to_string(SKU) + " Desc: " + Desc);
}

int Part::GetPrice()
{
    return (Price);
}

int Part::GetSKU()
{
    return (SKU);
}

int Part::GetQOH()
{
    return (QOH);
}

bool Part::InStock()
{
    return (QOH > 0);
}

int Part::rdn(int y, int m, int d)
{ /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    int x = 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
    return x;
}

bool Part::Availaible(string d)
{
    if (QOH > 0)
    {
        return true;
    }

    int day, month;
    size_t pos = 0;
    string delim = "/";

    pos = d.find(delim);
    month = stoi(d.substr(0, pos));
    d.erase(0, pos + delim.length());

    pos = d.find(delim);
    day = stoi(d.substr(0, pos));
    d.erase(0, pos + delim.length());

    time_t t = time(NULL);
    struct tm now;
    localtime_s(&now, &t);

    if ((rdn(123, month, day)- rdn(123, 3, now.tm_mday)) > this->LeadTime)
    {
        return true;
    }

    return false;
}

bool Part::operator>(Part &P)
{
    return (this->SKU > P.SKU);
}

bool Part::operator<(Part &P)
{
    return (this->SKU < P.SKU);
}

bool Part::operator==(Part &P)
{
    return (this->SKU == P.SKU);
}

bool Part::operator!=(Part &P)
{
    return (this->SKU != P.SKU);
}

void Part::Display()
{
    cout << "--------------------------------------------" << endl;
    ascii_art("SKU: " + to_string(this->GetSKU()));
    cout << endl
         << endl;
    ascii_art("QOH: " + to_string(this->GetQOH()));
    cout << endl
         << endl;
    ascii_art("Price: " + to_string(this->GetPrice()));
    cout << endl
         << endl;
    cout << "--------------------------------------------" << endl;
}

// function we found that creates ascii art for a string input

// Lord Hypersonic
// February 01, 2019
// ASCII Art Generator
// Code version: 1.0
// Source Code
// URL: https://lordhypersonic.blogspot.com/2019/02/c-ascii-art-generator.html
void Part::ascii_art(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << "  ___   ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << " _____  ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << " _____  ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << " _____  ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << " _____  ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << " _____  ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << " _____  ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << " _   _  ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << " _____  ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "   ___  ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << " _   __ ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << " _      ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << " __  __  ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << " _   _  ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << " _____  ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << " _____  ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << " _____  ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << " _____  ";
        if (input[i] == 'S' || input[i] == 's')
            cout << " _____  ";
        if (input[i] == 'T' || input[i] == 't')
            cout << " _____  ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << " _   _  ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << " _   _  ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << " _    _  ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << "__   __ ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << "__   __ ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << " ______ ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << " _  ";
        if (input[i] == '~')
            cout << "      ";
        if (input[i] == '1')
            cout << " __   ";
        if (input[i] == '2')
            cout << " _____  ";
        if (input[i] == '3')
            cout << " _____  ";
        if (input[i] == '4')
            cout << "   ___  ";
        if (input[i] == '5')
            cout << " _____  ";
        if (input[i] == '6')
            cout << "  ____  ";
        if (input[i] == '7')
            cout << " ______ ";
        if (input[i] == '.')
            cout << "    ";
        if (input[i] == '8')
            cout << " _____  ";
        if (input[i] == '9')
            cout << " _____  ";
        if (input[i] == '0')
            cout << " _____  ";
        if (input[i] == '!')
            cout << " _  ";
        if (input[i] == '@')
            cout << "   ____   ";
        if (input[i] == '#')
            cout << "   _  _    ";
        if (input[i] == '$')
            cout << "  _   ";
        if (input[i] == '%')
            cout << " _   __ ";
        if (input[i] == '^')
            cout << " /\\  ";
        if (input[i] == '&')
            cout << "         ";
        if (input[i] == '*')
            cout << "    _     ";
        if (input[i] == '(')
            cout << "  __ ";
        if (input[i] == ')')
            cout << "__   ";
        if (input[i] == '-')
            cout << "         ";
        if (input[i] == '_')
            cout << "         ";
        if (input[i] == '=')
            cout << "         ";
        if (input[i] == '+')
            cout << "        ";
        if (input[i] == '[')
            cout << " ___  ";
        if (input[i] == '{')
            cout << "   __ ";
        if (input[i] == ']')
            cout << " ___  ";
        if (input[i] == '}')
            cout << "__    ";
        if (input[i] == '|')
            cout << " _  ";
        if (input[i] == '\\')
            cout << "__      ";
        if (input[i] == ';')
            cout << " _  ";
        if (input[i] == ':')
            cout << "    ";
        if (input[i] == '\'')
            cout << " _  ";
        if (input[i] == '"')
            cout << " _ _  ";
        if (input[i] == '<')
            cout << "   __ ";
        if (input[i] == ',')
            cout << "    ";
        if (input[i] == '>')
            cout << "__    ";
        if (input[i] == '/')
            cout << "     __ ";
        if (input[i] == '?')
            cout << " ___   ";
    }
    cout << endl;
    // loop will print second layer
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << " / _ \\  ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << "| ___ \\ ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << "/  __ \\ ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << "|  _  \\ ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << "|  ___| ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << "|  ___| ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << "|  __ \\ ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << "| | | | ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << "|_   _| ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "  |_  | ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << "| | / / ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << "| |     ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << "|  \\/  | ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << "| \\ | | ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << "|  _  | ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << "| ___ \\ ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << "|  _  | ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << "| ___ \\ ";
        if (input[i] == 'S' || input[i] == 's')
            cout << "/  ___| ";
        if (input[i] == 'T' || input[i] == 't')
            cout << "|_   _| ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << "| | | | ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << "| | | | ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << "| |  | | ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << "\\ \\ / / ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << "\\ \\ / / ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << "|___  / ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << "( ) ";
        if (input[i] == '~')
            cout << "      ";
        if (input[i] == '1')
            cout << "/  |  ";
        if (input[i] == '2')
            cout << "/ __  \\ ";
        if (input[i] == '3')
            cout << "|____ | ";
        if (input[i] == '4')
            cout << "  /   | ";
        if (input[i] == '5')
            cout << "|  ___| ";
        if (input[i] == '6')
            cout << " / ___| ";
        if (input[i] == '7')
            cout << "|___  / ";
        if (input[i] == '.')
            cout << "    ";
        if (input[i] == '8')
            cout << "|  _  | ";
        if (input[i] == '9')
            cout << "|  _  | ";
        if (input[i] == '0')
            cout << "|  _  | ";
        if (input[i] == '!')
            cout << "| | ";
        if (input[i] == '@')
            cout << "  / __ \\  ";
        if (input[i] == '#')
            cout << " _| || |_  ";
        if (input[i] == '$')
            cout << " | |  ";
        if (input[i] == '%')
            cout << "(_) / / ";
        if (input[i] == '^')
            cout << "|/\\| ";
        if (input[i] == '&')
            cout << "  ___    ";
        if (input[i] == '*')
            cout << " /\\| |/\\  ";
        if (input[i] == '(')
            cout << " / / ";
        if (input[i] == ')')
            cout << "\\ \\  ";
        if (input[i] == '-')
            cout << "         ";
        if (input[i] == '_')
            cout << "         ";
        if (input[i] == '=')
            cout << " ______  ";
        if (input[i] == '+')
            cout << "   _    ";
        if (input[i] == '[')
            cout << "|  _| ";
        if (input[i] == '{')
            cout << "  / / ";
        if (input[i] == ']')
            cout << "|_  | ";
        if (input[i] == '}')
            cout << "\\ \\   ";
        if (input[i] == '|')
            cout << "| | ";
        if (input[i] == '\\')
            cout << "\\ \\     ";
        if (input[i] == ';')
            cout << "(_) ";
        if (input[i] == ':')
            cout << " _  ";
        if (input[i] == '\'')
            cout << "( ) ";
        if (input[i] == '"')
            cout << "( | ) ";
        if (input[i] == '<')
            cout << "  / / ";
        if (input[i] == ',')
            cout << "    ";
        if (input[i] == '>')
            cout << "\\ \\   ";
        if (input[i] == '/')
            cout << "    / / ";
        if (input[i] == '?')
            cout << "|__ \\  ";
    }
    cout << endl;
    // loop will print third layer
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << "/ /_\\ \\ ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << "| |_/ / ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << "| /  \\/ ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << "| | | | ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << "| |__   ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << "| |_    ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << "| |  \\/ ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << "| |_| | ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << "  | |   ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "    | | ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << "| |/ /  ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << "| |     ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << "| .  . | ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << "|  \\| | ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << "| | | | ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << "| |_/ / ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << "| | | | ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << "| |_/ / ";
        if (input[i] == 'S' || input[i] == 's')
            cout << "\\ `--.  ";
        if (input[i] == 'T' || input[i] == 't')
            cout << "  | |   ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << "| | | | ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << "| | | | ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << "| |  | | ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << " \\ V /  ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << " \\ V /  ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << "   / /  ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << " \\| ";
        if (input[i] == '~')
            cout << " /\\/| ";
        if (input[i] == '1')
            cout << "`| |  ";
        if (input[i] == '2')
            cout << "`' / /' ";
        if (input[i] == '3')
            cout << "    / / ";
        if (input[i] == '4')
            cout << " / /| | ";
        if (input[i] == '5')
            cout << "|___ \\  ";
        if (input[i] == '6')
            cout << "/ /___  ";
        if (input[i] == '7')
            cout << "   / /  ";
        if (input[i] == '.')
            cout << "    ";
        if (input[i] == '8')
            cout << " \\ V /  ";
        if (input[i] == '9')
            cout << "| |_| | ";
        if (input[i] == '0')
            cout << "| |/' | ";
        if (input[i] == '!')
            cout << "| | ";
        if (input[i] == '@')
            cout << " / / _` | ";
        if (input[i] == '#')
            cout << "|_  __  _| ";
        if (input[i] == '$')
            cout << "/ __) ";
        if (input[i] == '%')
            cout << "   / /  ";
        if (input[i] == '^')
            cout << "     ";
        if (input[i] == '&')
            cout << " ( _ )   ";
        if (input[i] == '*')
            cout << " \\ ` ' /  ";
        if (input[i] == '(')
            cout << "| |  ";
        if (input[i] == ')')
            cout << " | | ";
        if (input[i] == '-')
            cout << " ______  ";
        if (input[i] == '_')
            cout << "         ";
        if (input[i] == '=')
            cout << "|______| ";
        if (input[i] == '+')
            cout << " _| |_  ";
        if (input[i] == '[')
            cout << "| |   ";
        if (input[i] == '{')
            cout << " | |  ";
        if (input[i] == ']')
            cout << "  | | ";
        if (input[i] == '}')
            cout << " | |  ";
        if (input[i] == '|')
            cout << "| | ";
        if (input[i] == '\\')
            cout << " \\ \\    ";
        if (input[i] == ';')
            cout << "    ";
        if (input[i] == ':')
            cout << "(_) ";
        if (input[i] == '\'')
            cout << "|/  ";
        if (input[i] == '"')
            cout << " V V  ";
        if (input[i] == '<')
            cout << " / /  ";
        if (input[i] == ',')
            cout << "    ";
        if (input[i] == '>')
            cout << " \\ \\  ";
        if (input[i] == '/')
            cout << "   / /  ";
        if (input[i] == '?')
            cout << "   ) | ";
    }
    cout << endl;
    // loop will print fourth layer
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << "|  _  | ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << "| ___ \\ ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << "| |     ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << "| | | | ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << "|  __|  ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << "|  _|   ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << "| | __  ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << "|  _  | ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << "  | |   ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "    | | ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << "|    \\  ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << "| |     ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << "| |\\/| | ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << "| . ` | ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << "| | | | ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << "|  __/  ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << "| | | | ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << "|    /  ";
        if (input[i] == 'S' || input[i] == 's')
            cout << " `--. \\ ";
        if (input[i] == 'T' || input[i] == 't')
            cout << "  | |   ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << "| | | | ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << "| | | | ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << "| |/\\| | ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << " / ^ \\  ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << "  \\ /   ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << "  / /   ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << "    ";
        if (input[i] == '~')
            cout << "|/\\/  ";
        if (input[i] == '1')
            cout << " | |  ";
        if (input[i] == '2')
            cout << "  / /   ";
        if (input[i] == '3')
            cout << "    \\ \\ ";
        if (input[i] == '4')
            cout << "/ /_| | ";
        if (input[i] == '5')
            cout << "    \\ \\ ";
        if (input[i] == '6')
            cout << "| ___ \\ ";
        if (input[i] == '7')
            cout << "  / /   ";
        if (input[i] == '.')
            cout << "    ";
        if (input[i] == '8')
            cout << " / _ \\  ";
        if (input[i] == '9')
            cout << "\\____ | ";
        if (input[i] == '0')
            cout << "|  /| | ";
        if (input[i] == '!')
            cout << "| | ";
        if (input[i] == '@')
            cout << "| | (_| | ";
        if (input[i] == '#')
            cout << " _| || |_  ";
        if (input[i] == '$')
            cout << "\\__ \\ ";
        if (input[i] == '%')
            cout << "  / /   ";
        if (input[i] == '^')
            cout << "     ";
        if (input[i] == '&')
            cout << " / _ \\/\\ ";
        if (input[i] == '*')
            cout << "|_     _| ";
        if (input[i] == '(')
            cout << "| |  ";
        if (input[i] == ')')
            cout << " | | ";
        if (input[i] == '-')
            cout << "|______| ";
        if (input[i] == '_')
            cout << "         ";
        if (input[i] == '=')
            cout << " ______  ";
        if (input[i] == '+')
            cout << "|_   _| ";
        if (input[i] == '[')
            cout << "| |   ";
        if (input[i] == '{')
            cout << "< <   ";
        if (input[i] == ']')
            cout << "  | | ";
        if (input[i] == '}')
            cout << "  > > ";
        if (input[i] == '|')
            cout << "| | ";
        if (input[i] == '\\')
            cout << "  \\ \\   ";
        if (input[i] == ';')
            cout << " _  ";
        if (input[i] == ':')
            cout << "    ";
        if (input[i] == '\'')
            cout << "    ";
        if (input[i] == '"')
            cout << "      ";
        if (input[i] == '<')
            cout << "< <   ";
        if (input[i] == ',')
            cout << " _  ";
        if (input[i] == '>')
            cout << "  > > ";
        if (input[i] == '/')
            cout << "  / /   ";
        if (input[i] == '?')
            cout << "  / /  ";
    }
    cout << endl;
    // loop will print fifth layer
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << "| | | | ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << "| |_/ / ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << "| \\__/\\ ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << "| |/ /  ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << "| |___  ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << "| |     ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << "| |_\\ \\ ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << "| | | | ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << " _| |_  ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "/\\__/ / ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << "| |\\  \\ ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << "| |____ ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << "| |  | | ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << "| |\\  | ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << "\\ \\_/ / ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << "| |     ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << "\\ \\/' / ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << "| |\\ \\  ";
        if (input[i] == 'S' || input[i] == 's')
            cout << "/\\__/ / ";
        if (input[i] == 'T' || input[i] == 't')
            cout << "  | |   ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << "| |_| | ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << "\\ \\_/ / ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << "\\  /\\  / ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << "/ / \\ \\ ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << "  | |   ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << "./ /___ ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << "    ";
        if (input[i] == '~')
            cout << "      ";
        if (input[i] == '1')
            cout << "_| |_ ";
        if (input[i] == '2')
            cout << "./ /___ ";
        if (input[i] == '3')
            cout << ".___/ / ";
        if (input[i] == '4')
            cout << "\\___  | ";
        if (input[i] == '5')
            cout << "/\\__/ / ";
        if (input[i] == '6')
            cout << "| \\_/ | ";
        if (input[i] == '7')
            cout << "./ /    ";
        if (input[i] == '.')
            cout << " _  ";
        if (input[i] == '8')
            cout << "| |_| | ";
        if (input[i] == '9')
            cout << ".___/ / ";
        if (input[i] == '0')
            cout << "\\ |_/ / ";
        if (input[i] == '!')
            cout << "|_| ";
        if (input[i] == '@')
            cout << " \\ \\__,_| ";
        if (input[i] == '#')
            cout << "|_  __  _| ";
        if (input[i] == '$')
            cout << "(   / ";
        if (input[i] == '%')
            cout << " / / _  ";
        if (input[i] == '^')
            cout << "     ";
        if (input[i] == '&')
            cout << "| (_>  < ";
        if (input[i] == '*')
            cout << " / , . \\  ";
        if (input[i] == '(')
            cout << "| |  ";
        if (input[i] == ')')
            cout << " | | ";
        if (input[i] == '-')
            cout << "         ";
        if (input[i] == '_')
            cout << " ______  ";
        if (input[i] == '=')
            cout << "|______| ";
        if (input[i] == '+')
            cout << "  |_|   ";
        if (input[i] == '[')
            cout << "| |_  ";
        if (input[i] == '{')
            cout << " | |  ";
        if (input[i] == ']')
            cout << " _| | ";
        if (input[i] == '}')
            cout << " | |  ";
        if (input[i] == '|')
            cout << "| | ";
        if (input[i] == '\\')
            cout << "   \\ \\  ";
        if (input[i] == ';')
            cout << "( ) ";
        if (input[i] == ':')
            cout << " _  ";
        if (input[i] == '\'')
            cout << "    ";
        if (input[i] == '"')
            cout << "      ";
        if (input[i] == '<')
            cout << " \\ \\  ";
        if (input[i] == ',')
            cout << "( ) ";
        if (input[i] == '>')
            cout << " / /  ";
        if (input[i] == '/')
            cout << " / /    ";
        if (input[i] == '?')
            cout << " |_|   ";
    }
    cout << endl;
    // loop will print sixth layer
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a')
            cout << "\\_| |_/ ";
        if (input[i] == 'B' || input[i] == 'b')
            cout << "\\____/  ";
        if (input[i] == 'C' || input[i] == 'c')
            cout << " \\____/ ";
        if (input[i] == 'D' || input[i] == 'd')
            cout << "|___/   ";
        if (input[i] == 'E' || input[i] == 'e')
            cout << "\\____/  ";
        if (input[i] == 'F' || input[i] == 'f')
            cout << "\\_|     ";
        if (input[i] == 'G' || input[i] == 'g')
            cout << " \\____/ ";
        if (input[i] == 'H' || input[i] == 'h')
            cout << "\\_| |_/ ";
        if (input[i] == 'I' || input[i] == 'i')
            cout << " \\___/  ";
        if (input[i] == 'J' || input[i] == 'j')
            cout << "\\____/  ";
        if (input[i] == 'K' || input[i] == 'k')
            cout << "\\_| \\_/ ";
        if (input[i] == 'L' || input[i] == 'l')
            cout << "\\_____/ ";
        if (input[i] == 'M' || input[i] == 'm')
            cout << "\\_|  |_/ ";
        if (input[i] == 'N' || input[i] == 'n')
            cout << "\\_| \\_/ ";
        if (input[i] == 'O' || input[i] == 'o')
            cout << " \\___/  ";
        if (input[i] == 'P' || input[i] == 'p')
            cout << "\\_|     ";
        if (input[i] == 'Q' || input[i] == 'q')
            cout << " \\_/\\_\\ ";
        if (input[i] == 'R' || input[i] == 'r')
            cout << "\\_| \\_| ";
        if (input[i] == 'S' || input[i] == 's')
            cout << "\\____/  ";
        if (input[i] == 'T' || input[i] == 't')
            cout << "  \\_/   ";
        if (input[i] == 'U' || input[i] == 'u')
            cout << " \\___/  ";
        if (input[i] == 'V' || input[i] == 'v')
            cout << " \\___/  ";
        if (input[i] == 'W' || input[i] == 'w')
            cout << " \\/  \\/  ";
        if (input[i] == 'X' || input[i] == 'x')
            cout << "\\/   \\/ ";
        if (input[i] == 'Y' || input[i] == 'y')
            cout << "  \\_/   ";
        if (input[i] == 'Z' || input[i] == 'z')
            cout << "\\_____/ ";
        if (input[i] == ' ')
            cout << "  ";
        if (input[i] == '`')
            cout << "    ";
        if (input[i] == '~')
            cout << "      ";
        if (input[i] == '1')
            cout << "\\___/ ";
        if (input[i] == '2')
            cout << "\\_____/ ";
        if (input[i] == '3')
            cout << "\\____/  ";
        if (input[i] == '4')
            cout << "    |_/ ";
        if (input[i] == '5')
            cout << "\\____/  ";
        if (input[i] == '6')
            cout << "\\_____/ ";
        if (input[i] == '7')
            cout << "\\_/     ";
        if (input[i] == '.')
            cout << "(_) ";
        if (input[i] == '8')
            cout << "\\_____/ ";
        if (input[i] == '9')
            cout << "\\____/  ";
        if (input[i] == '0')
            cout << " \\___/  ";
        if (input[i] == '!')
            cout << "(_) ";
        if (input[i] == '@')
            cout << "  \\____/  ";
        if (input[i] == '#')
            cout << "  |_||_|   ";
        if (input[i] == '$')
            cout << " |_|  ";
        if (input[i] == '%')
            cout << "/_/ (_) ";
        if (input[i] == '^')
            cout << "     ";
        if (input[i] == '&')
            cout << " \\___/\\/ ";
        if (input[i] == '*')
            cout << " \\/|_|\\/  ";
        if (input[i] == '(')
            cout << " \\_\\ ";
        if (input[i] == ')')
            cout << "/_/  ";
        if (input[i] == '-')
            cout << "         ";
        if (input[i] == '_')
            cout << "|______| ";
        if (input[i] == '=')
            cout << "         ";
        if (input[i] == '+')
            cout << "        ";
        if (input[i] == '[')
            cout << "|___| ";
        if (input[i] == '{')
            cout << "  \\_\\ ";
        if (input[i] == ']')
            cout << "|___| ";
        if (input[i] == '}')
            cout << "/_/   ";
        if (input[i] == '|')
            cout << "|_| ";
        if (input[i] == '\\')
            cout << "    \\_\\ ";
        if (input[i] == ';')
            cout << "|/  ";
        if (input[i] == ':')
            cout << "(_) ";
        if (input[i] == '\'')
            cout << "    ";
        if (input[i] == '"')
            cout << "      ";
        if (input[i] == '<')
            cout << "  \\_\\ ";
        if (input[i] == ',')
            cout << "|/  ";
        if (input[i] == '>')
            cout << "/_/   ";
        if (input[i] == '/')
            cout << "/_/     ";
        if (input[i] == '?')
            cout << " (_)   ";
    }
    cout << endl;
}