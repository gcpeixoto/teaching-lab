/* \file   basicOperators.cpp
 * \author Gustavo Peixoto de Oliveira
 * \date   March, 2013
 */

#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

/* \brief Convert integer to string */
string Int2Str(int number)
{
	stringstream ss; // creates string buffer containing a sequence of characters to be accessed by 						the member str() 
	ss << number; // adds number to the stream
	return ss.str(); // returns a string with the content of the stream 
}

int main(int argc, char *argv[])
{
	int c;
	cout << "Enter an integer:" << endl;
	cin >> c;

	cout << "c++" << c++ << endl;
	cout << "c--" << c-- << endl;
	cout << "++c" << ++c << endl;
	cout << "--c" << --c << endl;

	int aux = c;
	
	string str;
	cout << "Choose a letter to represent your integer:"<< endl;
	cin >> str;
	getline(cin,str);

	string str2 = Int2Str(c++);

	//printf("%s++ \t %s \n",str,str2);

	FILE * PtrFile;
	
	PtrFile = fopen("BasicOperators.dat","w");

	fprintf(PtrFile, "%s","Here is a small list of how some C++ operators affect your integer 'c':\n");
	fprintf (PtrFile,"Operator %s \t %i \n","c++",c++);
	aux = c--;
	fprintf (PtrFile,"Operator %s \t %i \n","c--",aux);
	aux = ++c;
	fprintf (PtrFile,"Operator %s \t %i \n","++c",aux);
	aux = --c;
	fprintf (PtrFile,"Operator %s \t %i \n","--c",aux);

	fclose (PtrFile);

}


