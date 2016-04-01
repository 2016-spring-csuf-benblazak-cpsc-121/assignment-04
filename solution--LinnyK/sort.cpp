#include <iostream>
#include <vector>
#include "sort.h"

using std::cout;
using std::endl;
using std::vector;


void print_vector(const vector<int> & print)
{
	for (int i = 0; i <= print.size(); i++)
	{
		cout << print[i] << " ";
	}
}

void selection_sort(vector<int> & v)
{
	for (int a = 0; a < v.size(); a++)
	{
		for (int b = 0; b < v.size(); b++)
		{
			if (v[a] > v[b])
			{
				int Min = v[a];
				v[a] = v[b];
				v[b] = Min;
			}
		}
	}
}

vector<int> merge_sort(const vector<int> & v)
{
	if (v.size() <= 1)
		return v;
	int l = 0;
	int r = 0;
	int split = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for (int a = 0; a < split; a++)
	{
		left.push_back(v[a]);
	}
	for (int i = split; i <= v.size(); i++)
	{
		right.push_back(v[i]);
	}

	left = merge_sort(left);
	right = merge_sort(right);
	vector<int> sorted;
	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r])
		{
			sorted.push_back(left[l]);
			l++;
		}
		else
		{
			sorted.push_back(right[r]);
			r++;
		}
	}

	if (l >= left.size())
	{
		for (int a = r; a < right.size(); a++)
		{
			sorted.push_back(right[r]);
			r++;
		}
	}

	if (r >= right.size())
	{
		for (int a = l; a < left.size(); a++)
		{
			sorted.push_back(left[l]);
			l++;
		}
	}

	return sorted;
}