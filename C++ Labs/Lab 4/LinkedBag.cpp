//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedBag.
 	 @file LinkedBag.cpp 
 	 @author Mohammed Milten 
 */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
   itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
      
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
   return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
   
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
   itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::bagUnion(const LinkedBag<ItemType> &otherBag) const
{
	// make a new LinkedBag that will hold the union of the two bags
	// copy into unionBag using the copy constructor
   LinkedBag<ItemType> unionBag = LinkedBag(otherBag);
	
   Node<ItemType>* origChainPtr = headPtr; // Points to nodes in original chain
   while(origChainPtr != nullptr) 
   {
   	// copy first node
      unionBag.add(origChainPtr->getItem());
      origChainPtr = origChainPtr->getNext();
   }
   return unionBag;
}

template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::bagIntersection(const LinkedBag<ItemType> &otherBag) const
{
	// make a new LinkedBag that will hold the interset of the two bags
   LinkedBag<ItemType> intersectionBag;
	
	// traverse the existing linked list
   Node<ItemType>* callerPtr = headPtr;
   Node<ItemType>* otherPtr = otherBag.headPtr;
	
   while(callerPtr != nullptr)
   {
      while(otherPtr != nullptr)
      {
         if(callerPtr->getItem() == otherPtr->getItem()) // if there's a match
         {
         	// add to intersect
            intersectionBag.add(callerPtr->getItem());
         	// stop looking for this value
            otherPtr = otherPtr->getNext();
            break;
         }
      	// go to next item in otherPtr
         otherPtr = otherPtr->getNext();
      }
   	// reset paramPtr
      otherPtr = otherBag.headPtr;
   	//advance to the next item in callerPtr
      callerPtr = callerPtr->getNext();
   }
	
   return intersectionBag;
} // end bagInterset

template<class ItemType>
LinkedBag<ItemType> LinkedBag<ItemType>::bagDifference(const LinkedBag<ItemType> &otherBag) const
{
	// make a new LinkedBag to hold the difference
   LinkedBag<ItemType> differenceBag;
	
	// traverse the existing linked list
   Node<ItemType>* callerPtr = headPtr;
   Node<ItemType>* otherPtr = otherBag.headPtr;
	
	// add the difference of the first bag compared to second bag
   while(callerPtr != nullptr)
   {
      while(otherPtr != nullptr)
      {
      	// compare items
         if(callerPtr->getItem() == otherPtr->getItem())
         {
         	// do nothing
            break;
         }
			
			// check to see if the item is already in differnceBag
         if(differenceBag.contains(callerPtr->getItem()))
         {
         	// do nothing 
            break;
         }
      	  	
      	// if we get to the end of otherBag and don't find it
         if(otherPtr->getNext() == nullptr)
         {
            // add to difference
               differenceBag.add(callerPtr->getItem());

         }
      	//advance to the next item in otherPtr
         otherPtr = otherPtr->getNext();
      }
   	// reset otherPtr
      otherPtr = otherBag.headPtr;
   	// advance to the next item in callerPtr
      callerPtr = callerPtr->getNext();
   }
	
	
	// add the difference of the second bag compared to the first bag
   while(otherPtr != nullptr)
   {
      while(callerPtr != nullptr)
      {
			// compare items
			if(otherPtr->getItem() == callerPtr->getItem())
			{
				// do nothing
				break;
			}
			
			// check to see if the item is already in differnceBag
			if(differenceBag.contains(otherPtr->getItem()))
			{
				// do nothing
				break;
			}
			
			if(callerPtr->getNext() == nullptr)
			{
				//add to difference
				differenceBag.add(otherPtr->getItem());
			}
			//advance to the next item in callerPtr
			callerPtr = callerPtr->getNext();
      }
		// reset callerPtr
		callerPtr = headPtr;
		// advance to the nex item in otherPtr
		otherPtr = otherPtr->getNext();
   }
	
   return differenceBag;
	
} // end bagDifference
