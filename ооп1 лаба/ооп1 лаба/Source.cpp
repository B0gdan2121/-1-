#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#define NL std::cout << '\n'
using namespace std;

class valueB
{
protected:
	double x;
	double y;
	double z;

public:
	valueB(double X, double Y, double Z)
	{
		x = X; y = Y; z = Z;
	}

	double Calc()
	{
		double b = pow(fabs(((x + y) / pow(fabs(z), 0.6)) + (pow(sin((x + z * z) / (2 * x + y)), 2))), 1. / 3) - (z * exp((x * x - y) / (1 + z)));
		return b;
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}

	double getZ()
	{
		return z;
	}
};

class valueA : public valueB
{
private:
	double b;

public:
	valueA(double X, double Y, double Z, double B) : valueB(X, Y, Z)
	{
		b = B;
	}

	double Calc()
	{
		double  a = (y * y) + (((z / (x * z)) + pow(b, 2)) / (fabs((pow(x, 2) + y) / (z + (pow(x, 3) / 3))))) - (log(x * x + z));
		
		
		return a;
	}

	double getB()
	{
		return b;
	}
};



void main()
{
	NL; NL; NL;
	double x = 0.48 * 4;
	double y = 0.47 * 4;
	double z = -1.32 * 4;

	cout << "Task 1:" << endl;
	valueB b(x, y, z);
	valueA a(x, y, z, b.Calc());
	cout << "b[x, y, z] = " << b.Calc(); NL;
	cout << "a[x, y, z, b] = " << a.Calc(); NL; NL;

	cout << "Task 2:"; NL;
	for (double x = -1.0; x <= 1.0; x += 0.2)
	{
		valueB b(x, y, z);
		valueA a(x, y, z, b.Calc());
		cout << "x = " << to_string(x).substr(0, 4) << setw(20) << "a[x, y, z, b] = " << to_string(a.Calc()).substr(0, 8) << setw(20) << "b[x, y, z] = " << to_string(b.Calc()).substr(0, 8) << endl;
	}
	NL; NL; NL;
}