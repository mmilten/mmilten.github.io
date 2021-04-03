/** The second part of a c++ program that reads from the standard input stream
  * and displays the string in reverse order in the output stream
  *
  * @author Mohammed Milten
  * @file ReversedString
*/
#include <iostream>     // std::cout
#include <cstdlib> 		// Where EXIT_SUCCESS is defined	



std::string reversedString(std::string str); // prototype function

int main()
{
   std::string str = " ";
	
   std::cout << "Enter a sentence and I'll display it it reverse order \n";
   getline(std::cin, str);
	
   std::cout << reversedString(str);

   return EXIT_SUCCESS;
}

/**
	reversedString function - The functions reads words from a standard input stream
	by the user and puts them in reversed order
	@param s - The string entered by the user
	@return reversedString - The reversed string to display
*/
std::string reversedString(std::string s)
{
   if(s.length() == 0)	// end condition to stop recursion
	{		
		return " ";
	}
		
	std::string last(1,s[s.length()-1]);		// create string with last character 
	std::string reversed = reversedString(s.substr(0,s.length()-1)); //recursive call
	return last+reversed;   // make the last character of the string first
}
