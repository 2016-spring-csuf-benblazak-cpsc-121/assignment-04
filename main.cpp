/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Burke Masles <burkemasles@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Assaingment 4: Selection Sort & Merge Sort
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


void print_vector(const vector<int> & x) 
{
	for (int i = 0; i < x.size(); i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}

vector<int> Selection_Sort(const vector<int> & v)
{
	vector<int> x = v;
	for (int startIndex = 0; startIndex < x.size(); startIndex++)
	{
		int minIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < x.size(); currentIndex++)
		{
			if (x[currentIndex] < x[minIndex]) minIndex = currentIndex;
		}
		int temp = x[startIndex];
		x[startIndex] = x[minIndex];
		x[minIndex] = temp;
	}
	return x;
}

vector<int> Merge_Sort(const vector<int> & v)
{
	vector<int> z = v;
	if (z.size() < 2)
	{
		return z;
	}
	vector<int> left;
	vector<int> right;
	int mid = z.size() / 2;
	for (int i = 0; i < mid; i++)
	{
		left.push_back(z[i]);
	}
	for (int i = mid; i < z.size(); i++)
	{
		right.push_back(z[i]);
	}
	left = Merge_Sort(left);
	right = Merge_Sort(right);
	vector<int> sorted;
	if (left[0] <= right[0])
	{
		for (int i = 0; i <= left.size()-1; i++)
		{
			sorted.push_back(left[i]);
		}
		for (int i = 0; i <= right.size()-1; i++)
		{
			sorted.push_back(right[i]);
		}
	}
	if (left[0] > right[0])
	{
		for (int i = 0; i <= right.size()-1; i++)
		{
			sorted.push_back(right[i]);
		}
		for (int i = 0; i <= left.size()-1; i++)
		{
			sorted.push_back(left[i]);
		}
	}
	return sorted;
}

int main() 
{
	vector<int> x = { 12, 2, 1, 8, 4, 5, 22, 19, };
	print_vector(Selection_Sort(x));
	print_vector(Merge_Sort(x));
}