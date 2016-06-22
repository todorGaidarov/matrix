#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "Matrix.h"


template <class T>
Matrix<T>::Matrix()
{
	rows = 2;
	columns = 2;
	theMatrix.resize(2, vector<T>(2, T()));
	
}

template<class T>
Matrix<T>::Matrix(int r, int c)
{
	resizer(r, c);
	
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	resizer(obj.rows, obj.columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			theMatrix[i][j] = obj.theMatrix[i][j];
		}
	}
}

template<class T>
istream& operator>>(istream& in, Matrix<T>& inMatrix)
{
	cout << "Enter the number of rows\n";
	in >> inMatrix.rows;
	cout << "Enter the number of columns\n";
	in >> inMatrix.columns;
	in.ignore();
	inMatrix.resizer(inMatrix.rows, inMatrix.columns);
	for (int i = 0; i < inMatrix.rows; i++)
	{
		for (int j = 0; j < inMatrix.columns; j++)
		{
			in >> inMatrix.theMatrix[i][j];
		}
	}
	return in;
}

template<class T>
ostream& operator<<(ostream& out,  Matrix<T>& outMatrix)
{
	for (int i = 0; i < outMatrix.rows; i++)
	{
		for (int j = 0; j < outMatrix.columns; j++)
		{
			out << outMatrix.theMatrix[i][j] << "  ";
		}
		out << '\n';
	}
	out << '\n';
	return out;
}

template<class T>
Matrix<T> Matrix<T>::operator+( Matrix<T>& obj2)
{
	Matrix<T> sum;
	if (this->rows != obj2.rows || this->columns != obj2.columns)
	{
		cout << "You can not execute the operation\n";
	}
	else
	{
		sum.resizer(obj2.rows, obj2.columns);
		for (int i = 0; i < obj2.rows; i++)
		{
			for (int j = 0; j < obj2.columns; j++)
			{
				sum.theMatrix[i][j] = this->theMatrix[i][j] + obj2.theMatrix[i][j];
			}
		}
	}
	return sum;
}

template<class T>
Matrix<T> Matrix<T>::operator-( Matrix<T>& obj2)
{
	Matrix<T> sub;
	if (this->rows != obj2.rows || this->columns != obj2.columns)
	{
		cout << "You can not execute the operation\n";
	}
	else
	{
		sub.resizer(obj2.rows, obj2.columns);
		for (int i = 0; i < sub.rows; i++)
		{
			for (int j = 0; j < sub.columns; j++)
			{
				sub.theMatrix[i][j] = this->theMatrix[i][j] - obj2.theMatrix[i][j];
			}
		}
	}
	return sub;
}

template<class T>
Matrix<T> Matrix<T>::operator*( Matrix<T>& obj2)
{
	Matrix<T> prod;
	
	
		prod.resizer(this->rows, obj2.columns);
		for (int i = 0; i < prod.rows; i++)
		{
			for (int j = 0; j < prod.columns; j++)
			{
				prod.theMatrix[i][j] = 0;
				for (int k = 0; k < this->columns; k++)
				{
					prod.theMatrix[i][j] = prod.theMatrix[i][j] + this->theMatrix[i][k] * obj2.theMatrix[k][j];
				}
			}
		}
	
	return prod;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T num)
{
	Matrix<T> newMatr;
	newMatr.resizer(this->rows, this->columns);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			newMatr.theMatrix[i][j] = num * this->theMatrix[i][j];
		}
	}
	return newMatr;
}

template<class T>
T Matrix<T>::operator()(int i, int j)
{
	return theMatrix[i][j];
}

template<class T>
void Matrix<T>::resizer(int m, int n)
{
	
	theMatrix.resize(m);
	for (int i = 0; i < m; i++)
	{
		theMatrix[i].resize(n);
	}
	rows = m;
	columns = n;
}

template<class T>
Matrix<T>& Matrix<T>::operator=( Matrix<T>& obj)
{
	
	resizer(obj.rows, obj.columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			theMatrix[i][j] = obj.theMatrix[i][j];
		}
	}
	return *this;
}

template<class T>
int Matrix<T>::getRows()
{
	return rows;
}

template<class T>
int Matrix<T>::getColumns()
{
	return columns;
}

template<class T>
void Matrix<T>::input(int row, int column, T in)
{
	theMatrix[row][column] = in;
}


#endif