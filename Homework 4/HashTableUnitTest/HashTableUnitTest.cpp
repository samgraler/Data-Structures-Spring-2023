#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework 4/HashTable.h"
#include "../Homework 4/HashTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableUnitTest
{
	TEST_CLASS(HashTableUnitTest)
	{
	public:
		
		TEST_METHOD(Find)
		{
			HashTable<int>*  Hash1 = new HashTable<int>();
			HashTable<int>* Hash2 = new HashTable<int>();
			Hash1->Insert(new int(5));
			Hash2->Insert(new int(5));
			Assert::AreEqual(Hash1->Find(new int(5)), Hash2->Find(new int(5)));
		}
		TEST_METHOD(Insert)
		{
			HashTable<int>* Hash = new HashTable<int>();
			for(int i = 0; i <500; i++){
				Hash->Insert(new int(i));
			}
			Assert::AreEqual(Hash->GetLength(), 500);
		}
		TEST_METHOD(Remove)
		{
			HashTable<int>* Hash = new HashTable<int>();
			for (int i = 0; i < 500; i++) {
				Hash->Insert(new int(i));
			}
			for (int i = 0; i < 500; i++) {
				Hash->Remove(new int(i));
			}
			Assert::AreEqual(Hash->GetLength(), 0);
		}
	};
}
