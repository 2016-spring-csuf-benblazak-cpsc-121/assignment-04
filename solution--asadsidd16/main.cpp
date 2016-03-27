//
//  main.cpp
//  Assignment 4
//
//  Created by asad siddiqui on 3/26/16.
//  Copyright © 2016 asad siddiqui. All rights reserved.
//

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;


    void selection_sort(std::vector<int> &n);

    int main() {
    
    std::vector <int> loop {8, 9, 4, 2, 1, 6};
    selection_sort(loop);
    
    
   
    return 0;
}
void print_vector(const std::vector<int> & m){
    for(int i = 0; i < m.size(); i++){
        cout << m[i] << " ";
        
    }
    cout << endl;
        }

std::vector<int> merge_sort( std::vector<int> & var ){
    
    std::vector<int> left;
    std::vector<int> right;
    std::vector<int> sorted;
    
        //base case
        //if vector has 1 element, return the vector
        if( var.size() == 1 )
               return var;
       else{
                    
                    int half = ( int ) var.size() / 2;
            
                    
                    for( int l = 0; l < half; l++ ){
                                left.push_back( var[l] );
                            }
            
                  
                    for( int r = half; r < var.size(); r++ ){
                                right.push_back( var[r] );
                            }
               
                    left = merge_sort( left );
                    right = merge_sort( right );
                    sorted = merge_sort( left, right );
                }
        return sorted;
    
    void selection_sort(std::vector<int> & n){
    int small, s_index;
    for(int i = 0; i < n.size(); i++){
        small = n[i];
        s_index = i;
        
        for(int j = 1 + i; j <n.size(); j++){
            if(small > n[j]){
                small = n[j];
                s_index = j;
                
            }
        }
        n[s_index] = n[i];
        n[i] = small;
        
        
    }
    print_vector(n);
}
