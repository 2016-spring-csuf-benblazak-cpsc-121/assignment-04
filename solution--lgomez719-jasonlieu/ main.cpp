/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Jason Lieu <jasonlieu@csu.fullerton.edu>
* Copyright &copy; 2016 Luisfernando Gomez <lgomez420@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

template<class T>
void multiply( T a, T b)
{
	T c = a * b;
	cout << c;
};
int GCD_iter(int a, int b) //recursion
{
	if (b > a) //swap
	{
		int temp = b;
		b = a; 
		a = temp;
	}
	int r = a%b;
	if (r <= 0) return b;
	else GCD_iter(b, r);
};
int GCD(int a, int b)
{
	if (b > a) //swap
	{
		int temp = b;
		b = a;
		a = temp;
	}
	int r = a%b;
	while (r > 0)
	{
		
		a = b;
		b = r;
		r = a%b;
	}
	return b;
};
int fib_iter(int a)
{
	if (a <= 0) return 0;
	else if (a == 1) return 1;
	else
	{
		return fib_iter(a - 1) + fib_iter(a - 2);
	}
};
int fib(int a)
{
	int b= 0;
	int c = 0;
	int d = 1;
	if (a <= 0) return 0;
	else if (a == 1)return 1;
	for (int i = 0; i <= a; i++)
	{
		if (i <= 1)
			b = c;
		else
		{
			b = c + d;
			c = d;
			d = b;
		}
	}
	return b;
};
int pow(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
	{
		c = c*a;
	}
	return c;
};
int pow_iter(int a, int b)
{
	if (b > 0) return a * pow_iter(a, b - 1);
	return 1;
};
int tri(int a)
{
	int b = 0;
	int c = 0;
	while (b <= a)
	{
		c += b;
		b++;
	}
	return c;
};
int tri_iter(int a)
{
	int b = a;
	if(a>0) return b += tri_iter(a-1);
	return 0;
};
void four(int a)
{
	if (a == 4) throw 1;
	else cout << "good job"<<endl;
};
int main()
{
	

	cout << "Part 1 - exceptions" << endl;
	int c;
	cout << "Don't enter 4 : ";
	cin >> c;
	try 
	{
		four(c);
	}
	catch (int d)
	{
		if (d == 1) cout << "You entered 4, genius" << endl;
	}
	
	cout << endl << endl << "Part 2 - templates" << endl;
	int w;
	int x;
	double y;
	double z;
	cout << "int w : ";
	cin >> w;
	cout << "int x : ";
	cin >> x;
	cout << "double y : ";
	cin >> y;
	cout << "double z : ";
	cin >> z;
	cout << "multiply<int>(w,x) : ";
	multiply<int>(w, x);
	cout << endl;
	cout << "multiply<double>(y,z) : ";
	multiply<double>(y, z);


	cout <<endl<<endl<< "Part 4 + 5 - recursion" << endl;
	int a; int b;
	cout << "a : ";
	cin >> a;
	cout << "b : ";
	cin >> b;
	cout <<"GCD(a,b) : "<< GCD(a, b)<<endl;
	cout <<"GCD_iter(a,b) : "<< GCD_iter(a,b)<<endl;
	cout <<"pow(a,b) : "<< pow(a, b)<<endl;
	cout <<"pow_iter(a,b) : "<< pow_iter(a, b) << endl;
	cout <<"tri(a) : "<< tri(a)<<endl;
	cout <<"tri_iter(a) : "<< tri_iter(a)<<endl;
	cout <<"fib(a) : "<< fib(a) << endl;
	cout <<"fib_iter(a) : "<< fib_iter(a) << endl;

	return 0;
	

	

};
