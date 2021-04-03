#ifndef MONTHDAYS_H
/**
	@file MonthDays.h
	@author Mohammed Milten
	Defines a MonthDays object and and methods to support the object 
*/
/** Definiton of a class of MonthDays */
#include <string>

class MonthDays
{
private:
   int month;
   int year;
	
public:
 /** 
 	 Default constructor: creates a MonthDay object and 
	 initializes month to 0 and year to 0
    Precondition: None.
    Postcondition: month is 0 and year is 0
*/
   MonthDays();
	
/**
	Constructor: creates a MonthDay object and
	initilize month and year
	Precondition: monthNumber is the desired month
					  yearNumber is the desired year
	Postcondition: a MonthDay of month monthNumber and
					   year yearNumber exists
*/
   MonthDays(int monthNumber, int yearNumber);
	
/** 
	Sets (alters) the month of MonthDsy
 	Precondition: newMonth is the desired radius.
   Postcondition: the month is newMonth 
*/
   void setMonth(int mewMonth);
	
/**
	Sets (alters) the year of MonthDay
	Precondition: newYear is the desired year.
	Postcondition: the year is newYear
*/
   void setYear(int newYear);

/**
	Gets the month
	Precondition: None.
	Postcondition: returns the month
*/
   int getMonth();
	
/**
	Gets the year
	Precondition: None.
	Postcondition: returns the year
*/
   int getYear();
	
/**
	Gets the of days in the specified month
	Precondition: None.
	Postcondition: returns the number of days in a month
*/
   int getNumberOfDays();
   
   /**
   Gets the name of the month
   Precondition: None.
   Postcondition: returns the name of the month
   */
   std::string getMonthName();
/**
	Displays a string based on the input provided by the user
	Precondition: 
	Postcondition: returns the month name, year, and number of days
*/
   void display();
};
#define MONTHDAYS_H
#endif