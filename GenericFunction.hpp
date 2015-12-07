#ifndef GENERICFUNCTIONHEADERDEF
#define GENERICFUNCTIONHEADERDEF
#include "Righthandside.hpp"

class GenericFunction: public Righthandside
{
	private:
	double (*f_rhs)(double y, double t);
	double (*g_rhs)(double y, double t);
	bool havegradient;
	public:
	//Righthandside();
	GenericFunction();
	virtual ~GenericFunction();
	GenericFunction(double (*f)(double y, double t));
	GenericFunction(double (*f)(double y, double t),double (*g)(double y, double t));
	virtual double value(double y, double t) const;
	virtual double gradient(double y, double t) const;

};
#endif
