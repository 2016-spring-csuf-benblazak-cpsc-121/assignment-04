#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;



void print_vector(vector <int> nums, int n)
{

	for (int i = 1; i <= n - 1; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;


}


void selection_sort(vector <int> & nums)
{
	int n = 0;
	for (int j = 1; j< n - 1; j++)
	{
		for (int o = 1; o <= n - 1; o++)
		{
			if (nums[j] < nums[o])
			{
				int now = nums[j];
				nums[j] = nums[o];
				nums[o] = nums[j]; 
				cout << nums[j];
			}
		}
	}


}

int main()
{

	vector <int> nums = { 1,8,6,9,7,5,3,2,4 };

	selection_sort(nums);
	

	for (int i = 1; i <= 10; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;




	system("pause");
	return 0;
}
