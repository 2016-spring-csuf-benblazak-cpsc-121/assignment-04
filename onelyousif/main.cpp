#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

void print_vector(const vector<int> &v);
void selection_sort(vector<int> &v);
vector<int> merge(vector<int> left, vector<int> right);
vector<int> merge_sort(const vector<int> &p);

int main() {
	vector<int> v = { 3 , 2, 5, -5, -1 };
	vector<int> merge_sorted;

	cout << "The OG list: ";
	print_vector(v);
	cout << endl;

	selection_sort(v);

	merge_sorted = merge_sort(v);
	cout << "Merge sort: ";
	print_vector(merge_sorted);

	cout << endl;
	system("pause");
	return 0;
}

void print_vector(const vector<int> &v) {
	vector<int>::const_iterator r;
	for (r = v.begin(); r != v.end(); r++) {
		cout << *r << " ";
	}
	cout << endl;
}

void selection_sort(vector<int> &v) {
	for (int z = 0; z < v.size(); z++){
		for (int b = 0; b < z; b++){
			if (v[b] > v[b + 1]){
				int temp = v[b];
				v[b] = v[b + 1];
				v[b + 1] = temp;
			}
		}
	}
	
   cout << "Selection sort: ";
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> merge_sort(const vector<int> &k) {
	
	if (k.size() <= 1) return k;

	else {
		int half = ((int)k.size() + 1) / 2;
		vector<int> left, right, sorted;
		for (int i = 0; i < half; i++) {
			left.push_back(k[i]);
		}

		for (int i = half; i < (int)k.size(); i++) {
			right.push_back(k[i]);
		}

		left = merge_sort(left);
		right = merge_sort(right);
		sorted = merge(left, right);

		return sorted;
	}
}

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> sorted;

	while ((int)left.size() > 0 || (int)right.size() > 0) {

		if ((int)left.size() > 0 && (int)right.size() > 0) {
			if ((int)left.front() <= (int)right.front()) {
				sorted.push_back((int)left.front());
				left.erase(left.begin());
			}
			else {
				sorted.push_back((int)right.front());
				right.erase(right.begin());
			}
		}

		else if ((int)left.size() > 0) {
			for (int i = 0; i < (int)left.size(); i++)
				sorted.push_back(left[i]);
			break;
		}

		else if ((int)right.size() > 0) {
			for (int i = 0; i < (int)right.size(); i++)
				sorted.push_back(right[i]);
			break;
		}
	}

	return sorted;
}
