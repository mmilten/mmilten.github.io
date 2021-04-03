//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Header file for an array-based implementation of the ADT bag.
	 @file ArrayBag.h 
 	 @author Mohammed Milten
*/

#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
   int itemCount;                         // Current count of bag items 
   int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();
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
		 
	ArrayBag<ItemType> bagUnion(const ArrayBag<ItemType> &otherBag) const;
	
	/** Creates a new bag containing the entries that occur in both
		 of the original bags.
		 @param otherBag The given bag
		 @return A bag that contains entries that occur in both bags */
		 
	ArrayBag<ItemType> bagIntersection(const ArrayBag<ItemType> &otherBag) const;
	
	/** Creates a new bag that contains the entries that would be left
		 in one bag after removing those that occur in the second bag
		 @param otherBag The given bag
		 @return A bag that contains the difference of the two bags */
		 
	ArrayBag<ItemType> bagDifference(const ArrayBag<ItemType> &otherBag) const;
	
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
