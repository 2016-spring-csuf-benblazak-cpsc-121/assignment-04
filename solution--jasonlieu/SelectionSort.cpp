/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Jason Lieu <jasonlieu@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class SelectionSort
{
private:
	vector<int>a;
	int size;
public:
	SelectionSort(vector<int>v)
	{
		size = v.size();
		for (int f = 0; f < size; f++)
		{
			a.push_back(v[f]);
		}
	}
	void sort()
	{
		for (int i = 0; i < size; i++)
		{
			int pos = i;
			int smallest = a[i];
			for (int n = i; n < size; n++)
			{
				if (smallest > a[n])
				{
					smallest = a[n];
					pos = n;
				}
			}
			if (pos != i) swap(i, pos);
		}
	}
	void swap(int l, int r)
	{
		int temp = a[l];
		a[l] = a[r];
		a[r] = temp;
	}
	void print()
	{
		for (int b = 0; b < size; b++)
		{
			cout << a[b] << " ";
		}
	}
};
int main()
{
	vector<int> v;
	int b;
	char choice;
	bool more = true;
	while (more)
	{
		cout << "Do you want to add a value (Y/y)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			cout << "Enter your next value: ";
			cin >> b;
			v.push_back(b);
		}
		else more = false;
	}
	SelectionSort* a = new SelectionSort(v);
	a->sort();
	a->print();
	system("pause");
	return 0;
};