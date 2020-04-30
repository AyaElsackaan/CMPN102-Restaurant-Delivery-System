#pragma once
template <typename T>
class SortedListInterface
{
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insertSorted(T it)= 0;
	virtual bool removeSorted(const T& it) = 0;
	virtual int getPosition(const T& it) const= 0;
	virtual bool remove(int position) = 0;
	virtual void clear() = 0;
	virtual bool getEntry(int position, T & item) = 0;
	virtual Node<T>* getHead()=0;

};
