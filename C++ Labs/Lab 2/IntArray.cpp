/** Implementation file for the class IntArray.
 	 @file IntArray.cpp 
 	 @author Mohammed Milten 
 */

#include "IntArray.h"
#include <iostream>

bool IntArray::setNumber(int pos, int n)
{
	if(pos < 10)
	{
		num[pos] = n;
	}
	
	return false;
	
}

// clears the array by putting 0s in all the elements
void IntArray::clear()
{
	for (int i=0; i < 10; i++)
	{
		num[i]=0;
	}
}

void IntArray::displayNumbers()
{
	cout << "The numbers are ";
	for (int i = 0; i < 10; i++)
	{
		cout << num[i] << " ";
	}
}

void IntArray::getStats(int &min, int &max, double &avg)
{
	min = num[0];
	max = num[0];
	avg;
	int sum = 0;
	
	
	for (int i = 0; i < 10; i++)
	{
		sum += num[i];
		if(min > num[i])
		{
			min = num[i];
		}
		if (max < num[i])
		{
			max = num[i];
		}
	}
	
	avg = (double) sum/10;
	
	cout << sum;
	cout << " " << endl;
	cout << "The values range from " << min << " to " << max << " with an average value of " << avg;
}

