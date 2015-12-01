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
	virtual void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
