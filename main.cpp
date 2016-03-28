/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Vector mian 
*/
#include "vector.h"

int main()
{
	vector<int> KoolKid;
	int input = 0;
	bool choice = false;
	std::cout << "Give numbers for your vectors: " << std::endl;
	for (;;)
	{
		std::cin >> input;
		KoolKid.push_back(input);
		std::cout << "Keep adding more?(1 for Yes or 0 for No): ";
		std::cin >> choice;
		if (choice == false)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	
	merge_sort(KoolKid);
	print_vector(merge_sort(KoolKid));
	system("pause");

}
