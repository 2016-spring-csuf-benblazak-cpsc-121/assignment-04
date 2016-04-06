//header
/*#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;*/

#include "header.h"

void print_vector(const vector<int> &v)
{
	unsigned long n = v.size();  
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
vector<int> merge_sort(const vector<int> &v)
{
	if (v.size() == 1) return v;
	
	// if elements are greather than 1 than split the list in half

	
	unsigned long mid = v.size() / 2;
	vector<int> right(v.begin() + mid, v.end());   //create the right
	vector<int> left(v.begin(), v.begin() + mid); //create the left
	
	right = merge_sort(right); //recursively merge sort the right half
	left = merge_sort(left); //recursively merge sort the right half
	

	//for the first element of each list
	vector<int>::iterator v_left = left.begin(); 
	vector<int>::iterator v_right = right.begin();

	vector<int> sorted; //create a new empty list called sorted
	
	//merge the sorted left and right halves together

	//while both lists are non-empty
	while (v_left != left.end() && v_right != right.end())
	{
		if (*v_left < *v_right) //compare the first element of each list
		{
			sorted.push_back(*v_left);//take the smaller element out of the list it is in, and put in sorted
			v_left++;
		}
		else
		{
			sorted.push_back(*v_right);
			v_right++;
		}
	}

	//take the remaining elements from the nonempty list, and place them in order at the end of sorted
	while (v_left != left.end())
	{
		sorted.push_back(*v_left); 
		v_left++;
	}

	while (v_right != right.end())
	{
		sorted.push_back(*v_right);
		v_right++;
	}
	return sorted; // return sorted
}



int main(int argc, const char * argv[]) {
		vector<int> v = { 8,2,3,4,5,6,7,1 };
		vector<int> receiver = merge_sort(v); 
		print_vector(receiver);

		system("pause");
		return 0;

}

