#include "CppUnitTest.h"
#include "../Doubly Linked List/DList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<DListNode<int>>(const DListNode<int> &b)
			{
				return L"DListNode";
			};
		}
	}
}
namespace DoublyLinkedListTests
{		
	TEST_CLASS(DListNodeTest)
	{
	public:
		/*
			Test to ensure value is setted and next and previous are set to
			null when constructor is called
		*/
			

		TEST_METHOD(TestConstructor)
		{
			DListNode<int> node(5);
			Assert::AreEqual(5, node.data);
			Assert::IsNull(node.next);
			Assert::IsNull(node.previous);
		}

		/*
			Test of insert after with a single node 
			Tests teh correct value is set and the correct links are established
			using next and previous

		*/
		TEST_METHOD(TestInsertAfter)
		{
			DListNode<int> node(5);
			Assert::AreEqual(5, node.data);
			node.insertAfter(6);
			Assert::IsNotNull(node.next);
			Assert::AreEqual(6, node.next->data);
			Assert::AreSame(node, *(node.next->previous));
		}
		/*
			Test insert after correctly inserts a value between 2 existing nodes
			initial list: {5, 7}
			final list : {5,6,7}

			test checks teh values are in the correct place and next/previous 
			are pointing correctly in the new node
		*/
		TEST_METHOD(TestInsertAfterBetweenTwoNodes)
		{
			DListNode<int> node(5); // add 5
			node.insertAfter(7);// add 7 next
			DListNode<int> *finalNode = node.next;
			node.insertAfter(6);// place 6 between 5 and 7
			DListNode<int> *next = node.next;
			Assert::IsNotNull(next);
			Assert::AreEqual(6, next->data);
			Assert::AreSame(node, *next->previous);
			Assert::AreSame(*finalNode, *next->next);
			Assert::AreSame(*finalNode->previous, *next);
			Assert::AreSame(*(node.next), *next);

		}

		/*
		Test of insert before with a single node
		Tests teh correct value is set and the correct links are established
		using next and previous

		*/
		TEST_METHOD(TestInsertBefore)
		{
			DListNode<int> node(5);
			Assert::AreEqual(5, node.data);
			node.insertBefore(4);
			Assert::IsNotNull(node.previous);
			Assert::AreEqual(4, node.previous->data);
			Assert::AreSame(node, *(node.previous->next));
		}
		/*
		Test insert before correctly inserts a value between 2 existing nodes
		initial list: {5, 7}
		final list : {5,6,7}

		test checks the values are in the correct place and next/previous
		are pointing correctly in the new node
		*/
		TEST_METHOD(TestInsertBeforeBetweenTwoNodes)
		{
			DListNode<int> node(5); // add 5
			node.insertAfter(7);// add 7 next
			DListNode<int> *finalNode = node.next;
			finalNode->insertBefore(6);// place 6 between 5 and 7
			DListNode<int> *next = node.next;
			Assert::IsNotNull(next);
			Assert::AreEqual(6, next->data);
			Assert::AreSame(node, *next->previous);
			Assert::AreSame(*finalNode, *next->next);
			Assert::AreSame(*finalNode->previous, *next);
			Assert::AreSame(*(node.next), *next);

		}
	};
}