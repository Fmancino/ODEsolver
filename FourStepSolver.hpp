#ifndef FOURSTEPSOLVERHEADERDEF
#define FOURSTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class FourStepSolver: public AbstractOdeSolver
{
	public:
	FourStepSolver();
	virtual ~FourStepSolver();
	virtual void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
