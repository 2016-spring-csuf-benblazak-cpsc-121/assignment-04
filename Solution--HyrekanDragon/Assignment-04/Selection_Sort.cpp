/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program that performs selction sort on the contents of a vector
*/

#include "Selection_Sort.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(const vector<int> v)
{
	cout << "Printing out contents of the array.\n\n";

	for (int e:v)
	{
		cout << e << " ";
	}

	cout << endl << endl;
}

void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void selection_sort(vector<int> & v)
{
	cout << "Sorting out the contents of the array.\n\n";

	for (int i = 0; i < v.size(); i++)
	{
		int min = v[i];
		int min_index = i;

		for (int j = i + 1; j < v.size() - 1; j++)
		{
			if (v[j] < min)
			{
				min = v[j];
				min_index = j;
			}
		}
		swap(v[min_index], v[i]);
	}
}
