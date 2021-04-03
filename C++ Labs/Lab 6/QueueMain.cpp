/**
 * @file QueueMain.cpp
 * @author Mohammed Milten
 * @date October 17, 2017
 * This program creates a queue of Civil War officers who agree to a pact 
 * to determine which of them is to go for help because they are surrounded 
 * by Union forces and there is no chance for victory without reinforcements. 
 * They must choose an officer to go for help. The officers form a queue and 
 * they pick a number from a hat.  Beginning with the first officer in the 
 * queue, they begin to count.  As each officer counts off, he moves to the 
 * end of the queue.  When the count reaches the number that was picked, that 
 * officer is removed from the queue, and the count begins again with the 
 * next man.  The last officer that remains in the queue is the one that rides 
 * away on their only horse, Little Sorrel, to summon help.
 *
 * The program inputs the list of officers from a text file and puts each name
 * into a queue. The program is incomplete because the countOff() method has
 * not been implemented. 
 
 */  

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <cassert>
#include "LinkedQueue.h"
using namespace std;

/**
 * Name of input file containing officer names
 */
const char INPUT_FILE[] = "officers.txt"; 
/**
 * Inputs data from a text file and places each officer's name into the
 * queue passed as a parameter.
 * @param officers - dynamic queue of Confederate officers in the Civil War
 */ 
void loadQueue(LinkedQueue<string> &officers);

/**
 * Displays a list of officers removed from the queue and also displays
 * the name of the officer going for help. Retrieves officers from the 
 * officers queue, one at a time, counting as each is retrieved. If the 
 * count is not equal to hatNumber, the officer is put back into the
 * queue. When the count reaches hatNumber, that officer is removed from
 * the queue permanently (i.e., not put back into the queue), and the
 * officer's name is output to the screen. The last officer remaining in
 * the queue is the one shown as going for help.
 * @param officers - dynamic queue of Confederate officers in the Civil War
 * @param hatNumber - the number drawn from the hat, used to count off
 */ 
void countOff (LinkedQueue<string> officers, int hatNumber);

int main (void)
{
   ifstream inFile(INPUT_FILE); // declare and open the input file
   int count;  // number used for counting off
   LinkedQueue<string> officers; // queue containing officer names
   string officerName; // name of officer in front of queue
   string firstName; // name of first officer in original queue

   loadQueue(officers);
   
   // Display list of officers in original queue
   cout << "Officers in original queue: " << endl;
   firstName = officers.peekFront();
   cout << firstName << endl;
   officers.dequeue();
   officers.enqueue(firstName);
   officerName = officers.peekFront();
   while (firstName != officerName)
   {
      cout << officerName << endl;
      officers.dequeue();
      officers.enqueue(officerName);
      officerName = officers.peekFront();
   }

   // Test countOff() method using various numbers drawn from the hat
   count = 4;
   cout << endl << endl<< "Count is: " << count << endl;
   countOff (officers, count);
   count = 5;
   cout << endl << endl << "Count is: " << count << endl;
   countOff (officers, count);
	count = 8;
	cout << endl << endl << "Count is: " << count << endl;
   countOff (officers, count);
	
	return EXIT_SUCCESS;
}


void loadQueue(LinkedQueue<string> &officers)
{
   ifstream inFile(INPUT_FILE); // declare and open the input file
   string officerName; // name of officer input from file

   if (!inFile)
      cout << "Error opening file for input: " << INPUT_FILE << endl;
   else
   {
      getline (inFile, officerName);
      while (!inFile.eof())
      {
         officers.enqueue(officerName);
         getline (inFile, officerName);
      }
      inFile.close();
   }
}


void countOff (LinkedQueue<string> officers, int count)
{
   int hatNumber = count; // number in hat pulled
   int num = 1; // beginning of the queue
   string lastOfficer; // officer that is to be removed from queue
   string tempOfficer; // officer that remains in the queue
	
   cout << "\nOfficers leaving the queue are: " << endl;
   while(!officers.isEmpty()) //the queue is not empty
   {
      if(num != hatNumber)
      {
         tempOfficer = officers.peekFront();
         officers.dequeue(); // removes officer from queue
         officers.enqueue(tempOfficer);  // moves officer to the back of the queue
         num++;
      }
   	
      if(num == hatNumber)
      {
         lastOfficer = officers.peekFront();
         officers.dequeue(); // removes the officer from queue
         num = 1;
      	
         if(lastOfficer != tempOfficer) // if the officer is not in queue
         {
            cout << lastOfficer << endl; // displays the officer to be removed
         }
      }
   	
   }//end while
	
   cout << "\nThe officer going for help is: " << lastOfficer << endl;
}
