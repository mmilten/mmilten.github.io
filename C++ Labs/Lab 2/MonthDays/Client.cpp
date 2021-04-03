/**
	@file Client.cpp
	@author Mohammed Milten
	This program demonstrates using the MonthDays class. It creates two
	MonthDays objects. The second is initialized with a month and year 
	provided by the end user. The result of the various methods of the
	MonthDays class are displayed to the end user and repeadeted until 
	the end user decides to discontinue
	
NOTE: Must use make utlility to create executable - jGrasp hamer icon
*/
#include "MonthDays.h"
#include <iostream>

int main()
{
   MonthDays someMonthDays;				// month is 0 and year is 0
   MonthDays myMonthDays(5, 2015);		// month is 5 and year is 2015
	
   std::cout << "The MonthDay using the default settings has a month of " 
      		 << someMonthDays.getMonth()
      		 << " and a year of "
      		 << someMonthDays.getYear()
      		 << std::endl;
				 
   int month = 0;
   int year = 0;
   char choice;
   do
   {
      std::cout << "Enter a month (1-12): ";
      std::cin >> month;
      
		while ((month > 12) || (month <= 0))
		{
			std::cout << "Invalid month! Re-Enter: ";
			std::cin >> month;
		}
		
		someMonthDays.setMonth(month);
      
      std::cout << "Enter a year: ";
      std::cin >> year;
      
            
      while (year < 1582)
      {
         std::cout << "Invalid year! Re-Enter: ";
			std::cin >> year;
		}
		
		someMonthDays.setYear(year);
    
      someMonthDays.display();
   	
      std::cout << "\nDo you want to continue? (Y/N) ";
      std::cin >> choice;
      std::cout << std::endl;
   }
   while(tolower(choice) != 'n');
	 
   return 0;

}