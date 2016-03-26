/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program to test merge sort and selection sort
*/

#include "Selection_Sort.h"
#include "Merge_Sort.h"
#include <iostream>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::setfill;
using std::setw;

int main()
{
	cout << setw(80) << setfill('-') << " ";
	cout << "Testing Selection Sort.\n\n";
	vector<int> v = { 10, 19, 99, 2, 0, -10, -100, 14, 15, 18, 22 };

	print_vector(v);
	selection_sort(v);
	print_vector(v);
	cout << setw(80) << setfill('-') << " ";

	cout << "Testing Merge Sort\n\n";

	vector<int> v2 = { 100, -49, 60, 72, 102, 7, 49, 89, };

	print_vector(v2);
	merge_sort(v2, 0, v2.size());

	return 0;
}
