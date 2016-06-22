#include "complex.h"


complex::complex(double a, double b)
{
	real = a;
	img = b;
}

double complex::getReal()
{
	return real;
}

double complex::getImg()
{
	return img;
}

complex::~complex()
{
}

istream& operator>>(istream& in, complex& obj)
{
	char input[30];
	in >> input;
	char buffer[30];
	int s1 = -1, s2 = -1;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '-' || input[i] == '+')
			s1 = i;
		if (input[i] == 'i')
			s2 = i;
	}
	if (s2 == -1)
	{
		obj.img = 0;
		obj.real = atoi(input);
	}
	if (s1 == -1 && s2 != -1)
	{
		obj.real = 0;
		if (input[0] == 'i')
			obj.img = 1;
		else
			obj.img = atoi(input);
	}
	if (s1 != -1 && s2 != -1)
	{
		if (s1 == 0)
		{
			obj.real = 0;
			if (input[1] == 'i')
			{
				if (input[0] = '-')
					obj.img = -1;
				else obj.img = 1;
			}
			else
				obj.img = atoi(input);
		}
		else
		{
			for (int i = 0; i < s1; i++)
			{
				buffer[i] = input[i];

			}
			obj.real = atoi(buffer);

			for (int j = s1; j < strlen(input); j++)
			{
				buffer[j - s1] = input[j];

			}
			if (strlen(input) - 2 == s1)
			{
				if (input[s1] == '-')
					obj.img = -1;
				else if (input[s1] == '+')
					obj.img = 1;
			}
			else
				obj.img = atoi(buffer);
		}
	}
	return in;
}

ostream& operator<<(ostream& out, complex& obj)
{
	if (obj.real == 0 && obj.img == 0)
	{
		out << 0;// << '\n';
	}
	else
	{
		switch ((int)obj.real)
		{
		case 0:if (obj.real != 0) out << obj.real; break;
		default: out << obj.real; break;
		}
		switch ((int)obj.img)
		{
		case 0: if (obj.img != 0)
		{
					if (obj.img < 0)
						out << obj.img << 'i';
					else
						out << '+' << obj.img << 'i';
		}
		break;
		case 1: if (obj.img != 1)
		{
					out << obj.img << 'i';

		}
				else
					out << "+i";
		break;
		case -1: if (obj.img != -1)
		{
					 out << obj.img << 'i';
		}
				 else
					 out << "-i";
		break;
		default: if (obj.img < 0)  out << obj.img << "i";
				 else out << '+' << obj.img << "i"; break;
		}
	}
	//out << obj.real << " " << obj.img;
	return out;
}
complex operator+(complex& obj1, complex& obj2)
{
	complex tmp(obj1.real + obj2.real, obj1.img + obj2.img);
	return tmp;

}

complex operator-(complex& obj1, complex& obj2)
{
	complex tmp(obj1.real - obj2.real, obj1.img - obj2.img);
	return tmp;
}

complex operator*(complex& obj1, complex& obj2)
{
	complex tmp(obj1.real * obj2.real - obj1.img * obj2.img,
		obj1.real * obj2.img + obj1.img *obj2.real);
	return tmp;
}

complex operator/(complex& obj1, complex& obj2)
{

	complex result;
	if (obj2.img == 0)
	{
		result.real = obj1.real / obj2.real;
		result.img = obj1.img / obj2.real;
	}
	else if (obj2.img == 0 && obj1.img == 0)
	{
		result.real = obj1.real / obj2.real;
		result.img = 0;
	}
	else
	{
		complex tmp(obj2.real, -obj2.img);
		result = tmp * obj1;
		result.real = result.real / (obj2.real * obj2.real +
			obj2.img * obj2.img);
		result.img = result.img / (obj2.real * obj2.real +
			obj2.img * obj2.img);
	}

	return result;

}

bool complex::operator!=(complex& obj)
{
	if (real == obj.real && img == obj.img)
		return false;
	else
		return true;
}

complex complex::operator*(double n)
{
	complex result(n * real, n * img);
	return result;

}

