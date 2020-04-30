#pragma once
#include "Generic_DS/Node.h"
#include "SortedListInterface.h"
template <typename T>
class SortedListLinkedList :public SortedListInterface<T>
{
	Node<T>* Head;
	int count;
	Node<T>* GetNodeAt(int pos);
	Node<T>* GetNodeBef(T item);
public:
	~SortedListLinkedList();
	SortedListLinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insertSorted(T it);
	virtual bool removeSorted(const T& it);
	virtual int getPosition(const T& it)const;
	int getCount();
	bool remove(int position);
	void clear();
	bool getEntry(int position, T & item);
	Node<T>* getHead();
	
};
template<typename T>
inline Node<T>* SortedListLinkedList<T>::getHead()
{
	return Head;
}

template <typename T>
int SortedListLinkedList<T>:: getPosition(const T& it) const
{
	int c = 0;
	Node<T>*temp = Head;
	while (temp)
	{
		if (temp->getItem() == it)
			return c;
		c++;
		temp = temp->getNext();
	}
	return -1;
 }
template<typename T>
inline int SortedListLinkedList<T>::getCount()
{
	return count;
}
template<typename T>
inline SortedListLinkedList<T>::~SortedListLinkedList()
{
	clear();
}
template <typename T>
SortedListLinkedList<T>::SortedListLinkedList()
{
	count = 0;
	Head = nullptr;
}

template <typename T>
bool SortedListLinkedList<T>::isEmpty() const
{
	if (count == 0)
		return true;
	return false;
}

template <typename T>
int SortedListLinkedList<T>::getLength() const
{
	return count;
}

template<typename T>
void SortedListLinkedList<T>::clear()
{
	while (!isEmpty())
	{
		remove(0);
	}
}

template<typename T>
bool SortedListLinkedList<T>::remove(int pos)
{
	if (pos<0 || pos>count - 1)
		return false;
	if (pos == 0)
	{
		Node<T>* temph = Head;
		Head = Head->getNext();
		delete temph;
		count--;
		return true;
	}
	Node<T>* temppr = new Node<T>;
	temppr = GetNodeAt(pos - 1);
	Node<T>* tempdel = new Node<T>;
	tempdel = temppr->getNext();
	temppr->setNext(tempdel->getNext());
	delete tempdel;
	count--;
	return true;
}

template<typename T>
Node<T>* SortedListLinkedList<T>::GetNodeAt(int pos)
{
	if (pos<0 || pos>count - 1)
		return nullptr;
	int var = 0;
	Node<T>* temp = Head;
	
	if (pos == 0)
	{
		return Head;

	}
	while (var < pos)
	{
		temp = temp->getNext();
		var++;
	}
	return temp;
}

template<typename T>
bool SortedListLinkedList<T>::getEntry(int pos, T & item)
{
	if (pos<0 || pos>count - 1)
		return false;
	Node<T>* tempf = GetNodeAt(pos);

	item = tempf->getItem();
	return true;
}
//Not finished
template <typename T>
bool SortedListLinkedList<T>::insertSorted(T it)
{
	if (Head == nullptr)
	{
		Node<T>*temp = new Node<T>;
		temp->setItem(it);
		Head = temp;
		count++;
		return true;
		
	}
	T temp = Head->getItem();
	bool check = *it > *temp;
	if (check)
	{
		Node<T>*temp = new Node<T>;
		temp->setItem(it);
		temp->setNext(Head);
		Head = temp;
		count++;
		return true;
		
	}
	Node<T>*temp3 = Head;
	while (temp3->getNext())
	{
		if (*(temp3->getNext()->getItem()) < *it)
		{
			Node<T>*temp1 = new Node<T>;
			temp1->setItem(it);
			temp1->setNext(temp3->getNext());
			temp3->setNext(temp1);
			count++;
			return true;
		}
		temp3 = temp3->getNext();
	}
	Node<T>*temp2 = new Node<T>;
	temp2->setItem(it);
	temp3->setNext(temp2);
	count++;
	return true;
}
//
template <typename T>
bool SortedListLinkedList<T>::removeSorted(const T& it)
{
	if (Head == nullptr) { return false; }
	Node<T>*temp = Head;
	if (Head->getItem() == it)
	{
		Head = Head->getNext();
		delete temp;
		return true;
	}
	while (temp->getNext())
	{
		if (temp->getNext()->getItem()==it)
		{
			Node<T>*temp2 = temp->getNext();
			temp->setNext(temp2->getNext());
			delete temp2;
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

template <typename T>
Node<T>* SortedListLinkedList<T>::GetNodeBef(T it)
{
	Node<T>* temppr = new Node;
	Node<T>* tempf = new Node;
	tempf = Head;
	if (Head->getItem() == it)
	{
		return nullptr;
	}
	while (tempf)
	{
		if (tempf->getItem == it)
		{
			return temppr;
		}
		temppr = tempf;
		tempf = tempf->getNext();
	}
	return temppr;
}
