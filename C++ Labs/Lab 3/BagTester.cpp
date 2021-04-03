// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.

/**
	@file BatTester.cpp
	@author Mohammed Milten 
	BagTester class that demonstrates the ArrayBag class. It creates four bag arrays; two 
	bags that contains strings, that demonstrates the union, intersection, and difference
	of each bag. Two bags that contains int, that demonstrates the union, intersection, and
	difference of each bag.
*/
#include <iostream>
#include <string>
#include "ArrayBag.h"
using namespace std;


void displayBag(ArrayBag<string>& bagTwo);
void displayBag(ArrayBag<string>& bag);
void bagTester(ArrayBag<string>& bag);
void intBagTester(ArrayBag<int>& bagTwo);
int main()
{
   ArrayBag<string> bag;
   ArrayBag<int> bagTwo;
   bagTester(bag);
   intBagTester(bagTwo);

   return 0;
} // end main

void displayBag(ArrayBag<int>& bagTwo)
{
   cout << "The bag contains " << bagTwo.getCurrentSize()
      << " items:" << endl;
   vector<int> bagItems = bagTwo.toVector();
   int numberOfEntries = (int)bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   } // end for
   cout << endl << endl;
} // end displayBag

void displayBag(ArrayBag<string>& bag)
{
   cout << "The bag contains " << bag.getCurrentSize()
      << " items:" << endl;
   vector<string> bagItems = bag.toVector();
   int numberOfEntries = (int)bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   } // end for
   cout << endl << endl;
} // end displayBag

void intBagTester(ArrayBag<int>& bagTwo)
{
	cout << "\n***TESTING ARRAYS CONTAINING INTS***\n" << endl;
	
   ArrayBag<int> secondBag;
	
   int first[] = {1, 2, 3, 4, 5};
   int second[] = {20, 30, 40, 50, 1};
	
   cout << "First bag: ";
   for(int i = 0; i < 5; i++)
   {
      bagTwo.add(first[i]);
   } // end for
   
   displayBag(bagTwo);
   
   cout << "Second bag: ";
   for(int i = 0; i < 5; i++)
   {
      secondBag.add(second[i]);
   } // end for
   
   displayBag(secondBag);
   
   // test bagUnion
   ArrayBag<int> unionBag;
   
   unionBag = bagTwo.bagUnion(secondBag);
   
   cout << "The bag containing the union of these bags: ";
   displayBag(unionBag);
   
   // test bagIntersection
   ArrayBag<int> intersectionBag;

   intersectionBag = bagTwo.bagIntersection(secondBag);
   
   cout << "The bag containing the intersection of these bags: ";
   displayBag(intersectionBag);
   
   //test bagDifference
   ArrayBag<int> differenceBag;
   
   differenceBag = bagTwo.bagDifference(secondBag);
   
   cout << "The bag containing the difference of these bags: ";
   displayBag(differenceBag);
	
	
}

void bagTester(ArrayBag<string>& bag)
{

	cout << "\n***TESTING ARRAYS CONTAINING STRINGS***\n" << endl;
	
   ArrayBag<string> secondBag;

   string first[] = {"one", "two", "three", "four", "five"};
   string second[] = {"twenty", "thirty", "fourty", "fifty", "one"};
   
   cout << "First bag: ";
   for(int i = 0; i < 5; i++)
   {
      bag.add(first[i]);
   } // end for
   
   displayBag(bag);
   
   cout << "Second bag: ";
   for(int i = 0; i < 5; i++)
   {
      secondBag.add(second[i]);
   } // end for
   
   displayBag(secondBag);
   
   // test bagUnion
   ArrayBag<string> unionBag;
   
   unionBag = bag.bagUnion(secondBag);
   
   cout << "The bag containing the union of these bags: ";
   displayBag(unionBag);
   
   // test bagIntersection
   ArrayBag<string> intersectionBag;

   intersectionBag = bag.bagIntersection(secondBag);
   
   cout << "The bag containing the intersection of these bags: ";
   displayBag(intersectionBag);
   
   //test bagDifference
   ArrayBag<string> differenceBag;
   
   differenceBag = bag.bagDifference(secondBag);
   
   cout << "The bag containing the difference of these bags: ";
   displayBag(differenceBag);
   
   
} // end bagTester