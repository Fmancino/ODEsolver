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
	double (*f_rhs)(double y, double t); //Function on the right hand side: f(y,t)
	double (*g_rhs)(double y, double t); //Gradient of the above function

	public:

	GenericFunction();
	virtual ~GenericFunction(); //Default Constructor and destructor

	GenericFunction(double (*f)(double y, double t)); //Constructor if you have only the function
	GenericFunction(double (*f)(double y, double t),double (*g)(double y, double t)); //Constructor if you have function and gradient


	virtual double value(double y, double t) const;
	virtual double gradient(double y, double t) const; //Virtual functions to get value and gradient of a generic function.

};
#endif
