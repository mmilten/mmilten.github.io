/** Header file for an array that accepts user input and uses
	 the array to determine values 
	 @file IntArray.h 
 	 @author Mohammed Milten
*/

#ifndef INTARRAY_H
using namespace std;


class IntArray
{
private:
	static const int MAX_NUMBERS = 10;		//max number of elements
	int num[MAX_NUMBERS];
	
public:
	/**
		accepts an integer value to be stored in the array
		returns true if there is room in the array, and the 
		integer was successfully stored. Returns false otherwise
	*/
	bool setNumber(int pos, int n);
	
	/**
		removes all values from the array so that the array
		can be reused
	*/
	void clear();
	
	/**
		displays the values currently stored in the array
	*/
	void displayNumbers();
	
	/**
		determines the largest, smallest, and average of the values
		currently stored in the array. These values are returned to the 
		caller via refernce parameters
	*/
	void getStats(int& min, int& max, double& avg);
};
#define INTARRAY_H
#endif