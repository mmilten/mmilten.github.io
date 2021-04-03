/**
 * @file Palindrome.h
 * @author Professor Gregory
 * @class Palindrome
 * Evaluates a string to determine if it is a palindrome or not. A palindrome is 
 * a sequence of characters that reads the same both forward and backward.  An 
 * uppercase character is considered equivalent to the same character in 
 * lowercase, and spaces and punctuation are ignored.
 */
#include <string>
#include <cctype>
#include "ArrayStack.h"
using namespace std;

#ifndef PALINDROME_H
#define PALINDROME_H 
class Palindrome
{
private:
   /**
    * stores the letters in the string while it is being evaluated
    * to determine if it is a palindrome
    */
   ArrayStack<char> letters; 

   /**
    * original phrase to evaluate to determine if it is a palindrome
    */
   string phrase;

public:
   /**
    * Default constructor. Initializes expression to an empty string.
    */
   Palindrome ();

   /**
    * Overloaded constructor that initializes the phrase.
    * @param - newPhrase - original phrase tested to determine if it is a 
    *          palindrome
    */
   Palindrome (string newPhrase); 
   
   /**
    * Evaluates the phrase to determine if it is a palindrome. Uses
    * a stack to reverse the order of the letters in the phrase and
    * to determine if the original phrase is a palindrome. A palindrome
    * is a sequence of letters that reads the same forward and backward;
    * however, all spaces and punctuation are ignored.
    * @return - true if phrase is a palindrome; false otherwise                     
    * @param reversePhrase - orginal phrase in reverse order, including
    *                        all puncutation and spaces
    */
   bool evalPalindrome (string& reversePhrase); 
};
#endif