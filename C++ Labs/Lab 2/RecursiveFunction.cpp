/** The first part of a c++ program that prints the a character repeatedly 
  * to form a line of the given number of character from the user.
  *
  * @author Mohammed Milten
  * @file RecursiveFunction
*/
#include <iostream>     // std::cout
#include <cstdlib> 		// Where EXIT_SUCCESS is defined


void printLine(char c, int i); // prototype function printLine

int main()
{
	char c; // character to display
	int i = 0; // the number of times to prints
	
	std::cout << "Which character should I display? ";
	std::cin >> c;
	
	std::cout << "How many should I display? ";
	std::cin >> i;
	
	printLine(c,i); // recursive call
	
	return EXIT_SUCCESS;
}

/**
	printLine function - the function uses two parameters from the user to 
	display the character and number of times specified by the user in a line
	@param c The character to print
	@param i The number of times to print 
	@return void
*/
void printLine(char c, int i)
{

	if (i > 0)
	{
		std::cout << c;
		printLine(c, i-1); // recursive call 
	}
}


