/**
 *
 * Righthandside.hpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Abstract class which is the head of the family of possible right hand side functions f(y,t) in the ODE dy/dt=f(y,t).
 *			   The possible functions will be define as derived classes from this class.
 */

#ifndef RIGHTHANDSIDEDEF
#define RIGHTHANDSIDEDEF

class Righthandside
{
private:
	bool HaveGradient;  ///< Boolean variable used for determining if the function has a gradient and backward Euler can be performed with Newtons method.
	public:
	Righthandside();
	virtual ~Righthandside(); //Constructor and destructor


	void SetGradientInfo(bool a); ///< Function to set the information about the gradient: if we have a gradient or not (going to be used inside the other classes).
	bool GetGradientInfo() const; ///< Function to get the information about the gradient.

	/// Virtual function to get the value of the function on the right hand side, f(y,t) for a specific y and t.
	virtual double value(double y, double t) const = 0;
	/// Virtual function to get the value gradient of the function on the right hand side, f'(y,t) for a specific y and t.
	virtual double gradient(double y, double t) const = 0;

};
#endif
