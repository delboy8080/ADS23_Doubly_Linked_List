
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
	TEST_CLASS(DListTest)
	{
	public:
		/*
			Test the append method on an empty list
			Checks the head and tail are set correctly.
			and the value is added to the list
		*/
		TEST_METHOD(TestAppendEmpty)
		{
			DList<int> list;
			list.append(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreSame(*list.head, *list.tail);
		}
		/*
			Test the append method with a single entry 
			in the list.
			Checks the head and tail are set correctly.
			and the value is added to the list
			and accessible fron the head

		*/
		TEST_METHOD(TestAppendOneEntry)
		{
			DList<int> list;
			list.append(4);
			list.append(5);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->data);
			Assert::AreEqual(5, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}
		/*
		Test the append method with a multiple entries
		in the list.
		Checks the head and tail are set correctly.
		and the value is added to the list 
		and accessible fron the head

		*/
		TEST_METHOD(TestAppendMultipleEntry)
		{
			DList<int> list;
			list.append(4);
			list.append(5);
			list.append(6);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->data);
			Assert::AreEqual(5, list.head->next->data);
			Assert::AreEqual(6, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}
		/*
		Test the prepend method on an empty list
		Checks the head and tail are set correctly.
		and the value is added to the list
		*/
		TEST_METHOD(TestPrependEmpty)
		{
			DList<int> list;
			list.prepend(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreSame(*list.head, *list.tail);
		}
		/*
		Test the prepend method with a single entry
		in the list.
		Checks the head and tail are set correctly.
		and the value is added to the list
		and accessible fron the head

		*/
		TEST_METHOD(TestPrependOneEntry)
		{
			DList<int> list;
			list.prepend(4);
			list.prepend(5);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(5, list.head->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}
		/*
		Test the prepend method with a multiple entries
		in the list.
		Checks the head and tail are set correctly.
		and the value is added to the list
		and accessible fron the head

		*/
		TEST_METHOD(TestPrependMultipleEntry)
		{
			DList<int> list;
			list.prepend(4);
			list.prepend(5);
			list.prepend(6);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(6, list.head->data);
			Assert::AreEqual(5, list.head->next->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}
		/*
			Tests the remove head method with a single item in the list
			head and tail should be set to nullptr
		*/
		TEST_METHOD(TestRemoveHead1Item)
		{
			DList<int> list;
			list.append(4);
			list.removeHead();
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);

		}
		/*
		Tests the remove head method with a multiple items in the list
		head and tail should be set to the same node (4)
		*/
		TEST_METHOD(TestRemoveHeadMultipleItem)
		{
			DList<int> list;
			list.prepend(4);
			list.prepend(3);
			list.removeHead();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreSame(*list.head, *list.tail);

		}
		/*
		Tests the remove head method with a 3 items in the list
		head and tail should be set to the different nodes
		head (3) tail (4)
		*/
		TEST_METHOD(TestRemoveHead3Items)
		{
			DList<int> list;
			list.prepend(4);
			list.prepend(3);
			list.prepend(2);
			list.removeHead();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(3, list.head->data);
			Assert::AreEqual(4, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}
		/*
		Tests the remove tail method with a single item in the list
		head and tail should be set to nullptr
		*/
		TEST_METHOD(TestRemoveTail1Item)
		{
			DList<int> list;
			list.prepend(4);
			list.removeTail();
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);

		}
		/*
		Tests the remove head method with a multiple items in the list
		head and tail should be set to the same node (3)
		*/
		TEST_METHOD(TestRemoveTailMultipleItem)
		{
			DList<int> list;
			list.prepend(4);
			list.prepend(3);
			list.removeTail();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(3, list.head->data);
			Assert::AreEqual(3, list.tail->data);
			Assert::AreSame(*list.head, *list.tail);

		}
		/*
		Tests the remove tail method with a 3 items in the list
		head and tail should be set to the different nodes
		head (2) tail (3)
		*/
		TEST_METHOD(TestRemoveTail3Items)
		{
			DList<int> list;
			
			list.append(2);
			list.append(3);
			list.append(4);
			list.removeTail();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(2, list.head->data);
			Assert::AreEqual(3, list.tail->data);
			Assert::AreNotSame(*list.head, *list.tail);
		}

		/*
			Test insert with iterator into an empty list.
			As the iterator is invalid this method will fail
			and the list will remain empty
		*/

		TEST_METHOD(TestInsertEmptyWithIterator)
		{
			DList<int> list;
			DListIterator<int> iter = list.getIterator();
			list.insert(iter, 1);
			Assert::IsNull(list.head);


		}
		/*
			Test the insert method (which uses insertBefore on the node) on a list with one item
			head and tail should be different items 
			head will be 2 and tail will be 1
		*/
		TEST_METHOD(TestInsertAtEnd)
		{
			DList<int> list;
			list.append(1);
			DListIterator<int> iter = list.getIterator();

			list.insert(iter, 2);
			Assert::AreEqual(2, list.head->data);
			Assert::AreNotSame(*list.head, *list.tail);
			Assert::AreEqual(1, list.tail->data);


		}
		/*
		Test the insert method (which uses insertBefore) on a list with multiple items
		inital list {1,3}
		final list {1,2,3}
		*/
		TEST_METHOD(TestInsertMiddle)
		{
			DList<int> list;
			list.append(1);
			list.append(3);
			DListIterator<int> iter = list.getIterator();
			iter.advance();
			list.insert(iter, 2);
			Assert::AreEqual(1, list.head->data);
			Assert::AreEqual(2, list.head->next->data);
			Assert::AreEqual(3, list.tail->data);


		}
		/*
			Test the remove method to remove an item from a list with one entry.
			After removing the item head and tail should both be null.
		*/
		TEST_METHOD(TestRemoveOneItem)
		{
			DList<int> list;
			list.append(1);
			DListIterator<int> iter = list.getIterator();
			list.remove(iter);
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);


		}
		/*
		Test the remove method to remove an item from a list with two entries.
		head and tail should both be the same item, 1.
		*/
		TEST_METHOD(TestRemoveAtEnd)
		{
			DList<int> list;
			list.append(1);
			list.append(2);
			DListIterator<int> iter = list.getIterator();
			iter.advance();
			list.remove(iter);
			Assert::AreEqual(1, list.head->data);
			Assert::AreSame(*list.head, *list.tail);

		}
		/*
		Test the remove method to remove an item from a list with multiple entries.
		head and tail should both be different but the middle item should be removed.
		initial list {1,2,3}
		final list {1,3}
		*/
		TEST_METHOD(TestRemoveMiddle)
		{
			DList<int> list;
			list.append(1);
			list.append(2);
			list.append(3);
			DListIterator<int> iter = list.getIterator();
			iter.advance();
			list.remove(iter);
			Assert::AreEqual(1, list.head->data);
			Assert::AreEqual(3, list.tail->data);
			Assert::AreSame(*list.tail, *list.head->next);
			Assert::AreSame(*list.head, *list.tail->previous);

		}
		/*
		Test the remove method to remove the first item from a list with multiple entries.
		the head should update to become the second entry in the inital list.
		initial list {1,2,3}
		final list {1,3}
		*/
		TEST_METHOD(TestRemoveHeadWithIterator)
		{
			DList<int> list;
			list.append(1);
			list.append(2);
			list.append(3);
			DListIterator<int> iter = list.getIterator();
			list.remove(iter);
			Assert::AreEqual(2, list.head->data);
		}
	};
}