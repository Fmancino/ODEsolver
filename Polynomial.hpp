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
    Polynomial(T a1,T b1,T c1)
	{
		a=a1;
		b=b1;
		c=c1;
		d=0;
		e=0;
	}
    Polynomial(T a1,T b1,T c1,T d1)
    {
    	a=a1;
    	b=b1;
    	c=c1;
    	d=d1;
    	e=0;
    }
    Polynomial(T a1,T b1,T c1,T d1, T e1)
    {
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
