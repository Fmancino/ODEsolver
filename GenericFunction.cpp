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
	havegradient= false;
	g_rhs=f; // Will give me error if i try to use it ;-)
}

GenericFunction::GenericFunction(double (*f)(double y, double t),double (*g)(double y, double t))
{
	f_rhs=f;
	g_rhs=g;
	havegradient=true;
}

double GenericFunction::value(double y, double t) const
{
	return f_rhs(y,t);
}

double GenericFunction::gradient(double y, double t) const
{
	if (havegradient == true)
	{
	return g_rhs(y,t);
	}
	else
	{
		std::cout << "Warning: Gradient not specified, try using another method." << std::endl;
	    return 0;
	}
}

