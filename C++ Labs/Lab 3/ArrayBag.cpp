//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayBag.
 	 @file ArrayBag.cpp 
 	 @author Mohammed Milten 
 */

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
   bool hasRoomToAdd = (itemCount < maxItems);
   if (hasRoomToAdd)
   {
      items[itemCount] = newEntry;
      itemCount++;
   }  // end if
    
   return hasRoomToAdd;
}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/   
 
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
   bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
   if (canRemoveItem)
   {
      itemCount--;
      items[locatedIndex] = items[itemCount];
   }  // end if
    
   return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   for (int i = 0; i < itemCount; i++)
      bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
   bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType> &otherBag) const
{
   ArrayBag<ItemType> unionBag;

	// add items from the first bag to the new bag
   for (int i = 0; i < itemCount; i++)
      unionBag.add(items[i]);
		
	// add items from the second bag to the new bag
   for (int i = 0; i < otherBag.getCurrentSize(); i++)
      unionBag.add(otherBag.items[i]);
	
   return unionBag;
}	//end bagUnion

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagIntersection(const ArrayBag<ItemType> &otherBag) const
{
	/** The count of an item in the intersection of two bags is
		 the smaller of the count in each bag */
		 
   ArrayBag<ItemType> intersectionBag;
	ArrayBag<ItemType> copyOfOtherBag;
	
	// copy the second bag
   for(int i = 0; i < otherBag.getCurrentSize(); i++)
   {
		copyOfOtherBag.add(otherBag.items[i]);
   }
	
	/** Add to the intersectionBag each item in this bag
		 that matches an item in in otherBag, once matched,
		 remove the item from the second bag */
	
	for(int i = 0; i < getCurrentSize(); i++)
	{
		if(copyOfOtherBag.contains(items[i]))
		{
			intersectionBag.add(items[i]);
			copyOfOtherBag.remove(items[i]);
		}
	}
	
   return intersectionBag;
}	//end bagIntersection

template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagDifference(const ArrayBag<ItemType> &otherBag) const
{
	/** The count of an item in the difference is the difference
	    of the counts in the two bags. */
		 
   ArrayBag<ItemType> differenceBag;
	
	//copy the first bag
   for(int i = 0; i < itemCount; i++)
   {
      differenceBag.add(items[i]);
   }
	
	//removce the ones that are in otherBag
   for(int i = 0; i < otherBag.getCurrentSize(); i++)
   {
      if(differenceBag.contains(otherBag.items[i]))
      {
         differenceBag.remove(otherBag.items[i]);
      }
   }
   return differenceBag;

}	//end bagDifference