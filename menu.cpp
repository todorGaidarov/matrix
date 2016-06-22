#include<fstream>
#include "Operation.h"
#include<string>



// some basic UI 

template<class M>
void Multi()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Matrix<M> product;
	Matrix<M> m_A;
	Matrix<M> m_B;

	cout << "Enter the first matri\n";
	cin >> m_A;
	cout << "Enter the second matrix\n";
	cin >> m_B;
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	while (m_A.getColumns() != m_B.getRows())
	{
		cout << "Incorrect input.\n";
		cout << "Enter the first matri\n";
		cin >> m_A;
		cout << "Enter the second matrix\n";
		cin >> m_B;
	}
	newMemory << "Multiplication\n__________________________\n";
	newMemory << "A\n" << m_A << '\n';
	newMemory << "B\n" << m_B << '\n';
	product = m_A * m_B;
	newMemory << "_________________________\nResult\n" << product;
	newMemory.close();
	
	cout << product;
}

template<class M>
void Addition()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Matrix<M> sum;
	Matrix<M> m_A;
	Matrix<M> m_B;
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	cout << "Enter the first matri\n";
	cin >> m_A;
	cout << "Enter the second matrix\n";
	cin >> m_B;
	while (m_A.getRows() != m_B.getRows() || m_A.getColumns() != m_B.getColumns())
	{
		cout << "Incorrect input.\n";
		cout << "Enter the first matri\n";
		cin >> m_A;
		cout << "Enter the second matrix\n";
		cin >> m_B;
	}
	newMemory << "Addition\n__________________________\n";
	newMemory << "A\n" << m_A << '\n';
	newMemory << "B\n" << m_B << '\n';
	sum = m_A + m_B;
	newMemory << "_________________________\nResult\n" << sum;
	newMemory.close();

	
	cout << sum;
}

template<class M>
void Subtraction()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Matrix<M> sub;
	Matrix<M> m_A;
	Matrix<M> m_B;
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	cout << "Enter the first matri\n";
	cin >> m_A;
	cout << "Enter the second matrix\n";
	cin >> m_B;
	
	while (m_A.getRows() != m_B.getRows() || m_A.getColumns() != m_B.getColumns())
	{
		cout << "Incorrect input.\n";
		cout << "Enter the first matri\n";
		cin >> m_A;
		cout << "Enter the second matrix\n";
		cin >> m_B;
	}

	newMemory << "Subtraction\n__________________________\n";
	newMemory << "A\n" << m_A << '\n';
	newMemory << "B\n" << m_B << '\n';
	
	sub = m_A - m_B;
	newMemory << "_________________________\nResult\n" << sub;
	newMemory.close();
	
	cout << sub;
}

template<class M>
void Transpose()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Operation<M> m_A;
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	newMemory << "Transpose\n__________________________\n";
	newMemory << "A\n" << m_A.getMatrix() << '\n';
	newMemory << "Result\n__________________________\n";
	newMemory << m_A.transpose();
	cout << m_A.transpose();
	newMemory.close();
}

template<class M>
void Equation()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Operation<M> m_A;
	Operation<M> m_B;
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	newMemory << "AX = B\n__________________________\n";
	newMemory << "A\n" << m_A.getMatrix() << '\n';
	newMemory << "Result\n__________________________\n";
	newMemory << m_A.equation(m_B);
	cout << m_A.equation(m_B);
	newMemory.close();
}

template<class M>
void Inverse()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Matrix<M> tmp;
	Operation<M> m_A;
	tmp = m_A.getMatrix();
	while (tmp.getRows() != tmp.getColumns())
	{
		cout << "Invalid input\nTry again.\n";
		m_A.create();
		tmp = m_A.getMatrix();
	}
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	newMemory << "Inverse\n__________________________\n";
	newMemory << "A\n" << m_A.getMatrix() << '\n';
	newMemory << "Result\n__________________________\n";
	if (m_A.inverse().getColumns() == 0)
	{
		cout << "The matrix has no inverse matrix\n";
		newMemory << "The matrix has no inverse matrix\n";
	}
	else
	{
		newMemory << m_A.inverse();
		cout << m_A.inverse();
		
	}
	newMemory.close();
}

template<class M>
void Determinant()
{
	cout << "Please enter name for memory file\n";
	string fileName;
	cin >> fileName;
	Matrix<M>  tmp;
	Operation<M> m_A;
	tmp = m_A.getMatrix();
	while (tmp.getRows() != tmp.getColumns())
	{
		cout << "Invalid input\nTry again.\n";
		m_A.create();
		tmp = m_A.getMatrix();
	}
	ofstream newMemory;
	newMemory.open((fileName + ".txt").c_str(), ios::app);
	newMemory << "Determinant\n__________________________\n";
	newMemory << "A\n" << m_A.getMatrix() << '\n';
	newMemory << "Result\n__________________________\n";
	newMemory << m_A.determinant() << '\n';
	cout << m_A.determinant();
	newMemory.close();
}

template<class M>
int mainMenu()
{
	bool loop = true
	while (loop)
	{


		cout << "Multiplication - M\n"
			<< "Addition - A\n"
			<< "Subtraction - S\n"
			<< "Transpose - T\n"
			<< "Determinant - D\n"
			<< "Inverse Matrix - I\n"
			<< "AX = B - E\n"
			<< "Exit - C\n";


		cin >> command;

		switch (int(command))
		{
		case 67: return 0; break;
		case 65: Addition<M>(); break;
		case 77: Multi<M>(); break;
		case 69: Equation<M>(); break;
		case 83: Subtraction<M>(); break;
		case 84: Transpose<M>(); break;
		case 73: Inverse<M>(); break;
		case 68: Determinant<M>(); break;
		}
	}
	
}


