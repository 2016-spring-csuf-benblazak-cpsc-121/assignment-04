/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/*
 * A program that calls 2 functions which sort numbers in increasing order.
 */

#include <iostream>
#include <vector>

#include "vector.h"

using std::vector;

int main ()
{
    Vector func;                                //instance of Vector class
    
    vector<int> v = {2, 8, 3, 4, 1};            //declaration of vector named v
    
    func.selection_sort(v);                         //passing vector v as argument into func function
    
    func.print_vector(v);                       //display vector output

    return 0;
}
