#include "Operation.h"


template<class H>
Operation<H>::Operation()
{
	cin >> a;
}

template<class H>
Operation<H>::Operation(int row, int col)
{
	a = Matrix<H>(row, col);
}

template<class H>
void Operation<H>::printMatr()
{
	cout << a;
}

template<class H>
Matrix<H> Operation<H>::transpose()
{
	Matrix<H> trans(a.getColumns(), a.getRows());
	for (int i = 0; i < a.getRows(); i++)
	{
		for (int j = 0; j < a.getColumns(); j++)
		{
			trans.input(j, i, a(i , j ));
		}
	}
	return trans;
}

template<class H>
H Operation<H>::determinant()
{
	H det = H(0);
	int n = a.getColumns();
	Operation<H> tmp(n-1 , n-1 );
	if (n == 1)
		return a(0, 0);
	else if (n == 2)
		return a(0, 0) * a(1, 1) - a(0, 1) * a(1, 0);
	else
	{
		
		for (int i = 0; i < n; i++)
		{
			int row = 0, col = 0;
			for (int r = 1; r < n; r++)
			{
				for (int c = 0; c < n; c++)
				{
					if (c == i)
					{
						continue;
					}
					tmp.a.input(row, col, a(r, c));
					++col;
				}
				++row;
				col = 0;
			}
			det = det + a(0, i) * pow(-1, i) * tmp.determinant();
		}
	}
	return det;
}

template<class H>
H Operation<H>::adjugate(int i, int j)
{
	
	int n = a.getColumns();
	Operation<H> t(n - 1, n - 1);
	H adj;
	int row = 0, col = 0;
	for (int k = 0; k < n ; k++)
	{
		for (int l = 0; l < n ; l++)
		{
			if (k == i) break;
			if (l == j) continue;
			t.a.input(row, col, a(k, l));
			++col;
			if (col == n - 1)
			{
				++row;
				col = 0;
			}
		}
		
	}
	adj = t.determinant() * pow(-1, i + j);
	return adj;
}

template<class H>
Matrix<H> Operation<H>::inverse()
{
	
	int n = a.getRows();
	int count = 0;
	Matrix<H> tmp(n, n);
	
	if (this->determinant() != H(0))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp.input(i, j, this->adjugate(j, i));
			}
		}
		tmp = tmp * (H(1) / this->determinant());
		
	}
	else
	{
		 tmp.resizer(0, 0);
	}
	return tmp;
		
}

template<class H> 
Matrix<H> Operation<H>::equation(Operation<H>& obj)
{
	Matrix<H> m_X;
	m_X = this->inverse() * obj.a;
	return m_X;

}

template<class H>
Matrix<H> Operation<H>::getMatrix()
{
	return a;
}

template<class H>
void Operation<H>::create()
{
	cin >> a;
}