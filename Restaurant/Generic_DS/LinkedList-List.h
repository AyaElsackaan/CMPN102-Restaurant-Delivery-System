#pragma once
#include"List.h"
#include"Node.h"
template < class ItemType>

class LinkedList : public List<ItemType>
{
private:    
	Node<ItemType>* headPtr; // Pointer to first node in the chain
	bool getNodeAt(int position, Node<ItemType>*&n) const;
	Node<ItemType>* insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);

	int count;
public:
	LinkedList();   
	LinkedList(const LinkedList<ItemType>& aList); 
	bool isEmpty() const; 
	int getLength() const; 
	bool insert(int newPosition, const ItemType& newEntry); 
	bool remove(int position); 
	void clear();
	bool getEntry(int position, ItemType & object) const;
		
	bool setEntry(int position, const ItemType& newEntry) ;
	};





template < class ItemType>
bool LinkedList<ItemType>::getEntry(int position, ItemType & object) const
{ // Enforce precondition
	 
	if ((position >= 1) && (position <= itemCount))
	{
		Node<ItemType>* nodePtr;
		if (getNodeAt(position, nodePtr))
		{
			object = nodePtr->getItem();
			return true;
		}
	}
		else
	{
		return false;
		
	} 
}
template<class ItemType>
 bool LinkedList<ItemType>::setEntry(int position, const ItemType & newEntry)
{
	 Node<ItemType>*n;
	 if (getNodeAt(position, n))
	 {
		 n->setItem(newEntry);
		 return true;
	 }
	 return false;
}


template<class ItemType>
 bool LinkedList<ItemType>::getNodeAt(int position, Node<ItemType>*&n) const
{
	 if (position >= 1) && (position <= itemCount)
	 {
		 // Count from the beginning of the chain    
		 Node<ItemType>* curPtr = headPtr;
		 for (int skip = 1; skip < position; skip++)
			 curPtr = curPtr->getNext();
		 n=curPtr;
		 return true;
	 }
	 return false;
	 
	 
}

 template<class ItemType>
 LinkedList<ItemType>::LinkedList()
 {
	 headPtr = NULL;
	 count = 0;
 }

 template<class ItemType>
 LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
 {
	 if (!aList.headPtr)
	 {
		 headPtr = nullptr;
		 count = 0;
		 return;
	 }

	 Node< ItemType>* original = aList.headPtr;

	 headPtr = new Node<ItemType>(original->getItem());
	 headPtr->setNext()
	 Node< ItemType>* newchain = headPtr->getNext;
	 original = original->getNext();

	 count = aList.count;
	 while (original->getNext())
	 {
	    newchain = new Node<ItemType>(original->getItem());
		newchain->setNext(original->getNext());
	 }
 }

 template<class ItemType>
  bool LinkedList<ItemType>::isEmpty() const
 {
	 return(headPtr==nullptr) ;
 }

  template<class ItemType>
   int LinkedList<ItemType>::getLength() const
  {
	  return count;
  }

 template<class ItemType>
 bool LinkedList<ItemType>::insert(int newPosition, const ItemType & newEntry)
 {

	 bool ableToInsert = (newPosition >= 1)&& (newPosition <= itemCount + 1); 
	 if (ableToInsert) 
	 {       
	    
		 Node<ItemType>* newNodePtr =  new Node<ItemType>(newEntry);       
		 headPtr = insertNode(newPosition, newNodePtr, headPtr);   
	 }   
		 
	 return ableToInsert;

	 
 }

	template<class ItemType>
	 bool LinkedList<ItemType>::remove(int position)
	{
		 Node<ItemType>*n;

		 if (getNodeAt(position, n))
		 {

			 return true;
		 }
		return false;
	}


	 template < class ItemType>
	 Node<ItemType>* LinkedList<ItemType>::insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr)
	 {
	 if (position == 1) 
	 {     // Insert new node at beginning of subchain       
		 newNodePtr->setNext(subChainPtr);      
		 subChainPtr = newNodePtr;       
		 itemCount++; // Increase count of entries  
	 }
	 else 
			
	 {       
	Node<ItemType>* afterPtr = insertNode(position - 1, newNodePtr, subChainPtr->getNext()); 
	 subChainPtr->setNext(afterPtr);  
	 } 
	 return subChainPtr;
	 } 



template < class ItemType>
 bool LinkedList<ItemType>::remove(int position)
 {
		 bool ableToRemove = (position >= 1) &&(position <= itemCount);
		 if (ableToRemove) 
		 {
			 Node<ItemType>* curPtr = nullptr; 
			 if (position == 1)
			 {                  
				 curPtr = headPtr;  
				 headPtr = headPtr->getNext();   
			 } 
			 else 
			 {
				 Node<ItemType>* prevPtr;
				 if (getNodeAt(position - 1, prevPtr))
				 {
					 curPtr = prevPtr->getNext();
					 prevPtr->setNext(curPtr->getNext());
				 }
			 }      
			 curPtr->setNext( nullptr ); 
			 delete curPtr;       
			 curPtr = nullptr;
			 itemCount-- ;  
		 }  
			 return ableToRemove;
	 }  




 template < class ItemType>
void LinkedList<ItemType>::clear()
 {
	 while (!isEmpty())    
		 remove(1);
 } 