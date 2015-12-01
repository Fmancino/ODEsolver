#include "Righthandside.hpp"

Righthandside::Righthandside(double (*f)(double y, double t))
{
	f_rhs=f;
}

double Righthandside::value(double y, double t) const
{
	return f_rhs(y,t);
}

double Righthandside::gradient(double y, double t, double h) const
{
	double g;
	g=(f_rhs(y,t)-f_rhs(y-h,t))/h;
	return g;
}
