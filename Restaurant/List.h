#pragma once
# include"Generic_DS/Node.h"
template <typename T>
class List
{
public:
	
	virtual bool isEmpty() const=0;
	virtual int getLength() const=0;
	virtual bool insert(int newPosition,const T& newEntry)=0;
	virtual bool remove(int position)=0;
	virtual void clear()=0;
	/** @throw  PrecondViolatedExcep if position < 1 or position > getLength(). */
	virtual T getEntry(int position, T & item) = 0;
	/** @throw PrecondViolatedExcep if position < 1 o   position > getLength(). */
	virtual void setEntry(int position, const T& newEntry)=0;
};