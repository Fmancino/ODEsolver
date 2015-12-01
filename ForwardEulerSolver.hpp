#ifndef FORWARDEULERSOLVERHEADERDEF
#define FORWARDEULERSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class ForwardEulerSolver: public AbstractOdeSolver
{
public:
	ForwardEulerSolver();
	virtual ~ForwardEulerSolver();
	virtual void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
