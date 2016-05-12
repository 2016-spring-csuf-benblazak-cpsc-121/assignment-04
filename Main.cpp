#include "Class.h"
#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;


int main() {
	vector <int> a = { 5 ,2 ,77,64,56,57 };

	for (int e : a) {
		
		print_vector(selection_sort(a));
		cout << endl;

		print_vector(merge_sort(a));
	}
	



	cin.get();
	cin.get();
	return 0;
}