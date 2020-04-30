#pragma once
template <class T>
class PriorityQueueInterface
{
	virtual bool isEmpty()const=0;
	virtual bool add(const T& Item) = 0;
	virtual bool remove(T& Item)=0;
	virtual bool Peek(T& Item)= 0;
	virtual T* toArray() = 0;
};
