/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Moises Leon <ml_70@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */


#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

void print_vector(const vector<int> & p)
{
	for (int i = 0; i <= p.size(); i++)
	{
		cout << p[i] << " ";

	}
	cout << endl;
}

void selection_sort(vector<int> & v) 
{
	int temp, j, i;

	for (int j = 0; j <= v.size(); j++) {
		

		
		int iMin = j;
		
		for (int i = j + 1; i <= v.size(); i++) {
			
			if (v[i] < v[iMin]) {
				
				iMin = i;
			}
		}

		if (iMin != j) {
			temp = v[j];
			v[j] = v[iMin];
			v[iMin] = temp;

		}
	}

}

 vector<int> merge_sort(const vector<int> & v) 
{
	if (v.size() <= 1)
		return v;
	int l_start=0;
	int r_start = 0;
	int split = v.size() / 2;
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < split; i++) 
	{
		left.push_back(v[i]);

	}
	for (int i = split; i <= v.size(); i++)
	{
		right.push_back(v[i]);

	}
	left = merge_sort(left);
	right = merge_sort(right);
	vector<int> sorted;
	while (l_start < left.size() && r_start < right.size()) 
	{
		if (left[l_start] < right[r_start]) 
		{
			sorted.push_back(left[l_start ]);
			l_start++;

		}
		else 
		{
			sorted.push_back(right[r_start]);
			r_start++;

		}
	}

	if (l_start >= left.size()) 
	{
		for (int i = r_start; i < right.size(); i++) 
		{
			sorted.push_back(right[r_start]);
			r_start++;


		}


	}
	if (r_start >= right.size()) 
	{
		for (int i = l_start; i < left.size(); i++) 
		{

			sorted.push_back(left[l_start]);
			l_start++;
		}


	}
	return sorted;
}

int main() 
{
	

	return 0;
}
