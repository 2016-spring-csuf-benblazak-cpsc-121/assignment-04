/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Marcus Hoertz <marcus.hoertz@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A short program to display selection sort and merge sort.
*/

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
void print_vector(const vector<int> & n)
{
	for (int i = 0; i <= n.length; i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;
}

void selection_sort(vector<int> & n)
{
	int temp, min;
	for (int i = 0; i <= n.length; i++)
	{
		min = i;
		for (int j = i + 1; j <= n.legnth; j++)
		{
			if (n[j] < n[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			temp = n[i];
			n[i] = n[min];
			n[min] = temp;
		}

	}
}

vector<int> merge_sort(const vector<int> & n)
{
	//base case
	if (n.length == 1) return n;
	vector<int> left;
	vector <int> right;
	//splitting into two vectors
	for (int i = 0; i <= n.length / 2; i++)
	{
		left.push_back(n[i]);
	}
	for (int i; i <= n.length; i++)
	{
		right.push_back(n[i]);
	}
	//recursive cases
	merge_sort(left);
	merge_sort(right);
	vector<int> sorted;
	//merging into sorted
	for (int i = 0; i <= left.length || i <= right.length; i++)
	{
		//Doesn't work quite right, need to iron it out
		if (left[i] <= right[i])
		{
			sorted.push_back(left[i]);
			i++
		}
		else if (right[i]<left[i])
		{
			sorted.push_back(right[i]);
			i++
		}
		if (i> left.length)
		{
			for (; i <= right.length; i++)
			{
				sorted.push_back(right[i]);
			}
		}
		else if (i>right.length)
		{
			for (; i <= left.length; i++)
			{
				sorted.push_back(left[i]);
			}

		}
	}
	return sorted;
}

int main()
{
	return 0;
}
