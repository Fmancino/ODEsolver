#include "AbstractOdeSolver.hpp"

void AbstractOdeSolver::SetNumberSteps(int n)
{
	stepNumber=n;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1)
{
	 initialTime=t0;
	 finalTime=t1;
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
