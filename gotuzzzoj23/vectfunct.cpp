//
//  vectfunct.cpp
//  assi4
//
//  Created by Jose Gotuzzo, Robert Gonzalez, Griffin Yee  on 3/25/16.
//  Copyright © 2016 Jose Gotuzzo. All rights reserved.
//

#include <iostream>
#include <vector>
#include "vectfunct.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;


void print_vector( const vector <int> & v){
   
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl;
}

void selection_sort( vector <int> & v){
    
    int current, least;
    for (int j = 0; j < v.size()-1; j++){
        least = j;
        for (int i = j+1; i < v.size(); i++){
            if ( v[i] < v[least])
                least= i;
        }
        if ( least != j){
            current = v[j] ;
            v[j] = v[least];
            v[least] = current;
        }
    }
}

vector <int> merge_sort( const vector <int>& v){
    
    vector <int> left, right, sorted;
    
    if (v.size()==1)
        return v;
    
    int middle = ((int)v.size() + 1) / 2;
    
    for (int i = 0; i < middle; i++)
        left.push_back(v[i]);
    
    for (int i =middle; i < v.size(); i++)
        right.push_back(v[i]);
    
    left = merge_sort(left);
    right = merge_sort(right);
    sorted = merge(left, right);
    
    return sorted;
}

vector <int> merge (vector <int>& left, vector <int>& right){
    
    vector <int> sorted;
    
    while (left.size() > 0 || right.size() > 0){
        if (left.size() > 0 && right.size() > 0){
            if (left.front() <= right.front()){
                sorted.push_back(left.front());
                left.erase(left.begin());
            }
            else{
                sorted.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0){
            for (int i = 0 ; i < left.size(); i++)
                sorted.push_back(left[i]);
            break;
        }
        else if (right.size() > 0){
            for (int i = 0; i < right.size(); i++)
                sorted.push_back(right[i]);
            break;
        }
    }
    return sorted;
}
