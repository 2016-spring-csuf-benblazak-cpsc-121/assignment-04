/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program merge sort the contents of a vector
*/

#include "Merge_Sort.h"
#include <iostream>
#include <vector>

vector<int> merge_sort(vector<int> &v, int low, int high)
{
	//Base Case
	if (v.size() == 1)
	{
		return v;
	}

	std::cout << "Low is " << low << " and high is " << high << std::endl << std::endl;

	int middle = (low + high) / 2;

	std::cout << "The middle is " << middle << std::endl << std::endl;

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < middle; i++)
	{
		left.push_back(v[i]);
	}

	std::cout << "Printing left side\n";

	for (int e : left)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl << std::endl;

	merge_sort(left, 0, left.size());

	for (unsigned int j = middle; j < v.size(); j++)
	{
		right.push_back(v[j]);
	}

	std::cout << "Printing right side\n";

	for (int e : right)
	{
		std::cout << e << " ";
	}
	
	std::cout << std::endl << std::endl;

	merge_sort(right, 0, right.size());

	v = merge(left, right);

	for (int e : v)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl << std::endl;

	return v;
}

vector<int> merge(vector<int> left, vector<int> right)
{
	std::cout << "Left has " << left.size() << " elements.\n";

	for (int e : left)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl << std::endl;

	std::cout << "Right has " << right.size() << " elements.\n";

	for (int e : right)
	{
		std::cout << e << " ";	
	}

	std::cout << std::endl << std::endl;

	vector<int> sorted;

	unsigned int i = 0, j = 0;

	std::cout << "Sorting out elements\n\n";

	while (i < left.size() && j < right.size())
	{
		if (left[i] < right[j])
		{
			sorted.push_back(left[i]);
			i++;
		}

		else if (right[j] <= left[i])
		{
			sorted.push_back(right[j]);
			j++;
		}

		std::cout << "i is " << i << " and j is " << j << std::endl;
	}

	std::cout << std::endl;

	if (i == left.size())
	{
		for (j; j < right.size(); j++)
		{
			sorted.push_back(right[j]);
		}
	}

	if (j == right.size())
	{
		for (i; i < left.size(); i++)
		{
			sorted.push_back(left[i]);
		}
	}

	return sorted;
}
