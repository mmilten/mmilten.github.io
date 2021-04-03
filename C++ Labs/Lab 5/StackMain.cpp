/**
 * @file StackMain.cpp
 * @author Professor Gregory
 * Test Client for the Palindrome class
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "Palindrome.h"
using namespace std;

void testForPalindrome(string origPhrase);

int main (void)
{
   const int NUM_PHRASES = 4;
   string allPhrases[NUM_PHRASES] = 
   {"kayak",
    "Read dear",
    "Madam, I'm Adam",
    "The End"};
   
   for (int i = 0; i < NUM_PHRASES; i++)
      testForPalindrome(allPhrases[i]);
      
   return EXIT_SUCCESS;  
}


void testForPalindrome(string origPhrase)
{
   string reversePhrase;

   Palindrome phrase(origPhrase);

   
   if (phrase.evalPalindrome(reversePhrase))
   {
      cout << "This phrase IS a palindrome!" << endl; 
   }
   else
   {
      cout << "This phrase is NOT a palindrome." << endl; 
   }
   cout << "Original phrase: " << origPhrase << endl;
   cout << "Reverse phrase: " << reversePhrase << endl << endl;
}


