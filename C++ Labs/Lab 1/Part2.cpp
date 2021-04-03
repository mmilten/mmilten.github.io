/** The secondpart of a c++ program that reads strings from a file and determines whether the word begins with 
  * 	1. A vowel
  *     2. A consonant
  *	3. Or something else such as a number
  * The program outputs the number of words read that begin with a vowel, a consonant, and one
  * that fits neither of those categories.
  *
  * @author Mohammed Milten
  * @file Part2
*/

#include <iostream>     // std::cout
#include <cstdlib> 		// Where EXIT_SUCCESS is defined
#include <sstream>      // std::stringstream
#include <string>       // std::string
#include <fstream>      // std::ifstream

/**
*	@brief Gets the vowel, consonate, and other variable count
*
*	@param w a constant string variable
*	@param v a initialized integer variable
*	@param c a initialized integer variable
*	@param n a initialized integer variable
*	@return void
*/
void wordCount(const std::string w, int& v, int& c, int& n); // function prototype for wordCount


int main()
{

   int vowelCount = 0;
   int consonantCount = 0;
   int otherCount = 0;
	
   std::ifstream inFile("wordstrings.txt");
   std::string inputline;
 
    
   getline(inFile, inputline);    // read the first line from the file
	

   while (inFile)                 // while successful read
   {  	
      std::istringstream iss(inputline);
   
      std::cout << "Input string: " << ":";
      
      std::string oneWord;           
      iss >> oneWord;          // get first word
      
      while (iss)              // continue until the end is reached
      {  
         
         std::cout << " " << oneWord;
         iss >> oneWord;       // get next word
			
			wordCount(oneWord, vowelCount, consonantCount, otherCount);
      }
      std::cout << std::endl;
   	// Display the information to the user
      
      std::cout << vowelCount << " begins with a vowel" << std::endl;
      std::cout << consonantCount << " begins with a consonant"<< std::endl;
      std::cout << otherCount << " other 'words' were found" << std::endl;
		
		vowelCount = 0;					 // reset variable
		consonantCount = 0;				 // reset variable
		otherCount = 0;					 // reset variable
   
      getline(inFile, inputline);    // read next line from file
   	
   }
   return 0; 
}

/**	
*	wordCount - string variable isint varaibles are passed by reference.  v, w, and n are created as local
*  variables using the same memory location as the variables passed.  Hence, any
*  changes to v, w, and n will also change the variables passed to the function.
*/
void wordCount(const std::string w, int& v, int& c, int& n)
{
   if (isalpha(w[0]) == false) 																					// Determines if the word begins with neither a vowel or consonant
   {
      n++; 		// The other counter
   }
   else if (tolower(w[0]) == 'a' || tolower(w[0]) == 'e' || tolower(w[0]) == 'i' || 			// Determines if the word begins with a vowel
      		  tolower(w[0]) == 'o' || tolower(w[0]) == 'u')
   {
      v++; 		// The vowel counter
   }
   else																													// The word begins with a consonant 
   {
      c++;		// The consonant counter
   }
   	
}
