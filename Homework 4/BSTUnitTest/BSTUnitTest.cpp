#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework 4/BST.h"
#include "../Homework 4/BST.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BSTUnitTest
{
	TEST_CLASS(BSTUnitTest)
	{
	public:

		TEST_METHOD(ConstructorMethod)
		{
			BST<int>* tree = new BST<int>();
			Assert::AreEqual(0, tree->getSize());
		}

		TEST_METHOD(getSizeMethod)
		{
			BST<int>* tree = new BST<int>();
			Assert::AreEqual(0, tree->getSize()); // Checks to see if new tree returns 0.
			tree->Insert(5);
			tree->Insert(3);
			Assert::AreEqual(2, tree->getSize()); // Checks to see if size is incremented after adding two nodes.
			tree->Remove(5);
			Assert::AreEqual(1, tree->getSize()); // Checks to see if size is decremented after removing a node.
			tree->Remove(3);
			Assert::AreEqual(0, tree->getSize()); // Checks to see if empty tree returns 0.
		}

		TEST_METHOD(InsertMethod)
		{
			BST<int>* tree = new BST<int>();
			Assert::AreEqual(0, tree->getSize()); // Checks to see if new tree returns 0.
			tree->Insert(5);
			Assert::AreEqual(1, tree->getSize()); // Checks to see if size is incremented after adding a node.
			tree->Insert(3);
			tree->Insert(7);
			Assert::AreEqual(3, tree->getSize()); // Checks to see if size is incremented after adding two nodes.
		}

		TEST_METHOD(FindMethod)
		{
			BST<int>* tree = new BST<int>();
			tree->Insert(3);
			tree->Insert(5);
			tree->Insert(7);
			Assert::AreEqual(5, *(tree->Find(5))); // Checks to see if 5 is found in the tree.
		}

		TEST_METHOD(RemoveMethod)
		{
			BST<int>* tree = new BST<int>();
			tree->Insert(5);
			tree->Insert(3);
			tree->Insert(7);
			Assert::AreEqual(3, tree->getSize()); // Checks to see if size is incremented after adding three nodes.
			tree->Remove(5);
			Assert::AreEqual(2, tree->getSize()); // Checks to see if the size is decremented after removing a node.
		}

		TEST_METHOD(getRootMethod)
		{
			BST<int>* tree = new BST<int>(); // Creates a new tree.

			Node<int>* root;

			tree->Insert(3);
			root = tree->getRoot();
			Assert::AreEqual(root->getData(), 3); // Checks to see if root is 3.
			tree->Insert(7); // Adds a node to the right of the root.
			tree->Insert(9); // Adds a node to the right of the right node.
			root = tree->getRoot();
			Assert::AreEqual(root->getData(), 7); // Checks to see if root is 7.
		}
	};
}
