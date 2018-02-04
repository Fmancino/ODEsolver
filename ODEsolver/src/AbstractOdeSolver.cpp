/*
 * AbstracOdeSolver.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Abstract Base class of the family of methods for solving ODE of the form dy / dt = f(y, t).
 *             The possible methods are defined as derived classes from this class.
 *             The definition of every function is given in the header file.
 */

#include "AbstractOdeSolver.hpp"
#include <cassert>

AbstractOdeSolver::AbstractOdeSolver()
    : stepNumber(),
      initialTime(),
      finalTime(),
      initialValue()
{}

AbstractOdeSolver::~AbstractOdeSolver()
{}

void AbstractOdeSolver::SetNumberSteps(int n)
{
    assert(n > 0);
    stepNumber = n;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1)
{
    assert(t1 > t0);
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0)
{
    initialValue = y0;
}

int AbstractOdeSolver::GetNumberSteps()
{
    return stepNumber;
}


double AbstractOdeSolver::GetInitialTime()
{
    return initialTime;
}

double AbstractOdeSolver::GetFinalTime()
{
    return finalTime;
}

double AbstractOdeSolver::GetInitialValue()
{
    return initialValue;
}
