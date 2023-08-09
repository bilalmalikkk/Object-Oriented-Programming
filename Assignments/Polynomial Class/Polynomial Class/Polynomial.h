#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

template <typename T>
class Polynomial
{
private:
	struct Term
	{
		T coeff;
		int exp;
	};
	Term* terms;
	int capacity;
	int currSize;
public:
	Polynomial()
	{
		terms = nullptr;
		capacity = 0;
		currSize = 0;

	}
	Polynomial(int cap)
	{
		terms = new Term[cap];
		capacity = cap;
		currSize = 0;
	}
	Polynomial(const Polynomial& other)
	{
		terms = new Term[other.capacity];
		capacity = other.capacity;
		currSize = other.currSize;
		for (int i = 0; i < currSize; i++)
		{
			terms[i].coeff = other.terms[i].coeff;
			terms[i].exp = other.terms[i].exp;
		}
	}
	~Polynomial()
	{
		delete[] terms;
	}

	
	Polynomial& operator =(const Polynomial& other)
	{
		if (this != &other)
		{
			delete[] terms;
			terms = new Term[other.capacity];
			capacity = other.capacity;
			currSize = other.currSize;
			for (int i = 0; i < currSize; i++)
			{
				terms[i].coeff = other.terms[i].coeff;
				terms[i].exp = other.terms[i].exp;
			}
		}
		return *this;
	}

	Polynomial& operator +(const Polynomial& other)
	{
		for (int i = 0; i < other.currSize; i++)
		{
			int exp = other.terms[i].exp;
			T coeff = other.terms[i].coeff;
			addTerm(coeff, exp);
		}
		return *this;
	}

	Polynomial& operator -(const Polynomial& other)
	{
		for (int i = 0; i < other.currSize; i++)
		{
			int exp = other.terms[i].exp;
			T coeff = -other.terms[i].coeff;
			addTerm(coeff, exp);
		}
		return *this;
	}


	Polynomial operator *(const Polynomial& other) const
	{
		Polynomial result(currSize * other.currSize);
		for (int i = 0; i < currSize; i++)
		{
			for (int j = 0; j < other.currSize; j++)
			{
				int newExp = terms[i].exp + other.terms[j].exp;
				T newCoeff = terms[i].coeff * other.terms[j].coeff;
				bool found = false;
				for (int k = 0; k < result.currSize; k++)
				{
					if (result.terms[k].exp == newExp)
					{
						result.terms[k].coeff += newCoeff;
						found = true;
						break;
					}
				}
				if (!found)
				{
					result.terms[result.currSize].exp = newExp;
					result.terms[result.currSize].coeff = newCoeff;
					result.currSize++;
				}
			}
		}
		return result;
	}

	void expandCapacity()
	{
		Term* newTerms = new Term[2 * capacity];
		for (int i = 0; i < currSize; i++)
		{
			newTerms[i] = terms[i];
		}
		delete[] terms;
		terms = newTerms;
		capacity *= 2;
	}

	

	void addTerm(T coeff, int exp)
	{
		if (currSize == capacity)
		{
			expandCapacity();
		}
		int i = 0;
		while (i < currSize && terms[i].exp > exp)
		{
			i++;
		}
		if (i < currSize && terms[i].exp == exp)
		{
			terms[i].coeff += coeff;
			if (terms[i].coeff == 0)
			{
				for (int j = i; j < currSize - 1; j++)
				{
					terms[j] = terms[j + 1];
				}
				currSize--;
			}
		}
		else
		{
			for (int j = currSize - 1; j >= i; j--)
			{
				terms[j + 1] = terms[j];
			}
			terms[i].coeff = coeff;
			terms[i].exp = exp;
			currSize++;
		}
	}

	//bool addTerm(T coefficient, int power) 
	//{
	//	for(int i = 0; i < currSize; i++) 
	//	{
	//		if (terms[i].exp == power) 
	//		{
	//			terms[i].coeff += coefficient;
	//			return true;
	//		}
	//	}

	//	// Term with given power does not exist
	//	addTerm(coefficient, power);
	//	return true;
	//}

	bool getDegree(int& deg) const
	{
		cout << "bilal";
		if (currSize == 0)
		{
			return false;
		}

		int maxExp = terms[0].exp;
		for (int i = 1; i < currSize; i++)
		{
			if (terms[i].exp > maxExp)
			{
				maxExp = terms[i].exp;
			}
		}

		deg = maxExp;
		return true;
	}

	
	T evaluate(const T& value) const
	{
		T result = 0;
		for (int i = 0; i < currSize; i++)
		{
			result += terms[i].coeff * pow(value, terms[i].exp);
		}
		return result;
	}



	bool getCoefficient(int power, T& coeff) const
	{
		for (int i = 0; i < currSize; i++)
		{
			if (terms[i].exp == power)
			{
				coeff = terms[i].coeff;
				return true;
			}
		}

		
		return false;
	}

	


	void addToCoefficient(T delta, int power)
	{
		for (int i = 0; i < currSize; i++)
		{
			if (terms[i].exp == power)
			{
				terms[i].coeff += delta;
				return;
			}
		}

		
		addTerm(delta, power);
	}


	void clear()
	{
		for (int i = 0; i < currSize; i++)
		{
			terms[i].coeff = 0;
		}
	}

	Polynomial<T> derivative() const
	{
		Polynomial<T> result;
		result.capacity = capacity - 1;
		result.currSize = 0;
		result.terms = new Term[result.capacity];

		for (int i = 0; i < currSize; i++) 
		{
			if (terms[i].exp > 0) {
				result.terms[result.currSize].coeff = terms[i].coeff * terms[i].exp;
				result.terms[result.currSize].exp = terms[i].exp - 1;
				result.currSize++;
			}
		}

		return result;
	}

	string ToString() const
	{
		string str;
		bool firstTerm = true;
		for (int i = 0; i < currSize; i++)
		{
			if (terms[i].coeff == 0)
				continue;
			if (!firstTerm && terms[i].coeff > 0)
				str += " + ";
			else if (terms[i].coeff < 0)
				str += " - ";
			if (abs(terms[i].coeff) != 1 || terms[i].exp == 0)
				str += to_string(abs(terms[i].coeff));
			if (terms[i].exp > 0)
				str += "x";
			if (terms[i].exp > 1)
				str += "^" + to_string(terms[i].exp);
			firstTerm = false;
		}
		if (firstTerm)
			str += "0";
		return str;
	}



};
