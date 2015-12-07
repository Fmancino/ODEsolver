#ifndef RIGHTHANDSIDEDEF
#define RIGHTHANDSIDEDEF

class Righthandside
{
	public:
	//Righthandside();
	Righthandside();
	virtual double value(double y, double t) const = 0;
	virtual double gradient(double y, double t) const = 0;

};
#endif
