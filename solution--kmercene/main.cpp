//Katelyn Mercene
//Project 4 
/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Katelyn Mercene <kmercene@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
//This program is designed to show an example of a vector sorted by selection sort and merge sort.
//referenced from stackoverflow and wikipedia
#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout; 
using std::vector;

void selection_sort(std::vector<int> &);
void merge_sort(const std::vector<int> &);
void mergeSort(vector<int> left, vector<int> right);
std::vector<int> v;

int main(){
	vector<int> v = { -1, 0, 5, 2, 4};
	/*cout << "This is the unchanged vector: ";			//Not really sure how to display this
	cout << vector.at(v);*/

	selection_sort(v);

	cout << "Merge sort of vector: ";
	merge_sort(v);

	return 0;
}
void selection_sort(std::vector<int> & v){				//I tried but this part confused me
	int size, *first, temp;
	for (int i = size - 1; i > 0; --i){
		first = 0;
		for (int j = 1; j <= i; ++j){
			if (v[j] > v[first]){
				*first = j;
			}
			temp = v[first];
			v[first] = v[i];
			v[i] = temp;
		}
	}
}
std::vector <int> const half_size = vector.size() / 2;

void merge_sort(const std::vector<int> & v){

	if(v.size() = 1)
		return v;
	else 
		resize(half_size);
}
/*vector<int> mergeSort(vector<int> left, vector<int> right){

}*/
