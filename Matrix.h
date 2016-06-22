#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include"complex.h"    // the complex number type

using namespace std;

template<class T> class Matrix;                                // template for the type of the numbers(maybe not neccesary)
template<class T> istream& operator>>(istream&, Matrix<T>&);   // override the cin >> operator	
template<class T> ostream& operator<<(ostream&, Matrix<T>&);   // override the cin >> operator


template<class T>
class Matrix
{
public:
	Matrix();           	// default 2 by 2 matrix
	Matrix(int, int);	// matrix r by c
	Matrix(const Matrix<T>&);	// copy constructor
	Matrix<T> operator+ ( Matrix<T>&);      // sum of matrices
	Matrix<T> operator- ( Matrix<T>&);	// difference
	Matrix<T> operator* ( Matrix<T>&); 	// matrix multiplication - matrix
	friend istream& operator>> <T>(istream&, Matrix<T>&);
	friend ostream& operator<< <T>(ostream&,  Matrix<T>&);	
	Matrix<T> operator* (T);		// matrix multiplication - number
	T operator()(int, int);			// gives the element with the index (i, j)
	Matrix<T>& operator=( Matrix<T>&);	// assignment operator
	//void seElement(int, int);	 // give the element of the matrix 
	int getRows();		 // returns the number of rows
	int getColumns();        // returns the number of columns
	void input(int, int, T);	// gives a certain element some value of type T
	void resizer(int, int);		// changes the matrix by resizing it
	
	
	//~Matrix();
private:
	
	int rows;		      // number of rows
	int columns;		      // number of columns		
	vector<vector<T> > theMatrix; // vector of type vector for the matrix
	

	
};


#endif