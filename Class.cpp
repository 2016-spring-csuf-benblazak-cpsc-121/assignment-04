#include "Class.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

void print_vector(vector<int> P){
	for (int e : P) {
		cout << e << " \n";
	}
}

vector<int> selection_sort(vector<int> a)
{
	return vector<int>();
}

vector<int> selection_sort(vector<int> v) {//v for vector
	if (v.size() <= 1){//baseclass
		return;
	}

	int min_index = 0;
	for (size_t i = 0; i < v.size(); i++){
		min_index = i;
			
		for (size_t x = i + 1; x < v.size(); x++) {
			if (v[i]> v[x])
				min_index = x;
		}
		int temp = v[min_index];
		v[min_index] = v[i];
		v[i] = temp;
}

	vector<int> merge_sort(vector<int> m) {
		//baseclass
		if (m.size() <= 1)
			return;

		size_t split = (m.size()) / 2;

		vector <int> left(m.begin(); m.begin() + split);

		vector <int> right(m.begin() + split, m.being());

		left = m(left);

		right = m(right);

		vector <int> sorted;
		int r = 0, l = 0;//right /left

		while (l < left.size() && r < right.size()) {
			if (right[r] < left[l]) {
				sorted.pushback(right[r]);
				r++;
			}
			else {
				sorted.push_back(left[l]);
				l++;
			}
		}
}