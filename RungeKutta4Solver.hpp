/**
 * RungeKutta4Solver.cpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Class that implements 4th order Runge-Kutta method to solve a ODE of the form: dy/dt=f(y,t).
 * 			   It is derived from the abstract class AbstractOdeSolver.
 */

#ifndef RUNGEKUTTA4SOLVERHEADERDEF
#define RUNGEKUTTA4SOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class RungeKutta4Solver: public AbstractOdeSolver
{
public:
	RungeKutta4Solver();
	virtual ~RungeKutta4Solver(); // Constructor and Destructor

	//Method for solving the ODE:
	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
