/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alan Reeve <areeve@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

// function prototypes

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

// this function takes a vector and outputs the contents to cout
void print_vector(const std::vector<int> &);

// this function takes a vector and sorts it in place 
void selection_sort(std::vector<int> &);

// takes a vector and returns another vector that is sorted
std::vector<int> merge_sort(const std::vector<int> &);

#endif