/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Diem-Huong Bui <diemhuongbui@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* -------------------------------------------------------------------------- */

/**
* A short program of functions that prints vectors, selection sorts vectors, and merge sorts vectors.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(const vector<int> &v) {
	vector<int>::const_iterator b;
	for (b = v.begin(); b != v.end(); b++) {
		cout << *b << " ";
	}
	cout << endl;
}

void selection_sort(vector<int> &v) {
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		int temp = 0;
		vector<int>::iterator min = i;
		for (vector<int>::iterator k = i; k != v.end(); k++) {
			if (*min > *k)
				min = k;
		}
		temp = *i;
		*i = *min;
		*min = temp;
	}
}

vector<int> merge_sort(const vector<int> &v) {
	if (v.size() < 2) return v;
	
	vector<int> leftSide{ v.begin(), v.begin() + v.size() / 2 }; //left begins with 1st element to the middle
	vector<int> rightSide{ v.begin() + v.size() / 2, v.end() }; //right begins with middle 
	
	leftSide = merge_sort(leftSide);
	rightSide = merge_sort(rightSide);
	
	vector<int> sort;
	vector<int>::iterator left = leftSide.begin();
	vector<int>::iterator right = rightSide.begin();
	while (left != leftSide.end() && right != rightSide.end())
		if (*left < *right)
			sort.push_back(*(left++));
		else
			sort.push_back(*(right++));
	while (left != leftSide.end())
		sort.push_back(*(left++));
	while (right != rightSide.end())
		sort.push_back(*(right++));
	
	return sort;
}

int main() {

	//test print_vector
	cout << "Testing print_vector()" << endl;
	vector<int> v = { 1, 5, 8 };
	print_vector(v);
	

	//test selection_sort
	cout << "Testing selection_sort()" << endl;
	vector<int> test = { 3, 1, 2 };

	//prints out test, set temp to test, sorts temp, prints temp
	print_vector(test);
	vector<int> temp = test;
	selection_sort(temp);
	print_vector(temp);
	

	//test merge_sort
	cout << "Testing merge_sort()" << endl;
	vector<int> mergeTest = { 7, 10, 4, 3 };
	print_vector(mergeTest);
	print_vector(merge_sort(mergeTest));
	
	system("pause");
	return 0;
}
