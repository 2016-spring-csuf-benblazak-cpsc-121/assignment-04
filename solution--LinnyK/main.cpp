#include <iostream>
#include <vector>
#include "sort.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	
	vector<int> a = { 7, 5, 15, 21, 19, 75, };
	vector<int> b = { 17, 19, 31, 57, 1, 9 };
	
			print_vector(a);
			vector<int> min = a;
			selection_sort(min);
			print_vector(min);
	

	print_vector(b);
	vector<int> small = b;
	print_vector(merge_sort(b));
	cout << endl;

	system("pause");
	return 0;
}