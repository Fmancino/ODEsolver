/*
 * GenericFunction.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Derived class from Righthandside. Allow the user to specify a generic function and its gradient, with the use of function pointers.
 *Description: The choice is given as to whether to specify the gradient or not, thought the use of two different constructors.
 */


#include "Righthandside.hpp"
#include "GenericFunction.hpp"
#include <iostream>

GenericFunction::GenericFunction() //default constructor
:f_rhs(0),g_rhs(0)
{}

GenericFunction::~GenericFunction() //destructor
{}

// Constructor which does not specify the gradient,  only input is the function:
GenericFunction::GenericFunction(double (*f)(double y, double t))
{
	f_rhs=f; //Righthanside funtion
	SetGradientInfo(false);
	g_rhs=0; //Should not be used.
}

// Constructor which does specify the gradient, first input is function and second input is its gradient:
GenericFunction::GenericFunction(double (*f)(double y, double t),double (*g)(double y, double t))
{
	f_rhs=f;
	g_rhs=g;
	SetGradientInfo(true);
}

double GenericFunction::value(double y, double t) const
{
	return f_rhs(y,t);
}

double GenericFunction::gradient(double y, double t) const
{
	if (GetGradientInfo() == true)
	{
	return g_rhs(y,t);
	}
	else
	{
		std::cout << "<GenericFunction> ERROR: Gradient not specified, function returns 0, NOT TO BE USED!!!!!!" << std::endl;
	    return 0; // Only because it is necessary to retunr something.
	}
}

