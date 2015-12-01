#include "Righthandside.hpp"

Righthandside::Righthandside(double (*f)(double y, double t))
{
	f_rhs=f;
	g_rhs=0; // Will give me error if i try to use it ;-)
}

Righthandside::Righthandside(double (*f)(double y, double t),double (*g)(double y, double t))
{
	f_rhs=f;
	g_rhs=g;
}

double Righthandside::value(double y, double t) const
{
	return f_rhs(y,t);
}

double Righthandside::gradient(double y, double t) const
{
	return g_rhs(y,t);
}
