#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF
#include "RightHandSide.hpp"
#include <fstream>

class AbstractOdeSolver
{
	private:
	double stepNumber;
	double initialTime;
	double finalTime;
	double initialValue;
	public:
	void SetNumberSteps(int n);
	void SetTimeInterval(double t0, double t1);
	void SetInitialValue(double y0);
	int GetNumberSteps();
	double GetInitialTime();
	double GetFinalTime();
	double GetInitialValue();

	virtual void SolveEquation(Righthandside f,std::ostream& stream) = 0;
};
#endif
