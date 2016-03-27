/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/*
 * header file where the class and function prototypes are declared
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

using std::vector;

class Vector                                             //Vector class
{
private:
    
public:
    void print_vector(const vector<int> &v);             //print_vector prototype

    void selection_sort(vector<int> &v);                 //selection_sort prototype
    
    vector<int> merge_sort(const vector<int> &v);        //merge_sort prototype
    
    vector<int> merge(vector<int> left, vector<int> right, vector<int> & sorted);       //merge prototype
};

#endif
