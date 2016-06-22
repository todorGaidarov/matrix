#ifndef OPERATION_H
#define OPERATION_H
#include "Matrix.h"
#include<math.h>

template<class H>					
class Operation					  // available operations on a matrix
{
public:
	Operation();				  // makes matrix based on user input 
	Operation(int, int);			  // makes matrix by given number of rows and columns 	
	Matrix<H> transpose();                    // gives the transpose matrix
	H determinant(); 			  // gives the determinant			
	H adjugate(int, int);			  // gives the 
	Matrix<H> equation(Operation<H>&);	  // solves equation for sqare matrix
	Matrix<H> inverse();			  // gives the inverse matrix
	void printMatr();			  // print the matrix
	Matrix<H> getMatrix();			  // returns the matrix for some use
	void create();				  
private:
	Matrix<H>  a;                             // the matrix 

};

#endif
