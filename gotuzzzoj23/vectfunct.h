//
//  vectfunct.hpp
//  assi4
//
//  Created by Jose Gotuzzo, Robert Gonzalez, Griffin Yee  on 3/25/16.
//  Copyright © 2016 Jose Gotuzzo. All rights reserved.
//

#ifndef vectfunct_h
#define vectfunct_h
#include <stdio.h>
using std:: cout;
using std::vector;


void print_vector( const vector <int> & v); //prints out vector

void selection_sort( vector <int> & v); //organizes vector using selection sort

vector <int> merge_sort( const vector <int> &); //devides the vector into length of 1 to organize

vector <int> merge (vector <int> &, vector <int> &); /* merges the divided vectors into one new
                                                        organized vector */


#endif /* vectfunct_h */
