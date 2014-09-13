/* \file class1.cpp
 * \author Gustavo Peixoto de Oliveira
 */

#include <iostream>


/*	UDTs (user-defined types) provided by C++: 
 *	i) classes; ii) enumerations: 
 *
 * 	class: interface + implementation;  
 */
using namespace std;


// struct is a class where members are public by default; simplified
// version

struct Y {
 	int a1;
};

class X {

  	int h;
	int hf(int);
  public:
 	int m;
	int mf(int v)
	{ 
		int old = m;
		m = v;
		return old;
	}
	int f(int i){ h = i; return hf(i); }
};


int main(int argc, char* argv[])
{
	X var; 
	int b1 = var.m = 7;
	cout << b1;

	int x = var.mf(9);
	cout << x;

	Y ct;
	int h1 = ct.a1 = 3;
}

