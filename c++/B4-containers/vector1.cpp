/* \file   vector1.cpp
 * \author Gustavo Peixoto de Oliveira
 */

#include <iostream>
#include <vector>

using namespace std;


double* calc(int res_size,int max) // leaks memory
{
	double* p = new double[max];
	double* res = new double[res_size];
	// use p to calculate results to be put in res
	delete[] p; // we don't need that memory anymore; free it
	return res;

}

// very simplified vector of doubles (like vector<double>)
class vecteur 
{
	int sz; // the size
	double *elem; // pointer to the first element of the vector (type double)

 public:
	vecteur(int s) // constructor: allocate s doubles
				   // let elem point to them
				   // stores s in sz
			:sz(s), // initialize sz
			elem(new double[s])
			{
			 	for (int i = 0; i < s; ++i) elem[i] = 0; // initialize elements
			}

	int size() const { return sz; } // the current size
};

int main(int argc, char *argv[])
{
	vector<double> age(4); // vector with 4 elements of type double

	// numbering from 0 is a universal convention in C++ STL
	
	// filling vector age
	age[0] = 0.33;
	age[1] = 22.0;
	age[2] = 27.2;
	age[3] = 54.2;

	cout << "size of vector = " << age.size() << endl; // size of vector. Elements numbered from 0 to size() - 1.


	int var = 14;

	int *ptr = &var; // ptr holds the address

	cout << "address of var by using & \t" << &var << endl; 
	cout << "address of var by using ptr \t" << ptr << endl; 
    
	char c = 'c';
	char *pc = &c;

	cout << "pointer to char pc \t" << pc << "; \ncontents of pc \t" << *pc << "\n";

	// dereference operator * used in the l.h.s.
	
	*pc = 'x'; // OK. the char pointed by pc now is 'x'
	*ptr = *pc; // OK. assigns a char (pc) to an int (ptr)

	cout << "*ptr \t" << *ptr << "\n *pc \t" <<*pc << endl;
	

	// Operator sizeof() answers how much memory a variable uses.
	
	cout << "the size of a char is: " << sizeof(char) << "bytes" << endl;
	cout << "the size of char c is: " << sizeof(c) << "bytes" << endl;

	cout << "the size of an int is: " << sizeof(int) << "bytes" << endl;
	cout << "the size of 2+2 is: " << sizeof(2+2) << "bytes" << endl;
	cout << "the size of an int* is: " << sizeof(int*) << "bytes" << endl;


	cout << "the size of a double is: " << sizeof(double) << "bytes" << endl;
	cout << "the size of a double* is: " << sizeof(double*) << "bytes" << endl;

	cout << "the size of a bool is: " << sizeof(bool) << "bytes" << endl;
	cout << "the size of a bool* is: " << sizeof(bool*) << "bytes" << endl;

	cout << "the size of a string is: " << sizeof(string) << "bytes" << endl;
	cout << "the size of a string* is: " << sizeof(string*) << "bytes" << endl;
	
	vector<int> v1(10);
	vector<int> v2(100);
	vector<int> v3(1000);
	vector<int> v4(10000);
	vector<int> v5(100000);

	cout << "the size of vector<int> v1(10) is: " << sizeof(v1) << "bytes" << endl;
	cout << "the size of vector<int> v2(100) is: " << sizeof(v2) << "bytes" << endl;
	cout << "the size of vector<int> v3(1000) is: " << sizeof(v3) << "bytes" << endl;
	cout << "the size of vector<int> v4(10000) is: " << sizeof(v4) << "bytes" << endl;
	cout << "the size of vector<int> v5(100000) is: " << sizeof(v5) << "bytes" << endl;

	vector<double> v11(10);
	vector<double> v22(100);
	vector<double> v33(1000);
	vector<double> v44(10000);
	vector<double> v55(100000);

	cout << "the size of vector<double> v11(10) is: " << sizeof(v11) << "bytes" << endl;
	cout << "the size of vector<double> v22(100) is: " << sizeof(v22) << "bytes" << endl;
	cout << "the size of vector<double> v33(1000) is: " << sizeof(v33) << "bytes" << endl;
	cout << "the size of vector<double> v44(10000) is: " << sizeof(v44) << "bytes" << endl;
	cout << "the size of vector<double> v55(100000) is: " << sizeof(v55) << "bytes" << endl;

	
	// Introducing dynamic allocation with 'new'. This operator makes
	// the "free store" (heap) available in run-time.
	
	double *p = new double[4]; // allocates 4 doubles on the free store and returns a pointer to the first double

	cout << p[0] << p[1] << p[2] << p[3] << endl; // value of the pointer is the address of the first byte of the memory and it doesn't know how many elements it points to.

	// new allocates individually or by arrays 
	int *pInt = new int; 
	int *pInt2 = new int[4];
	
	int n = 10; // number of objects allocated can be variable
	double *pD = new double;
	double *pD2 = new double[n];

	// Note: "[]" is the "subscript operator" 
	double y = *pD2; // first object pointed by pD2 and the same as pD2[0]
	double x = pD2[2]; // third object pointed by pD2

	pD2[-3] = 3.13;

	double z = pD2[-3]; // three addresses less than that pointed by the pointer.
	
	cout << z << endl;

	cout << &pD2[-3] << endl; // If pD2 points to the first byte, who is pD2[-3]?

	cout << x << y << endl;

	*pD2 = 1.1;
	pD2[1] = 1.2;

	y = *pD2;
	cout << y << endl;
	

	// Null pointer. Use 0 when we don't have another pointer to
	// initialize.
	
	double *pp = 0; // null pointer
	
	double* r = calc(100,1000); // function defined in the beginning
	// calc(100,1000) will render the space needed for 100 doubles
	// unusable for the rest of the program
	// "delete" frees the memory used by new.
	
	delete[] r;

	// "delete p" frees the memory individually
	// "delete[] p" for an array

	
}




