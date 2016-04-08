/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alexandria Wolfram & Dylan Connors <aleewolfram@gmail.com>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* A program containing selection sort and merge sort and print vector. :)
*/




#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


void print_vector(const std::vector<int> & c)
{
	for (size_t a = 0; a < c.size(); a++)
		cout << c[a] << " ";
  cout << endl;
}


//Selection Sort 
std::vector<int> selection_sort(std::vector <int> & pancakes )
{

	int first;
	int temp;
	
	int numPancakes = pancakes.size();
	for (int i = pancakes.size() - 1; i > 0; i--)
	{
		first = 0;                  
		for (int j = 1; j <= i; j++)    
		{
			if (pancakes[j] < pancakes[first])
				first = j;
		}
		temp = pancakes[first];   
		pancakes[first] = pancakes[i];
		pancakes[i] = temp;
	}

	return pancakes;
}

//Merge Sort

std::vector<int> merge(std::vector<int> vanilla, std::vector<int> chocolate) {
	
			
		std::vector<int> sorted;
	
		
		while (vanilla.size() != 0 && chocolate.size() != 0) 
		{

			if (vanilla[0] < chocolate[0])
			{
				sorted.push_back(vanilla[0]);
				vanilla.erase(vanilla.begin());
			}
			else
			{
				sorted.push_back(chocolate[0]);
				chocolate.erase(chocolate.begin());
			}
		}
	
		
		
	if (vanilla.size() != 0)
	{
		for (int i : vanilla)
		sorted.push_back(i);
	}
	
		if (chocolate.size() != 0)
		{
		for (int i : chocolate)
			 sorted.push_back(i);
		}
		return sorted;
}

std::vector<int> merge_sort(std::vector<int> & pop)
{
	

		if (pop.size() == 1) return pop;

		int half_size = pop.size() / 2;
		
		std::vector<int> little(pop.begin(), pop.begin() + half_size);
		std::vector<int> big(pop.begin() + half_size, pop.end());
		return merge(merge_sort(little), merge_sort(big));
	
}

int main()
{

	int bubbles;
	std::vector<int> cook = { 4, 6, 0, 2 };
	std::vector<int> baker = { 1, 9, 4, 5 };
	
		merge_sort(cook);
	print_vector(cook);
	print_vector(selection_sort(cook));
	print_vector(merge_sort(baker));
	print_vector(selection_sort(baker));

	cin >> bubbles;

	
}
