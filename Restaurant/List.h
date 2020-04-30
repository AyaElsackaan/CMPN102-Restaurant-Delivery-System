#pragma once
#include"Generic_DS/Node.h"
template <typename T>
class List
{
public:

	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insert(int newPosition, const T& newEntry) = 0;
	virtual bool insertEnd(T it) = 0;
	virtual bool remove(int position) = 0;
	virtual T removeBeg() = 0;
	virtual void clear() = 0;
	virtual bool getEntry(int position, T & item) = 0;
	virtual bool setEntry(int position, const T& newEntry) = 0;
	virtual Node<T>* getHead() = 0;
	virtual T* toArray()=0;

};