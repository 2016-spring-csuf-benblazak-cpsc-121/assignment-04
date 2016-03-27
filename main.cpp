/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Alex Wallingford <alexwallingford@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

 /*
  * A short program to sort the vector list using selection and merge sorts.
 */

#include <iostream>
 #include <vector>

 using std::cout;
 using std::endl;
 using std::vector;

//Prototypes  
 void print_vector(const vector<int> &v);
 void selection_sort(vector<int> &v);
 vector<int> merge(vector<int> left, vector<int> right);
 vector<int> merge_sort(const vector<int> &p);

 int main() {
	 vector<int> v = { 2, 0, -8, -3, 1 };
	 vector<int> merge_sorted;
	
		 cout << "The original list: ";
	 print_vector(v);
	 cout << endl;
	
			//Selection sort  
		 selection_sort(v);
	
			//Merge sort  
		 merge_sorted = merge_sort(v);
	 cout << "Merge sort: ";
	 print_vector(merge_sorted);
	
		 cout << endl;
	 system("pause");
	 return 0;

}

 void print_vector(const vector<int> &v) {
	 vector<int>::const_iterator n;
	 for (n = v.begin(); n != v.end(); n++) {
		 cout << *n << " ";
		
	}
	 cout << endl;
	
}

 void selection_sort(vector<int> &v) {
	 for (int a = 0; a < v.size(); a++) {
		 for (int b = 0; b < a; b++) {
			 if (v[b] > v[b + 1]) {
				 int temp = v[b];
				 v[b] = v[b + 1];
				 v[b + 1] = temp;
				
			}
		
		}
		
	}
	
		  cout << "Selection sort: ";
	 for (int i = 0; i < v.size(); i++) {
		 cout << v[i] << " ";
		
	}
	 cout << endl;
	
}

 vector<int> merge_sort(const vector<int> &p) {
		//base case  
		 if (p.size() <= 1) return p;
	
			//recursive case  
		 else {
		 int half = ((int)p.size() + 1) / 2;
		 vector<int> left, right, sorted;
		 for (int i = 0; i < half; i++) {
			 left.push_back(p[i]);
			
		}
	
			 for (int i = half; i < (int)p.size(); i++) {
			 right.push_back(p[i]);
			
		}
		
			 left = merge_sort(left);
		 right = merge_sort(right);
		 sorted = merge(left, right);
		
			 return sorted;
	
	}
	
}

 vector<int> merge(vector<int> left, vector<int> right) {
	 vector<int> sorted;
	
			//loop until there is no element in the list  
		 while ((int)left.size() > 0 || (int)right.size() > 0) {
		
				//when both lists are more than 2 elements  
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
		
					//when left side has more remainings  
			 else if ((int)left.size() > 0) {
			 for (int i = 0; i < (int)left.size(); i++)
				 sorted.push_back(left[i]);
			 break;
			
		}
				//when right side has more remainings  
			 else if ((int)right.size() > 0) {
			 for (int i = 0; i < (int)right.size(); i++)
				 sorted.push_back(right[i]);
			 break;
			
		}
		
	}
	
		 return sorted;
	
}
