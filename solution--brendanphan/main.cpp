/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Brendan Phan <brendanphan1@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* merge sort and selection sort
*/

#include <iostream>
#include <vector>
void selection_sort(std::vector<int> & x);
void print_vector(std::vector<int> & x);
std::vector<int> merge_sort(const std::vector<int> & x);
int main()
{
	return 0;
}
void print_vector(std::vector<int> & x)
{
	for (int i = 0; i < x.size(); i++)
	{
		std::cout << x[i];
		std::cout << std::endl;
	}
}
void selection_sort(std::vector<int> & x)
{
	for (int i = 0; i < x.size(); i++)
	{
		int min = i;
		for (int j = i+1; j < x.size(); j++)
		{
			if (x[j] < x[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = x[i];
			x[i] = x[min];
			x[min] = temp;
		}
	}
}
std::vector<int> merge_sort(const std::vector<int> & x)
{
	int half = x.size() / 2;
	std::vector<int> left;
	std::vector<int> right;
	int startLeft = 0;
	int startRight = 0;
	if (x.size() == 1)
		return x;
	for (int i = 0; i < half; i++)
		left.push_back(x[i]);
	for (int i = half; i < x.size(); i++)
		right.push_back(x[i]);
	left = merge_sort(left);
	right = merge_sort(right);
	std::vector<int> sorted;
	while (startLeft < left.size() && startRight < right.size())
	{
		if (left[startLeft] < right[startRight])
		{
			sorted.push_back(left[startLeft]);
			startLeft++;
		}
		else
		{
			sorted.push_back(right[startRight]);
			startRight++;
		}
	}
	if (startLeft >= left.size())
	{
		for (int i = startRight; i < right.size(); i++)
		{
			sorted.push_back(right[startRight]);
			startRight++;
		}
	}
	if (startRight >= right.size())
	{
		for (int i = startLeft; i < left.size(); i++)
		{
			sorted.push_back(left[startLeft]);
			startLeft++;
		}
	}
	return sorted;
}	
