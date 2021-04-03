/** The third part of Lab 1 that asks the user for a range of the highest number
  * and the number of elements to be played in a lottery ticket.
  *
  *
  * @author Mohammed Milten
  * @file Part3
*/

#include <iostream> 	// std::cin, std::cout
#include <vector>   	// std::vector
#include <algorithm>	// std::random_shuffler, std::sort


std::vector<int> lotto(int i, int j); // prototype function lott0 
void display(std::vector<int>v);		  // prototype function display

int main()
{
   int i = 0; // Upper rang eof available number
   int j = 0; // Count of number to be played
   std::vector<int>v;
	char choice;
	
	do
	{
   std::cout << "Enter the highest number: ";
   std::cin >> i;
	
   std::cout << "How many numbers should be generated? ";
   std::cin >> j;
	
   v = lotto(i,j);	// call the lotto function and store value in vector v
	display(v);			// call the display function
	
	std::cout << "\nDo you want to generate another ticket? ( Y or N): ";
	std::cin >> choice;
	
	}while(tolower(choice) != 'n');
   
	
	
}


/**
	lotto function - the function takes 2 parameters from the user to determine the
	range and numbers generated for a vector
	@param i a integer value that represents the highest value of the vector
	@param j a integer value that determines the amount of elements inside the vector
	@return a vector v
*/

std::vector<int> lotto(int i, int j)
{
   std::vector<int>v; // Vector of integers

	
   for (int k = 1; k <= i; k++)
   {
      v.push_back(k);
   }
	
   std::random_shuffle(v.begin(), v.end());
	v.resize(j);
   std::sort (v.begin(), v.end());
   std::cout << "\nYour randomly generated ticket: ";

   return v;
	
}

/**
	display function - a function that displays the numbers generated for the lotter ticket
	@param v2 - a vector of numbers for the lottery ticket
	@return void
*/
void display(std::vector<int>v2)
{
   std::cout << "You generated: ";
   for (std::vector<int>::iterator it=v2.begin(); it!=v2.end(); ++it)
      std::cout << ' ' << *it;
		
   std::cout << '\n';

}