/** The first part of a c++ program that reads a word at a time and determines whether the word begins with 
  * 	1. A vowel
  *     2. A consonant
  *	3. Or something else such as a number
  * The program outputs the number of words that begin with a vowel, a consonant, and one
  * that fits neither of those categories
  *
  * @author Mohammed Milten
  * @file Part1
*/

#include <iostream>     // std::cout
#include <cstdlib> 		// Where EXIT_SUCCESS is defined



int main()
{
   std::string word;
   int vowelCount = 0;
   int consonantCount = 0;
   int otherCount = 0;

   std::cout << "Enter words (quit to end): " << std::endl;
	
   std::cin >> word;				// Inputs the string of words entered by the user into the variable word
	
   while(word != "quit")		// Quits the program if the word 'quit' is read by the iostream
   {	
     if (isalpha(word[0]) == false) 																					// Determines if the word begins with neither a vowel or consonant
	  {
	  		otherCount++; 			// The counter
	  }
	  else if (tolower(word[0]) == 'a' || tolower(word[0]) == 'e' || tolower(word[0]) == 'i' || 		// Determines if the word begins with a vowel
	  			  tolower(word[0]) == 'o' || tolower(word[0]) == 'u')
	  {
	  		vowelCount++; 			// The vowel counter
	  }
	  else																													  // The word begins with a consonant 
	  {
	  		consonantCount++;		// The consonant counter
	  }
		
		std::cin >> word;			// Reads the rest of the string of the variable word
     
   }
	
	// Display the information to the user
   std::cout << vowelCount << " begins with a vowel" << std::endl;
   std::cout << consonantCount << " begins with a consonant"<< std::endl;
   std::cout << otherCount << " other 'words' were found" << std::endl;
	
   return 0; 
}
