/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Jason Lieu <jasonlieu@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

class MergeSort
{
private:
	vector<int>a;
	vector<int>temp;
	int size;
public:
	MergeSort(vector<int>v)
	{
		size = v.size();
		for (int f = 0; f < size; f++)
		{
			a.push_back(v[f]);
			temp.push_back(v[f]);
		}
	}
	void mergeSort()
	{
		mergeSort(0, size - 1);
	}
	void printa()
	{
		print(a);
	}
private:
	void mergeSort(int left, int right)
	{
		if (left == right) return;

		int middle = (left + right) / 2;
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, right);
	}
	void merge(int left, int right)
	{
		int middle = (left + right) / 2;
		int i = left;
		int j = middle + 1;
		int k = left;
		while ((i <= middle) && (j <= right))
		{
			if (a[i] < a[j]) temp[k++] = a[i++];
			else temp[k++] = a[j++];
		}
		while (i <= middle) temp[k++] = a[i++];
		while (j <= right) temp[k++] = a[j++];
		for (int index = left; index <= right; index++)
		{
			a[index] = temp[index];
		}
	}
	void print(vector<int>a)
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
	string choice;
	bool more = true;
	while (more)
	{
		cout << "Do you want to add a value" << endl;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Enter your next value: ";
			cin >> b;
			v.push_back(b);
		}
		else more = false;
	}
	MergeSort* c = new MergeSort(v);
	c->mergeSort();
	c->printa();
	system("pause");
	return 0;
}

