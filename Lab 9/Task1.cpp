#include "BST.h"
#include "BST.cpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	BST<int> Tree;
	Tree.Insert(10);
	Tree.Insert(11);
	Tree.Insert(9);
	Tree.Insert(8);
	Tree.Insert(7);
	
	Tree.Print(Tree.getRoot());
	cout << endl;

	return 0;
}