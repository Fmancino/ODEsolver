/*
 * BackwardEulersolver.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Backward Eulers method to solve a ODE of the form: dy/dt=f(y,t).
 * It is derived from the abstract class AbstractOdeSolver.
 * To Solve the equation arising due to the fact that Backward Eulers method is implicit,
 * Newtons method is used if the gradient is specified and the secant method is used it the gradient is not specified.
 */

#ifndef BACKWARDEULERSOLVERHEADERDEF
#define BACKWARDEULERSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class BackwardEulerSolver: public AbstractOdeSolver
{
	public:
	BackwardEulerSolver();
	virtual ~BackwardEulerSolver(); // Constructor and destructor.

	// Method for solving the equation using Backwards Eulers Method.
	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
