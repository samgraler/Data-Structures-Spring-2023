#include "LinkedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    current = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
}

template <class T>
void LinkedList<T>::AddItem(T *item) // only changes current if inserting to an empty list
{
    if (isEmpty())
    { // empty list case
        head = new Node<T>(item);
        length++;
        current = head;
    }
    else if ((*item) < (*head->data))
    { // head case
        Node<T> *h = new Node<T>(item);
        h->next = head;
        h->prev = nullptr;
        head->prev = h;
        head = h;
        length++;
    }
    else
    { // insert middle and tail cases
        Node<T> *temp = head;
        while ((temp->next != nullptr) && ((*temp->next->data) < (*item)))
        {
            temp = temp->next;
        }
        if (temp->next == nullptr) // tail case
        {
            Node<T> *newNode = new Node<T>(item);
            newNode->next = nullptr;
            newNode->prev = temp;
            temp->next = newNode;
            length++;
        }
        else // middle case
        {
            Node<T> *newNode = new Node<T>(item);
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }
    }
}

template <class T>
T *LinkedList<T>::Remove(T *item)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    if (!IsInList(item))
    {
        throw ItemNotFoundException();
    }

    Node<T> *temp = head;

    while ((*temp->data) != (*item))
    {
        temp = temp->next;
    }

    T *ret = new T(temp->data);

    if (temp->prev == nullptr)
    { // head case
        if (length == 1)
        {
            head = nullptr;
            current = nullptr;
            delete temp;
            length--;
            return (ret);
        }

        if (temp->next != nullptr)
        {
            head = temp->next;
            head->prev = nullptr;
        }

        if (temp == current)
        {
            current = temp->next;
        }
    }
    else if (temp->next == nullptr)
    { // tail case
        if (temp == current)
        {
            current = temp->prev;
        }
        temp->prev->next = nullptr;
    }
    else
    { // middle case
        if (temp == current)
        {
            if (temp->next == nullptr)
            {
                current = temp->prev;
            }
            current = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;
    length--;
    return ret;
}

template <class T>
T *LinkedList<T>::GetItem(T *item)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    if (!IsInList(item))
    {
        throw ItemNotFoundException();
    }

    Node<T> *temp = head;

    while ((*temp->data) != (*item))
    {
        comparisons++;
        temp = temp->next;
    }
    return (temp->data);
}



template <class T>
bool LinkedList<T>::IsInList(T *item)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (*temp->data == *item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
    {
        return (true);
    }
    return (false);
}

template <class T>
int LinkedList<T>::Size()
{
    return length;
}

template <class T>
T *LinkedList<T>::SeeNext()
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    if (current == nullptr || current->next == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->next;
    return (current->data);
}

template <class T>
T *LinkedList<T>::SeePrev()
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    if (current == nullptr || current->prev == nullptr)
    {
        current = nullptr;
        return nullptr;
    }
    current = current->prev;
    return (current->data);
}

template <class T>
T *LinkedList<T>::SeeAt(int l)
{
    if (l >= length)
    {
        throw EndOfListException();
    }
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    Node<T> *temp = head;
    for (int i = 0; i < l; i++)
    {
        temp = temp->next;
    }
    return (temp->data);
}

template <class T>
T *LinkedList<T>::SeeAt() // not required but makes more sense
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    return (current->data);
}

template <class T>
void LinkedList<T>::Reset()
{
    current = head;
}

template <class T>
bool LinkedList<T>::Available(string s)
{
    return (current->data->Availaible(s));
}

template <class T>
void LinkedList<T>::PrintAll()
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    Node<T> *temp = current;
    current = head;
    ascii_art("null");
    ascii_art("  |");
    SeeAt()->Display();
    while (current->next != nullptr)
    {
        ascii_art("  |  |  ");
        cout << endl;
        SeeNext()->Display();
    }
    ascii_art("     |");
    ascii_art("null");
    current = temp;
}

template <class T>
void LinkedList<T>::ascii_art(string input)
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