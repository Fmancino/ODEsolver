/**
 * TrheeStepSolver.cpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Class that implements Three Step Adam Bashworts Method to solve a ODE of the form: dy/dt = f(y, t).
 *             It is derived from the abstract class AbstractOdeSolver.
 */

/// \brief  Class that implements Four Three Adam Bashworts Method to solve a ODE of the form: dy/dt = f(y, t).
#ifndef THREESTEPSOLVERHEADERDEF
#define THREESTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class ThreeStepSolver: public AbstractOdeSolver
{
    public:
    ThreeStepSolver();
    virtual ~ThreeStepSolver();
    virtual void SolveEquation(Righthandside* f, std::ostream& stream);
};

#endif
