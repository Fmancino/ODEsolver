/*
 * Righthandside.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Abstract class which is the head of the family of possible right hand side functions f(y,t) in the ODE dy/dt=f(y,t).
 *			   The possible functions will be define as derived classes from this class.
 */

#ifndef RIGHTHANDSIDEDEF
#define RIGHTHANDSIDEDEF

class Righthandside
{
private:
	bool HaveGradient;  //Boolean variable used for determining if the function has a gradient and backward Euler can be performed with Newtons method.
	public:
	Righthandside();
	virtual ~Righthandside(); //Constructor and destructor

	// Functions to get and set the information about the gradient, if we have a gradient or not (going to be used inside the other classes).
	void SetGradientInfo(bool a);
	bool GetGradientInfo() const;

	// Virtual function to get the value of the function on the right hand side and its gradient. They are going to be defined in the derived classes.
	virtual double value(double y, double t) const = 0;
	virtual double gradient(double y, double t) const = 0;

};
#endif
