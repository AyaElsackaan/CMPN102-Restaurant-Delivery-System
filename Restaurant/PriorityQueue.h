#pragma once
#include "Generic_DS/Node.h"
#include "PriorityQueueInterface.h"
#include "SortedListLinkedList.h"
template <typename T>
class PriorityQueue :public PriorityQueueInterface<T>
{
	SortedListLinkedList<T> Mylist;
public:
	~PriorityQueue();
	bool isEmpty()const;
	bool add(const T& Item) ;
	bool remove(T& Item) ;
	bool Peek(T& Item);
	void Print();
	int getCount();
	T* toArray();
};
template < class T>
T * PriorityQueue<T>::toArray()
{
	T * QueueCont = new T[Mylist.getCount()];
	
	int counter = 0;
	while (counter<Mylist.getCount())
	{
		T item;
	    Mylist.getEntry(counter,item);
		QueueCont[counter] = item;
		counter++;
	} // end while
	return QueueCont;
} // end toArray
template <typename T>
int PriorityQueue<T>::getCount()
{
	return Mylist.getCount();
}
template<typename T>
inline PriorityQueue<T>::~PriorityQueue()
{
	Mylist.clear();
}
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return Mylist.isEmpty();
}
template <typename T>
bool PriorityQueue<T>::add(const T& Item)
{
	
	return Mylist.insertSorted(Item);
}
template <typename T>
bool PriorityQueue<T>::remove(T& Item)
{
	 Mylist.getEntry(0,Item);
	return Mylist.remove(0);
}
template <typename T>
bool PriorityQueue<T>::Peek(T& Item)
{
	return  Mylist.getEntry(0, Item);
}
template <typename T>

void PriorityQueue<T>::Print()
{
	Mylist.PrintList();
}
