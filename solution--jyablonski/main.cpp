/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Jacob Yablonski <jyablonski@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */
 
 /**
  * A program that uses merge sort and selection sort functions.
  References
  http://codereview.stackexchange.com/questions/48828/implementing-the-merge-sort-with-only-arrays-out-of-place
  http://www.cplusplus.com/forum/beginner/46753/
  */
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::endl;

void print_vector(const vector<int> & print) {
	
		for (int i = 0; i < print.size(); i++) {
		cout << print[i] << " ";
	}
}

void selection_sort(vector<int> & sort1)
{
	for (int i = 0; i < sort1.size(); i++)
	{
		for (int b = i; b < sort1.size(); b++)
		{
			if (sort1[i] > sort1[b])
			{
				int j = sort1[i];
				sort1[i] = sort1[b];
				sort1[b] = j;
			}
		}
	}
}

vector<int> merge_sort(const vector<int> & sort_merge) 
{
	
		if (sort_merge.size() < 2) 
		{
		return sort_merge;
		}
	else {
		std::size_t const half_size = sort_merge.size() / 2;
		vector<int> merge_sort_left(sort_merge.begin(), sort_merge.begin() + half_size);
		vector<int> merge_sort_right(sort_merge.begin() + half_size, sort_merge.end());
		
			merge_sort_left = merge_sort(merge_sort_left);
			merge_sort_right = merge_sort(merge_sort_right);
		
			vector<int> sorted;
		vector<int>::iterator L = merge_sort_left.begin();
		vector<int>::iterator R = merge_sort_right.begin();
		while (L != merge_sort_left.end() && R != merge_sort_right.end())
			 if (*L < *R)
			 sorted.push_back(*(L++));
		else
			 sorted.push_back(*(R++));
		while (L != merge_sort_left.end())
			 sorted.push_back(*(L++));
		while (R != merge_sort_right.end())
			 sorted.push_back(*(R++));
			return sorted;
		}
}


int main() {
	vector<int> a = { 13, 7, 5, 4, 11, 22, 17, 34 };
	print_vector(a);
	cout << endl;
	selection_sort(a);

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	vector<int> b = { 11, 4, 22, 34, 5, 13, 17, 7 };
	print_vector(b);
	cout << endl;
	merge_sort(b);

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
