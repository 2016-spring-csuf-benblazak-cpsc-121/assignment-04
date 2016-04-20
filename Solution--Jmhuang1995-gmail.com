/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Justin Huang <jmhuang1995@gmail.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A short program to demostrate selection sort and merge sort.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(const vector<int> & v)
{
	for (int e : v)
		cout << e << " " << endl;

}

void selection_sort(vector<int> &v)
{
	for (vector<int>::iterator first_unS = v.begin();
	first_unS != v.end(); first_unS++)
	{
		vector<int>::iterator min = first_unS;

		for (vector<int>::iterator first_unC = first_unS; first_unC != v.end(); first_unC++)
		{
			if (*min > *first_unC)
			{
				min = first_unC;
			}
		}
		int temp = *first_unS;
		*first_unS = *min;
		*min = temp;
	}
	
}

vector<int> merge_sort(const vector<int> & v)
{
	//base case
	if (v.size() < 2)
	{
		return v;
	}
	// split
	vector<int> left{ v.begin(), v.begin() + v.size() / 2 };
	vector<int> right{ v.begin() + v.size() / 2, v.end() };
	
	// sorrt each side
	left = merge_sort(left);
	right = merge_sort(right);


	//merge
	vector<int> sorted;
	vector<int>::iterator l = left.begin();
	vector<int>::iterator r = right.begin();
	while (l != left.end() && r != right.end())
	{
		if (*l < *r)
		{
			sorted.push_back(*(l++));
		}
		else
	{
			sorted.push_back(*(r++));
	}
		while (l != left.end())
		{
			sorted.push_back(*(l++));
		}
		while (r != right.end())
		{
			sorted.push_back(*(r++));
		}

		return sorted;

	}
}

int main()
{
	vector<int> vectors[] =
	{
		vector<int>{1,2,3 ,4 ,5 ,6, 7,},
	vector<int>{55,79,88,74,11,10,43,},
	vector<int>{23,48,64,79,446,9,77,},
	vector<int>{49,22,11,44,66,88,79,22},
	vector<int>{123,445,6,8,2,10,15},
	vector<int>{48,99,79,95,91,95,93},
	};

	for (vector<int> & v : vectors)
	{


		{
			print_vector(v);

			vector<int>temp = v;
			selection_sort(temp);
			print_vector(temp);
		}

		print_vector(v);
		print_vector(merge_sort(v));

		cout << endl;
	}
	return 0;
}
