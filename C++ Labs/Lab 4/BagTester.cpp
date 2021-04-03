//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/**
	@file BagTester.cpp
	@author Mohammed Milten 
	BagTester class that demonstrates the LinkedBag class. It creates two linked bags
	and demonstrates the union, intersection, and differenceof the bags.
	difference of each bag.
*/

#include <iostream>
#include <string>
#include "LinkedBag.h"

void bagTester();
void displayBag(LinkedBag<int>& bag);

using namespace std;

void displayBag(LinkedBag<int>& bag)
{
   vector<int> bagItems = bag.toVector();

   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   } // end for
   cout << endl << endl;
} // end displayBag



void newMethodTester()
{
   LinkedBag<int> bag;
   LinkedBag<int> bag2;
 
   int items[] = {1, 2, 3, 4, 5, 1};
   for (int i = 0; i < 6; i++)
   {
       bag.add(items[i]);
   } // end for
	
	cout << "Bag 1 contains: ";
   displayBag(bag);
  
   int items2[] = {4, 5, 6, 7, 8, 8};
   for (int i = 0; i < 6; i++)
   {
       bag2.add(items2[i]);
   } // end for
	
	cout << "Bag 2 contains: ";
   displayBag(bag2);

   LinkedBag<int> unionResult = bag.bagUnion(bag2);
   LinkedBag<int> intersectResult = bag.bagIntersection(bag2);
   LinkedBag<int> diffResult = bag.bagDifference(bag2);

	cout << "Test union method ...\n" << endl;
   displayBag(unionResult);
	
	cout << "Test intersection method ...\n" << endl;
   displayBag(intersectResult);
	
	cout << "Test difference method ...\n" << endl;
   displayBag(diffResult);

}

int main()
{
   //copyConstructorTester();
   //bagTester();
   newMethodTester();
  
   return 0;
} // end main