/**
	@file Client.cpp
	@author Mohammed Milten
	This program demonstrates using the IntArray class. It creates an 
	array that stores 10 integers provided by the user. It then uses that
	array to display the full array along with the range from minimum 
	value to maximum value and the average value in the array.
	
NOTE: Must use make utlility to create executable - jGrasp hammer icon
*/
#include "IntArray.h"
#include <iostream>

int main()
{
	IntArray num;
	char choice;
	int n;
	int min = 0;
	int max = 0;
	double avg;
		
	do
	{	
		for (int i=1; i<=10;i++)
		{
			cout << "Enter number " << i << ":";
			cin >> n;
			
			num.setNumber(i-1, n);			
		}
	
	
		num.displayNumbers();
		num.getStats(min, max, avg);
		num.clear();
		
		
		cout << "\nDo you want to enter another set of integers? (Y/N) ";
      cin >> choice;
      
	}while (tolower(choice) != 'n');
	
	return 0;
}
