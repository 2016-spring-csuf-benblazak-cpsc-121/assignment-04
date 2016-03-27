#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(const vector<int> & t) {
	for (int e : t)
		cout << e << "  \n";
	
}

void selection_sort(vector<int> & t) {
	int temp, min;

	for (int i = 0; i < t.size(); i++) {
		min = i;
		for (int j = 1; j < t.size(); j++) {
			if (t[j] < t[min])
				min = j;
		}
		temp = t[i];
		t[i] = t[min];
		t[min] = temp;
	}
}


vector<int> merge_sort(const vector<int> & t) {
	if (t.size() < 2)
		return t;

	vector<int> left{ t.begin(), t.begin() + t.size() / 2 };
	vector<int> right{ t.begin() + t.size() / 2, t.end() };

	left = merge_sort(left);
	right = merge_sort(right);

	vector<int> sorted;
	vector<int>::iterator l = left.begin();
	vector<int>::iterator r = right.begin();
	while (l != left.end() && r != right.end())
		if (*l < *r)
			sorted.push_back(*(l++));
		else
			sorted.push_back(*(r++));
	while (l != left.end())
		sorted.push_back(*(l++));
	while (r != right.end())
		sorted.push_back(*(r++));

	return sorted;
}

int main() {

	vector<int> num = {38,28,18,48,59,67,10,5,77};

	print_vector(num);
	selection_sort(num);

	print_vector(num);

	
		

	print_vector(num);
	print_vector(merge_sort(num));

	cout << endl;
	




	system("pause");
	return 0;
}
