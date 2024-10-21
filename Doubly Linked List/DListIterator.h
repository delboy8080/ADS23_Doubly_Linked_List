template <class T> class DList;
template <class T> class DListIterator;
template <class T> class DListNode;

#pragma once

#include "DList.h"
#include "DListNode.h"

template <class T>
class DListIterator
{
public:
	DListNode<T>* currentNode;
	DList<T>* list;

	DListIterator(DList<T>* l = nullptr, DListNode<T>* node = nullptr);
	void start();
	void end();
	void advance();
	void previous();
	T item();
	bool isValid();
	bool isEnd();
	bool isStart();

	// Add the dereference, increment and decrement operators
	T& operator*();
	DListIterator<T> operator++();
	DListIterator<T> operator++(int i);

	DListIterator<T> operator--();
	DListIterator<T> operator--(int i);

};
template <class T>
T& DListIterator<T>::operator*()
{
	return currentNode->data;
}
template <class T>
DListIterator<T> DListIterator<T>::operator++()
{
	currentNode = currentNode->next;
	return *this;
}
template <class T>
DListIterator<T> DListIterator<T>::operator++(int i)
{
	DListIterator<T> temp(*this);
	currentNode = currentNode->next;
	return temp;

}
template <class T>
DListIterator<T> DListIterator<T>::operator--()
{
	currentNode = currentNode->previous;
	return *this;
}
template <class T>
DListIterator<T> DListIterator<T>::operator--(int i)
{
	DListIterator<T> temp(*this);
	currentNode = currentNode->previous;
	return temp;
}


template <class T>
DListIterator<T>::DListIterator(DList<T>* l, DListNode<T>* n)
{
	list = l;
	currentNode = n;
}

template <class T>
void DListIterator<T>::start()
{
	currentNode = list->head;
}

template <class T>
void DListIterator<T>::end()
{
	currentNode = list->tail;
}
template <class T>
void DListIterator<T>::advance()
{
	if (currentNode == nullptr)
		return;
	currentNode = currentNode->next;
}

template <class T>
void DListIterator<T>::previous()
{
	if (currentNode == nullptr)
		return;
	currentNode = currentNode->previous;
}
template <class T>
T DListIterator<T>::item()
{
	return currentNode->data;
}

template <class T>
bool DListIterator<T>::isValid()
{
	return currentNode != nullptr;
}

template <class T>
bool DListIterator<T>::isEnd()
{
	return currentNode == list->tail;
}

template <class T>
bool DListIterator<T>::isStart()
{
	return currentNode == list->head;
}