#ifndef BACKWARDEULERSOLVERHEADERDEF
#define BACKWARDEULERSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class BackwardEulerSolver: public AbstractOdeSolver
{
	public:
	BackwardEulerSolver();
	virtual ~BackwardEulerSolver();
	virtual void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
