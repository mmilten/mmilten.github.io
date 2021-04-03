/**
	@file MonthDays.cpp
	@author Mohammed Milten
	Defines a MonthDays object and methocs to support the object
*/
#include "MonthDays.h"
#include <iostream>

MonthDays::MonthDays()
{
   month = 0;
   year = 0;
}

MonthDays::MonthDays(int monthNumber, int yearNumber)
{
   setMonth(monthNumber);
   setYear(yearNumber);
}

void MonthDays::setMonth(int newMonth)
{
   month = newMonth;
}

void MonthDays::setYear(int newYear)
{
   year = newYear;
}

int MonthDays::getMonth()
{
   return month;
}

int MonthDays::getYear()
{
   return year;
}

int MonthDays::getNumberOfDays()
{
   int numberDays = 0;
      
   switch (month)
   {
      case 1: case 3: case 5:
         case 7: case 8: case 10:
         case 12:
         numberDays = 31;
         break;
      case 4: case 6:
         case 9: case 11:
         numberDays = 30;
         break;
      case 2:
         if (((year % 4 == 0) && !(year % 100 == 0))
                 || (year % 400 == 0))
            numberDays = 29;
         else
            numberDays = 28;
         break;
      default: 
         break; 
   }
   return numberDays;
}

std::string MonthDays::getMonthName()
{
   std::string monthString = " ";
   
   switch (month) 
   {
      case 1:  
         monthString = "January";
         break;
      case 2:  
         monthString = "February";
         break;
      case 3:  
         monthString = "March";
         break;
      case 4:  
         monthString = "April";
         break;
      case 5:  
         monthString = "May";
         break;
      case 6:  
         monthString = "June";
         break;
      case 7:  
         monthString = "July";
         break;
      case 8:  
         monthString = "August";
         break;
      case 9: 
         monthString = "September";
         break;
      case 10: 
         monthString = "October";
         break;
      case 11: 
         monthString = "November";
         break;
      case 12: 
         monthString = "December";
         break;
      default: 
         monthString = "Invalid month";
         break;
   }
   return monthString;    

}

void MonthDays::display()
{
	std::cout << getMonthName() << " in year " << getYear() << " has "
			    << getNumberOfDays() << " days.\n";
}