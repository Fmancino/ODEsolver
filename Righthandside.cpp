/*
 * Righthandside.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Abstract Base class of the family of possible right hand side functions f(y,t) in the ODE dy/dt=f(y,t).
 *			   The possible functions will be define as derived classes from this class.
 */

#include "Righthandside.hpp"

Righthandside::Righthandside() //Default constructor
{HaveGradient=false;}

Righthandside::~Righthandside() //Destructor
{}

void Righthandside::SetGradientInfo(bool A) //Sets the information about the gradient
{
	HaveGradient=A;
}

bool Righthandside::GetGradientInfo() const //Returns information about the gradient
{
	return HaveGradient;
}



