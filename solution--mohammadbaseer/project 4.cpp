/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* -------------------------------------------------------------------------
Project 4
Mohammad Baseer
Moises Leon
*/


#include<iostream>
#include<vector>
typedef std::vector<int>::iterator vec_it;
using std::cout;
using std::cin;
using std::endl; 
using std::vector;




//This function simply prints out the vectors  
void printVector(const std::vector<int> &myVector)
{
	for (int i = 0; i <= myVector.size(); i++)
	{
		cout << "These are the sample numbers" << " " << myVector[i] << " ";
	}

	cout << endl;
}


//This is the selection sort function
template<int SampleVector>
void selectionSort(vector<sampleVector>, & sorting)
{
	int place, min, j;
	for (place = 0; place < 10; ++place)
	{
		min = sorting[place];

		for (j = sorting[place + 1]; i<sorting[10]; ++j])
		{
			if (j < min)
			{
				min = j;
			}

		}

		if (min != place)
		{
			std::swap(sorting.at(min), sorting.at(place));
		}

	}
}


//This function uses merge sort
void merge(vec_it left, vec_it leftmost, vec_it right, vec_it rightmost, vec_it sampleNumbers)
{
	while (left != leftmost) {
		if (*left < *right || right == rightmost) {
			*sampleNumbers = *left;
			++left;
		}
		else {
			*sampleNumbers = *right;
			++right;
		}

		++sampleNumbers;
	}

	while (right != rightmost) {
		*sampleNumbers = *right;
		++right;
		++sampleNumbers;
	}
}

void merge_sort(std::vector<int>& numbers)
{
	if (numbers.size() <= 1) {
		return;
	}

	std::vector<int>::size_type middle = numbers.size() / 2;
	std::vector<int> left(numbers.begin(), numbers.begin() + middle);
	std::vector<int> right(numbers.begin() + middle, numbers.end());

	merge_sort(left);
	merge_sort(right);

	merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin());
}
	

int main(int argc, const char * argv[])
{
	    
		
	// This part defines the numbers in the vector
	vector<v>;
	
	v.push_back(16)
	v.push_back(271)
	v.push_back(77)
	v.push_back(40)
	v.push_back(120)
	v.push_back(75)
	v.push_back(240)

	
	
		



		 printVector(vector);
		// This displays the vectors before sort to the user
		for (int i = 0; i<7; i++) 
		{
			std::cout << v[i] << " " << endl;
		}

		
		
	 selectionSort(int);
		//selectionSort(sortingVector);
		vector<int> sortingVector;
		std::cin.get();
		std::cout << "After sort \n";
		for (int i = 0; i<7; i++)
		{
			cout << sortingVector[i] << "\n";
		}
		//This is after the sort

		
	   merge(vec);
		 mergeSort(sortedVec);
		

		//This is after the merge sort function
		std::cout << v1[i] << " ";
		std::cout << endl;
		std::cout << "All tests passed.";
		system("PAUSE");
		return 0;
}
