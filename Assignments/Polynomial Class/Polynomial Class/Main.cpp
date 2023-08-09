#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial<int> p1;
	p1.addTerm(-2, 5);
	p1.addTerm(4, 3);
	p1.addTerm(3, 2);
	p1.addTerm(1, 0);
	Polynomial<int> p2;
	p2.addTerm(-3, 5);
	p2.addTerm(5, 3);
	p2.addTerm(2, 2);
	p2.addTerm(1, 0);
	cout << "p1 = " << p1.ToString() << endl;
	cout << "p2 = " << p2.ToString() << endl;
	Polynomial<int> sum = p1 + p2;
	Polynomial<int> diff = p1 - p2;
	Polynomial<int> prod = p1 * p2;
	cout << "p1 + p2 = " << sum.ToString() << endl;
	cout << "p1 - p2 = " << diff.ToString() << endl;
	cout << "p1 * p2 = " << prod.ToString() << endl;
	
	int value = 2;
	cout << "\np1 evaluated at " << value << " is " << p1.evaluate(value);
	cout << "\np2 evaluated at " << value << " is " << p2.evaluate(value);
	p1.addToCoefficient(2, 2);
	cout << "\np1 after adding 2 to coefficient of power 2: " << p1.ToString();
	p2.addToCoefficient(4, 2);
	cout << "\np1 after adding 4 to coefficient of power 2: " << p2.ToString();
	p1.clear();
	cout << "\np1 after clearing: " << p1.ToString() << endl;
	return 0;
}