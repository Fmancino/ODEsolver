/*
 * Righthandside.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Abstract class which is the head of the family of possible right hand side functions f(y,t) in the ODE dy/dt=f(y,t).
 *			   The possible functions will be define as derived classes from this class.
 */

#include "Righthandside.hpp"

Righthandside::Righthandside()
{HaveGradient=false;}

Righthandside::~Righthandside()
{}

void Righthandside::SetGradientInfo(bool A)
{
	HaveGradient=A;
}

bool Righthandside::GetGradientInfo() const
{
	return HaveGradient;
}



