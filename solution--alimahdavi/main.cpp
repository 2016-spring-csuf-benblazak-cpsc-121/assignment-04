/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 alimahdavi <alimahdavi05@csu.fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;

void print_vector(const vector<int> & v) {
	for (int e : v)
		cout << e << " ";
	cout << endl;
}

void selection_sort(vector<int> & v) {
	// for the index of each element in the array (the "current index")
	for (vector<int>::iterator first_unsorted = v.begin();
		first_unsorted != v.end();
		first_unsorted++) {

		// find the index of the minimum element at or after the current index
		vector<int>::iterator min = first_unsorted;

		for (vector<int>::iterator first_uncompared = first_unsorted;
			first_uncompared != v.end();
			first_uncompared++) {

			if (*min > *first_uncompared)
				min = first_uncompared;
		}

		// swap the element at the current index with the smallest element
		// found
		int temp = *first_unsorted;
		*first_unsorted = *min;
		*min = temp;
	}
}

vector<int> merge_sort(const vector<int> & v) {
	// base case
	if (v.size() < 2)
		return v;

	// split
	vector<int> left{ v.begin(), v.begin() + v.size() / 2 };
	vector<int> right{ v.begin() + v.size() / 2, v.end() };

	// recursively sort each side
	left = merge_sort(left);
	right = merge_sort(right);

	// merge
	vector<int> sorted;
	vector<int>::iterator l = left.begin();
	vector<int>::iterator r = right.begin();
	while (l != left.end() && r != right.end())
		if (*l < *r)
			sorted.push_back(*(l++));
		else
			sorted.push_back(*(r++));
	while (l != left.end())
		sorted.push_back(*(l++));
	while (r != right.end())
		sorted.push_back(*(r++));

	return sorted;
}

int main() {
	std::string line;

	int number;
	vector<int> numbers;

	cout << "Enter your vector numbers separated by spaces: ";
	std::getline(std::cin, line);

	std::istringstream stream(line);
	while (stream >> number)
		numbers.push_back(number);

	cout << endl << "Your vector: " << endl;
	print_vector(numbers);
	cout << endl;

	vector<int>temp = numbers;

	selection_sort(temp);
	cout << "Selection sorted: " << endl;
	print_vector(temp);
	cout << endl;

	cout << "Merge sorted: " << endl;
	print_vector(merge_sort(numbers));

	system("pause");

	return 0;
}
