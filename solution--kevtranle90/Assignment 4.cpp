/* ----------------------------------------------------------------------------
 *Copyright &copy; 2016 YOUR_NAME <kevintran323@csu.fullerton.edu>
 *Released under the[MIT License](http://opensource.org/licenses/MIT)
 *------------------------------------------------------------------------ - */
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;
using std::endl;

void print_vector(const vector<int> & v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void selection_sort(vector<int> & v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int min, temp;
		min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}

}

vector<int> merge_sort(const vector<int> & v)
{
	if (v.size() == 1)
	{
		return v;
	}

	vector<int> sorted;
	int half = v.size() / 2;
	vector<int> left(v.begin(), v.begin() + half);
	vector<int> right(v.begin() + half, v.end());

	left = merge_sort(left);
	right = merge_sort(right);

	vector<int>::iterator v_left = left.begin();
	vector<int>::iterator v_right = right.begin();
	while (v_left != left.end() && v_right != right.end())
	{
		if (*v_left < *v_right)
		{
			sorted.push_back(*v_left);
			v_left++;
		}
		else
		{
			sorted.push_back(*v_right);
			v_right++;
		}
	}
	while (v_left != left.end())
	{
		sorted.push_back(*v_left);
		v_left++;
	}

	while (v_right != right.end())
	{
		sorted.push_back(*v_right);
		v_right++;
	}
	return sorted;
}

int main()
{
	cout << "Original list: ";
	vector<int> numbers = { 3, 5, 6, 4, 1, 9, 2 };
	print_vector(numbers);
	vector<int> mergesort = merge_sort(numbers);
	cout << "Merge Sort: " ;
	print_vector(mergesort);
	cout << endl;
	cout << "Original list: ";
	print_vector(numbers);
	selection_sort(numbers);
	cout << "Selection Sort: ";
	print_vector(numbers);
	cout << endl;

	return 0;
}
