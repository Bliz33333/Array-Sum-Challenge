//============================================================================
// Name        : Practice_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Find the subarray that has the greatest value when all of
//				 its elements are summed together
//============================================================================

#include <iostream>
using namespace std;

int sum(int array[], int startIndex, int endIndex)
{
	int sum = 0;
	for(int i = startIndex; i < endIndex + 1; i++)
	{
		sum += array[i];
	}
	return sum;
}


int main()
{
	int n = 0;

	cout << "Enter the number of values in the set:" << endl;
	cin >> n;
	cout << endl;

	int array[n];
	for(int i = 0; i < n; i++)
	{
		cout << "Enter the value for index number " << i << ":" << endl;
		cin >> array[i];
	}

	int last = -1;
	int startSum = 0;
	int first = -1;
	int endSum = 0;

	for(int i = 0; i < n; i++)
	{
		if(sum(array, 0, i) >= startSum)
		{
			last = i;
			startSum = sum(array, 0 , i);
		}

		if(sum(array, i, n - 1) >= endSum)
		{
			first = i;
			endSum = sum(array, i , n - 1);
		}
	}

	cout << "The first index is: " << first << " and the last index is: " << last << endl;
	if(first == -1 || last == -1)
	{
		cout << "The largest consecutive subset is empty: {}" << endl;
		return 0;
	}

	cout << "The largest consecutive subset is: ";
	cout << " {";
	for(int i = first; i < last; i++)
	{
		cout << array[i] << ", ";
	}
	cout << array[last] << "}";

	getchar();
	return 0;
}

