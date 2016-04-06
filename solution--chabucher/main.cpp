#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

//Generic vector printing function. Used for debugging.
void print_vector(const vector<int> & v) {
	for (int i : v)
		cout << i << " ";
	cout << endl;
}

vector<int> selection_sort(vector<int> &);
vector<int> merge(vector<int>, vector<int>);
vector<int> merge_sort(vector<int> &);

int main() {

	vector<int> a = { -3,6,3,8,4,8,4,0,0,3,2,5,345 };
	vector<int> b = { -34,7,3,9,19,43,8,9,65,2,34,5 };
	
	merge_sort(a);
	print_vector(a);
	print_vector(selection_sort(a));
	print_vector(merge_sort(b));
	print_vector(selection_sort(b));

	system("Pause");

	return 0;
}


vector<int> merge(vector<int> v, vector<int> w) {

	//Create empty vector
	vector<int> sorted;

	//while both lists are non empty...
	while (v.size() != 0 && w.size() != 0) {
		//Compare the first element in both vectors.
		//Remove that element from it's respective vector and place at the end of sorted.
		if (v[0]<w[0]) {
			sorted.push_back(v[0]);
			v.erase(v.begin());
		}
		else {
			sorted.push_back(w[0]);
			w.erase(w.begin());
		}
	}

	//A vector might still be non-zero..
	//Add every element from that vector to the end of sorted.

	if (v.size() != 0) {
		for( int i : v)
			sorted.push_back(i);
	}

	if (w.size() != 0) {
		for (int i : w)
			sorted.push_back(i);
	}

	//Debugging section
	/*
	cout << "sorted begin:\n";
	print_vector(sorted);
	cout << "sorted end:\n";
	*/

	return sorted;
}

vector<int> merge_sort(vector<int> & v) {

	//Base case
	if (v.size() == 1) return v;

	//Determine half size of the vector
	int half_size = v.size() / 2;

	//Split vector in half
	vector<int> lo(v.begin(), v.begin() + half_size);
	vector<int> hi(v.begin() + half_size, v.end());

	//Debugging section
	/*
	cout << "lo and hi begin:\n";
	print_vector(lo);
	print_vector(hi);
	cout << "lo and hi end:\n";
	*/

	//Recursively merge sort the two split halves, based on the above merge method.
	return merge(merge_sort(lo), merge_sort(hi));
}


vector<int> selection_sort(vector<int> & v) {
	//Loop through the vector
	for (int i = 0; i < v.size(); i++) {
		//Create temp min value and position of the min value variables
		int temp_min = v[i];
		int min_pos = i;
		//Loop through remainder of the vector
		for (unsigned int j = i; j < v.size(); j++) {
			//Find the smallest value and save its info
			if (v[j]<temp_min) {
				temp_min = v[j];
				min_pos = j;
			}
		}
		//Swap min info with the current iteration
		v[min_pos] = v[i];
		v[i] = temp_min;
	}

	return v;
}
