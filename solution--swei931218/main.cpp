/* ----------------------------------------------------------------------------
* Copyright & copy; 2016 Yi Sui <swei931218@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void selection_sort(vector<int> &);
vector<int> merge(vector<int>&, vector<int>&, vector<int>&);
vector<int> sort(vector<int> );
void print_vector(const vector<int> &);

int main()
{
    
//merge sort
	cout << "Merge sort" << endl<< "unsorted list: ";
	vector<int> elements = { 1,22,7,4,98,3,5 };
	print_vector(elements);
	vector<int> sorted =sort(elements);
	cout <<endl<<"sorted list:   ";
	print_vector(sorted);cout<<endl<<endl;

//selection sort
	cout << "Selection sort" << endl<< "unsorted list: ";
	elements = { 1,22,7,4,98,3,5 };
	print_vector(elements);
	selection_sort(elements);
	cout <<endl<<"sorted list:   ";
	print_vector(elements);	cout << endl;
	return 0;
}

//selection sort
void selection_sort(vector<int> &sel)
{
   for (int i=0;i<(sel.size()-1);i++){
		int temp;int first=0;
		cout<<endl<<"sorting.....";
		for (int n=1;n<=i;n++){
			if (sel[n]>sel[first]){
				first=n;
			}
		}
		temp = sel[first];sel[first] = sel[i];sel[i] = temp;
	}
}


//merge sort
vector<int> merge(vector<int>&v, vector<int>&f, vector<int>&e)
{
	vector<int> sorted;
	unsigned int f_=0,e_=0;
	while (f_<(f.size())&&e_<(e.size())){
		if (f[f_]<e[e_]){
			sorted.push_back(f[f_]);f_++;
		}
		else{
			sorted.push_back(e[e_]);e_++;
		}
	}
	while (e_ < (e.size())){
		sorted.push_back(e[e_]);e_++;
	}
	while (f_ < (f.size())){
		sorted.push_back(f[f_]);f_++;
	}
	v=sorted;
	return v;
}

vector<int> sort(vector<int> v)
{
	if (v.size()==1){
		return v;
	}
	vector<int>::iterator middle=v.begin()+(v.size()/2);
	vector<int> f(v.begin(),middle);
	vector<int> e(middle,v.end());
	f=sort(f);
	e=sort(e);
	
	cout<<endl<<"sorting.....";
	return merge(v,f,e);
}

//print out 
void print_vector(const vector<int> &v)
{
	for (vector<int>::const_iterator i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}
}
