/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Chuoy <HyrekanDragon@yahoo.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* The Functions used in Merge Sort file
*/

#ifndef MERGE_SORT_H
#define MERGE_SORT_H	

#include <vector>

using std::vector;

vector<int> merge_sort(vector<int> &v, int low, int high);

vector<int> merge(vector<int> left, vector<int> right);

#endif
