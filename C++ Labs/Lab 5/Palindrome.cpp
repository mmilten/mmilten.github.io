/**
 * @file Palindrome.cpp
 * @author Mohammed Milten
 * @date October 17, 2017
 * Evaluates a string to determine if it is a palindrome or not.
 */
#include "Palindrome.h"
#include <iostream>
#include <string>
using namespace std;

Palindrome::Palindrome () 
{
   phrase = "";
}


Palindrome::Palindrome (string newPhrase) 
{
   phrase = newPhrase;
}
   

// After completing this method, submit the entire .cpp
// file as your solution for Lab 5. See method description in 
// Palindrome.h
bool Palindrome::evalPalindrome (string& reversePhrase)
{
   char ph;

	// Hold the phrase in a char array stack
   for(int i = 0; i < phrase.length(); i++)
   {
      ph = phrase[i];
		letters.push(ph);
   }
	
	// Reverse the phrase including all puncutations and spaces
   while(!letters.isEmpty())
   {
      reversePhrase += letters.peek();
      letters.pop();
   }
	
	
	// remove any whitespace and punctuation in the original phrase and lower case the characters
   for(int i = 0; i < phrase.length(); i++)
   {
      if(ispunct(phrase[i]) || isspace(phrase[i]))
      {
         phrase.erase(i--,1);
         phrase.length();
      }
   	
      phrase[i] = tolower(phrase[i]);
   }
	
	
	string reverseCopy = reversePhrase; // make a copy of reversePhase	
	
	// remove any whitespace and punctuation and lower case the characters from the copy
	for(int i = 0; i < reverseCopy.length(); i++)
	{
		if(ispunct(reverseCopy[i]) || isspace(reverseCopy[i]))
		{
			reverseCopy.erase(i--,1);
			reverseCopy.length();
		}
		reverseCopy[i] = tolower(reverseCopy[i]);
	}
	
	// checks if reverseCopy is a palindrome
   for(int j = 0; j <= phrase.length() && j <= reverseCopy.length(); j++)
   {
      if(reverseCopy[j] == phrase[j])
      {
       	// do nothing
      }
      else
      {
         return false;
      }
   }

   return true;
}
