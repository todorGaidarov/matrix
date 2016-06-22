#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>

using namespace std;

class complex  // definition of the complex number type
{
public:
	complex(double = 0, double = 0);
	friend ostream& operator<<(ostream&, complex&);  // input of compl numbers
	friend istream& operator>>(istream&, complex&);	 // output of compl numbers
	friend complex operator+(complex&, complex&);	 // sum of compl numbers
	friend complex operator-(complex&, complex&);	 // difference
	friend complex operator*(complex&, complex&);	 // multiplication - two compl numbers
	friend complex operator/(complex&, complex&);	 // division
	bool operator!=(complex&);			 // not equal
	complex operator*(double);			 // multiplication - real number
	double getReal();				 // gets the real part 
	double getImg();				 // gets the imaginary part
	~complex();
private:
	double real;	//  the real part
	double img;	//  the imaginary part
};

#endif