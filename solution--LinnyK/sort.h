#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
using std::vector;

void print_vector(const vector<int> & n); 

void selection_sort(vector<int> & v);

vector<int> merge_sort(const vector<int> & v);

#endif