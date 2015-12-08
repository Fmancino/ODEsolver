/*
 * FourStepSolver.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Four Step Adam Bashworts Method to solve a ODE of the form: dy/dt=f(y,t).
 * 			   It is derived from the abstract class AbstractOdeSolver.
 */

#ifndef FOURSTEPSOLVERHEADERDEF
#define FOURSTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class FourStepSolver: public AbstractOdeSolver
{
	public:
	FourStepSolver();
	virtual ~FourStepSolver(); // Constructor and Destructor.

	// Method for solving the ODE.
	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
