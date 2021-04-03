//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
 
/** Header file for a link-based implementation of the ADT bag.
	 @file LinkedBag.h 
 	 @author Mohammed Milten
*/
#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;
	
	/** Creates a new bag containing the combined contents of the 
		 original two bags.
		 @param otherBag The given bag.
		 @return A bag that is the union of the two bags. */
		 
	LinkedBag<ItemType> bagUnion(const LinkedBag<ItemType> &otherBag) const;
	
	/** Creates a new bag containing the entries that occur in both
		 of the original bags.
		 @param otherBag The given bag
		 @return A bag that contains entries that occur in both bags */
		 
	LinkedBag<ItemType> bagIntersection(const LinkedBag<ItemType> &otherBag) const;
	
	/** Creates a new bag that contains the entries (from both bag) that would be 
		 unique in one bag (not duplicated in its own bag, also not another bag).
		 @param otherBag The given bag
		 @return A bag that contains the unique difference of the two bags */
		 
	LinkedBag<ItemType> bagDifference(const LinkedBag<ItemType> &otherBag) const;
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif