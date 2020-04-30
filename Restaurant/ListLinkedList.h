#pragma once
#include "Generic_DS/Node.h"
#include "List.h"
template <typename T>
class ListLinkedList :public List<T>
{
	Node<T>* Head;
	Node<T>* backptr;
	int count;
	Node<T>* GetNodeAt(int pos);
public:
	ListLinkedList();
	T* toArray();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const T& newEntry);
	bool insertEnd(T it);
	bool remove(int position);
	T removeBeg();
	void clear();
	bool getEntry(int position, T & item);
	bool setEntry(int position, const T& newEntry);
	void PrintList();
	int GetCount();
	void DeleteNode(T item);
	Node<T>* getHead();
	

};
template < class T>
T * ListLinkedList<T>::toArray()
{
	T * QueueCont = new T[count];
	Node<T>* curPtr = Head;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < count))
	{
		QueueCont[counter] = curPtr->getItem();
		curPtr = curPtr->getNext();
		counter++;
	} // end while
	return QueueCont;
} // end toArray
template <typename T>
T ListLinkedList<T>::removeBeg()
{

	Node<T>* temp = Head;
	T data = Head->getItem();
	Head = Head->getNext();
	delete temp;
	count--;
	return data;
}
template <typename T>
bool ListLinkedList<T>::insertEnd(T newEntry)
{
	if (isEmpty())
	{

		Node<T>* temp = new Node<T>;
		temp->setItem(newEntry);
		Head = temp;
		backptr = temp;
		count++;
		return true;

	}
	Node<T>* temp = new Node<T>;
	temp->setItem(newEntry);
	backptr->setNext(temp);
	backptr = temp;
	count++;
	return true;
}
template <typename T>
void ListLinkedList<T>::PrintList()
{
	Node<T>*temp = Head;
	int c = 1;
	while (temp)
	{
		cout << c << "-" << " Item :" << temp->getItem() << endl;
		c++;
		temp = temp->getNext();
	}
}
template<typename T>
inline int ListLinkedList<T>::GetCount()
{
	return count;
}
template<typename T>
inline void ListLinkedList<T>::DeleteNode(T item)
{
	Node<T>*Temp = Head;
	if (Temp->getItem() == item)
	{
		Head = Head->getNext();
		delete Temp;
		count--;
		return;
	}
	while (Temp->getNext())
	{
		if (Temp->getNext()->getItem() == item)
		{
			Node<T>*del = Temp->getNext();
			Temp->setNext(del->getNext());
			delete del;
			count--;
			return;
		}
		Temp = Temp->getNext();
	}
}
template<typename T>
inline Node<T>* ListLinkedList<T>::getHead()
{
	return Head;
}
template <typename T>
ListLinkedList<T>::ListLinkedList()
{
	count = 0;
	Head = nullptr;
	backptr = nullptr;
}

template <typename T>
bool ListLinkedList<T>::isEmpty() const
{
	if (count == 0)
		return true;
	return false;
}

template <typename T>
int ListLinkedList<T>::getLength() const
{
	return count;
}

template <typename T>
bool ListLinkedList<T>::insert(int pos, const T& newEntry)
{
	if (pos<0 || pos>count)
	{
		return false;
	}
	if (pos == 0)
	{

		Node<T>* temp = new Node<T>;
		temp->setItem(newEntry);
		temp->setNext(Head);
		Head = temp;
		if (isEmpty())
			backptr = temp;
		count++;
		return true;

	}
	if (pos == count)
	{
		Node<T>* temp = new Node<T>;
		temp->setItem(newEntry);
		backptr->setNext(temp);
		backptr = temp;
		count++;
	}
	Node<T>* temppr = new Node <T>;
	temppr = GetNodeAt(pos - 1);
	Node<T>* temp1 = new Node<T>;
	temp1->setItem(newEntry);
	temp1->setNext(temppr->getNext());
	temppr->setNext(temp1);
	count++;
	return true;
}

template<typename T>
Node<T>* ListLinkedList<T>::GetNodeAt(int pos)
{
	if (pos<0 || pos>count - 1)
		return nullptr;
	int var = 0;
	Node<T>* temp = new Node<T>;
	temp = Head;
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
bool ListLinkedList<T>::remove(int pos)
{
	if (pos<0 || pos>count - 1)
		return false;
	if (pos == 0)
	{
		Node<T>* temph = Head;

		Head = Head->getNext();
		delete temph;
		count--;
		if (isEmpty())
			backptr = nullptr;
		return true;
	}
	if (pos == count - 1)
	{
		Node<T>* temppr;
		temppr = GetNodeAt(pos - 1);
		temppr->setNext(nullptr);
		delete backptr;
		backptr = temppr;
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
void ListLinkedList<T>::clear()
{
	while (!isEmpty())
	{
		remove(0);
	}
}
template<typename T>
bool ListLinkedList<T>::getEntry(int pos, T & item)
{
	if (pos<0 || pos>count - 1)
		return false;
	Node<T>* tempf = new Node<T>;
	tempf = GetNodeAt(pos);
	if (tempf == nullptr)
		return false;
	item = tempf->getItem();
	return true;
}
template<typename T>
bool ListLinkedList<T>::setEntry(int pos, const T& newEntry)
{
	if (pos<0 || pos>count - 1)
		return false;
	Node<T>* temps = new Node<T>;
	temps = GetNodeAt(pos);
	temps->setItem(newEntry);
	return true;

}