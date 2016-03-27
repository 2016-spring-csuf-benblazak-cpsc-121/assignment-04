/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/*
 * cpp file where the function definitions are written
 */

#include <iostream>
using std::cout;
#include <vector>

#include "vector.h"

using std::cout;
using std::endl;

void Vector::print_vector(const vector<int> &v)                //print_vector function
{
    for (int i = 0; i < v.size(); i++)                         //print out vector content
    {
        cout << v[i] << " ";
    }
}

void Vector::selection_sort(vector<int> &v)                    //selection_sort function
{
    int tempMin, tempNum;
    
    for (int i = 0; i < v.size(); i++)                         //select current index
    {
        tempMin = v[i];
        
        for (int j = (i + 1); j < v.size(); j++)
        {
            if (v[i] > v[j])                                   //swap current index with minimum
            {
                tempNum = v[i];
                v[i] = v[j];
                v[j] = tempNum;
            }
        }
    }
}

vector<int> Vector::merge_sort(const vector<int> &v)           //merge_sort function
{
    vector<int> left, right, sorted;
    
    if (v.size() == 1) return v;                               //base case
    
    int center = (static_cast<int>(v.size()) + 1) / 2;         //center of vector

    for (int i = 0; i < center; i++)                           //fill left vector
        left.push_back(v[i]);
    
    for (unsigned long i = v.size(); i > (v.size() - center); i--)   //fill right vector
        right.push_back(v[i]);
    
    merge_sort(left);
    merge_sort(right);
    
    merge(left, right, sorted);                                //call merge function
    
    return sorted;
}

vector<int> Vector::merge(vector<int> left, vector<int >right, vector<int> & sorted)   //merge function
{
    while (sorted.size() < left.size() && sorted.size() < right.size())
    {
        int i = 0;
        
        if (left[i] < right[i])                                //merge left and right together
        {
            sorted.push_back(left[i]);
            i++;
        }
        else
        {
            sorted.push_back(right[i]);
            i++;
        }
    }
    
    return sorted;
}

