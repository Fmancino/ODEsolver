/*
 * GenericFunction.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Derived class from Righthandside. Allow the user to specify a generic function and its gradient, with the use of function pointers.
 *Description: The choice is given as to whether to specify the gradient or not, thought the use of two different constructors.
 */

#ifndef GENERICFUNCTIONHEADERDEF
#define GENERICFUNCTIONHEADERDEF
#include "Righthandside.hpp"

class GenericFunction: public Righthandside
{
	private:
	double (*f_rhs)(double y, double t);
	double (*g_rhs)(double y, double t);
	public:
	GenericFunction();
	virtual ~GenericFunction();
	GenericFunction(double (*f)(double y, double t));
	GenericFunction(double (*f)(double y, double t),double (*g)(double y, double t));
	virtual double value(double y, double t) const;
	virtual double gradient(double y, double t) const;

};
#endif
