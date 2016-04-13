/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alan Reeve <areeve@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

// function definitions

#include "functions.h"
#include <iostream>

using std::cout;

void print_vector(const std::vector<int> &vect){

	for (int i : vect)
		cout << i << " ";

	cout << "\n";
}

void selection_sort(std::vector<int> &vect){

	for (std::vector<int>::iterator currentIndex = vect.begin();
			currentIndex < vect.end(); currentIndex++){

		std::vector<int>::iterator minIndex = currentIndex;

		// find the index of the minimum
		for(std::vector<int>::iterator compareIndex = currentIndex;
				compareIndex < vect.end(); compareIndex++){

			if(*minIndex > *compareIndex)
				minIndex = compareIndex;
		}

		// swap element at current with element at min
		int temp = *currentIndex;
		*currentIndex = *minIndex;
		*minIndex = temp;
	}
}

std::vector<int> merge_sort(const std::vector<int> &v){
    
    std::vector<int> vect = v;
	std::vector<int> left, right;
	std::vector<int> sorted;
	// base case
	if (vect.size() == 1){
		return vect;
	}


	// split into two vectors
	for(int i = 0; i < vect.size(); i++){
		if( i < vect.size()/2)
			left.push_back(vect[i]);
		else
			right.push_back(vect[i]);
	}	

	// recursively merge sort both sides
	left = merge_sort(left);
	right = merge_sort(right);

    while (left.size() > 0 && right.size() > 0){
		
		std::vector<int>::iterator minLeft = left.begin();
		std::vector<int>::iterator minRight = right.begin();

		for(std::vector<int>::iterator index = left.begin(); 
			index < left.end(); index++){
			if(*minLeft > *index)
				minLeft = index;
		}
		for(std::vector<int>::iterator index = right.begin();
			index < right.end(); index++){
			if(*minRight > *index)
				minRight = index;
		}

		if(*minLeft < *minRight){
			sorted.push_back(*minLeft);
			left.erase(minLeft);
		}
		else{
			sorted.push_back(*minRight);
			right.erase(minRight);
		}
	}
    
    while (left.size() > 0 || right.size() > 0){
        if(left.size() > 0){
            sorted.push_back(left[0]);
            left.erase(left.begin());
        }
        else if(right.size() > 0){
            sorted.push_back(right[0]);
            right.erase(right.begin());
        }
    }


	return sorted;

}