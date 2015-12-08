/*
 * Polynomual.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Derived class from Righthandside. Allow the user to specify a polynomial of grade 2 up to 4,
 *Description: in the form: a+b*x+c*x^2+d*x^3+e*x^4.
 *Description: The choice is given as to have int or double values for the coefficients with the the use of a template.
 */

#ifndef POLYNOMIALHEADERDEF
#define POLYNOMIALHEADERDEF

#include <cmath>
#include <string>
#include "Righthandside.hpp"


template <class T> class Polynomial: public Righthandside
{
	private:
	T a,b,c,d,e;
	public:
	Polynomial()
		{
	    	SetGradientInfo(true);
			a=0;
			b=0;
			c=0;
			d=0;
			e=0;
		}

	~Polynomial()
	{}
    Polynomial(T a1,T b1,T c1)
	{
    	SetGradientInfo(true);
		a=a1;
		b=b1;
		c=c1;
		d=0;
		e=0;
	}
    Polynomial(T a1,T b1,T c1,T d1)
    {
    	SetGradientInfo(true);
    	a=a1;
    	b=b1;
    	c=c1;
    	d=d1;
    	e=0;
    }
    Polynomial(T a1,T b1,T c1,T d1, T e1)
    {
    	SetGradientInfo(true);
    	a=a1;
    	b=b1;
    	c=c1;
    	d=0;
    	e=0;
    }
    virtual double value(double y, double t) const
    {
    	return a+b*y+c*pow(y,2)+d*pow(y,3)+e*pow(y,4);
    }
    virtual double gradient(double y,double t) const
    {
    	return b+2*c*y+3*d*pow(y,2)+4*d*pow(y,3);
    }
};

#endif
