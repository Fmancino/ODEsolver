/*
 * TwoStepSolver.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Two Step Adam Bashworts Method to solve a ODE of the form: dy/dt=f(y,t).
 * 			   It is derived from the abstract class AbstractOdeSolver.
 */

#ifndef TWOSTEPSOLVERHEADERDEF
#define TWOSTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class TwoStepSolver: public AbstractOdeSolver
{

	public:
	TwoStepSolver();
	virtual ~TwoStepSolver();

	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
