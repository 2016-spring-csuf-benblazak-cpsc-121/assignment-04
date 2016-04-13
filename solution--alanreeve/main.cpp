/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alan Reeve <areeve@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

// this program ..

#include "functions.h"


int main(){

	std::vector<int> vect = {4, 1, 29, 5, 10, 15, 2, 41, 20, 7};


	print_vector(vect);

	
	print_vector(merge_sort(vect));

	return 0;
}