/*
 * ForwardEulersolver.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Forward Eulers method to solve a ODE of the form: dy/dt=f(y,t).
 * 				It is derived from the abstract class AbstractOdeSolver.
 */


#ifndef FORWARDEULERSOLVERHEADERDEF
#define FORWARDEULERSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class ForwardEulerSolver: public AbstractOdeSolver
{
public:
	ForwardEulerSolver();
	virtual ~ForwardEulerSolver(); // Constructor and Destructor

	//Method for solving the ODE:
	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
