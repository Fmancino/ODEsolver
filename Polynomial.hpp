/**
 * Polynomial.hpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Derived class from Righthandside. Allow the user to specify a polynomial of grade 2 up to 4,
 *			   in the form: a+b*x+c*x^2+d*x^3+e*x^4.
 *			   The choice is given as to have int or double values for the coefficients with the the use of a template.
 */

/// \brief Class that allows the user to specify a polynomial of grade 2 up to 4, in the form: a+b*x+c*x^2+d*x^3+e*x^4, as the right hand side of the ODE.

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
	Polynomial() //Default constructor
		{
	    	SetGradientInfo(true);
			a=0;
			b=0;
			c=0;
			d=0;
			e=0;
		}

	~Polynomial() //Default destructor
	{}

	/// Constructor for a polynomial of grade 2: a+b*x+c*x^2
    Polynomial(T a1,T b1,T c1)
	{
    	SetGradientInfo(true);
		a=a1;
		b=b1;
		c=c1;
		d=0;
		e=0;
	}

    /// Constructor for a polynomial of grade 3: a+b*x+c*x^2+d*x^3
    Polynomial(T a1,T b1,T c1,T d1)
    {
    	SetGradientInfo(true);
    	a=a1;
    	b=b1;
    	c=c1;
    	d=d1;
    	e=0;
    }

    /// Constructor for a polynomial of grade 4: a+b*x+c*x^2+d*x^3+e*x^4
    Polynomial(T a1,T b1,T c1,T d1, T e1)
    {
    	SetGradientInfo(true);
    	a=a1;
    	b=b1;
    	c=c1;
    	d=d1;
    	e=e1;
    }

    virtual double value(double y, double t) const //Returns the value of the polynomial
    {
    	return a+b*y+c*pow(y,2)+d*pow(y,3)+e*pow(y,4);
    }

    virtual double gradient(double y,double t) const //Returns derivative of the polynomial
    {
    	return b+2*c*y+3*d*pow(y,2)+4*d*pow(y,3);
    }
};

#endif
