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

GenericFunction::GenericFunction()
{}

GenericFunction::~GenericFunction()
{}

GenericFunction::GenericFunction(double (*f)(double y, double t))
{
	f_rhs=f;
	SetGradientInfo(false);
	g_rhs=0; //should not be used.
}

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
		std::cout << "Warning: Gradient not specified, no estimate of it will be given." << std::endl;
	    return 0;
	}
}

