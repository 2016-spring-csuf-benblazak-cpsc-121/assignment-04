/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Jose Abundez <Jabundez@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void print_vector(const vector<int> & path)
{
	for (vector<int>::const_iterator i = path.begin(); i != path.end(); ++i)
		cout << *i << ' ';
}

void selection_sort(vector<int> & arr)
{
	int temp;
	for (int i = arr.size() - 1; i > 0; i--)
	{
		int min = 0;
		for (int j = 1; j <= i; j++)
			if (arr[j] > arr[min])
				min = j;

		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

vector<int> merge(vector<int>&vec, vector<int>&left, vector<int>&right)
{
	int i;

	vector<int> sorted;
	unsigned left_ = 0, right_ = 0;

	while (left_ < left.size() && right_ < right.size())
	{
		if (left[left_] < right[right_])
		{
			sorted.push_back(left[left_]);
			left_++;
		}

		else
		{
			sorted.push_back(right[right_]);
			right_++;
		}
	}

	while (left_ < left.size())
	{
		sorted.push_back(left[left_]);
		left_++;
	}

	while (right_ < right.size())
	{
		sorted.push_back(right[right_]);
		right_++;
	}

	vec = sorted;
	return vec;
}

vector<int> merge_sort(vector<int> vec)
{
	if (vec.size() == 1)
	{
		return vec;
	}

	vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
	vector<int> left(vec.begin(), middle);
	vector<int> right(middle, vec.end());

	left = merge_sort(left);
	right = merge_sort(right);

	return merge(vec, left, right);
}

int main()
{
	cout << "- Merge Sort -\nUnsorted:" << endl;
	vector<int> numbers = { 2,4,6,8,9,7,5,3,1 };
	print_vector(numbers);
	vector<int> answer = merge_sort(numbers);
	cout << "\nSorted:" << endl;
	print_vector(answer);

	cout << endl;

	cout << "\n- Selection Sort -\nUnsorted:" << endl;
	numbers = { 1,3,5,7,9,8,6,4,2 };
	print_vector(numbers);
	selection_sort(numbers);
	cout << "\nSorted:" << endl;
	print_vector(numbers);

	cout << endl;

	system("pause");
	return 0;
}
