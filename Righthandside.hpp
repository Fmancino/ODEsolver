#ifndef RIGHTHANDSIDEDEF
#define RIGHTHANDSIDEDEF

class Righthandside
{
	private:
	double (*f_rhs)(double y, double t);
	double (*g_rhs)(double y, double t);
	public:
	//Righthandside();
	Righthandside(double (*f)(double y, double t));
	Righthandside(double (*f)(double y, double t),double (*g)(double y, double t));
	double value(double y, double t) const;
	double gradient(double y, double t) const;

};
#endif
