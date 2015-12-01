#ifndef FORWARDEULERSOLVERHEADERDEF
#define FORWARDEULERSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class ForwardEulerSolver: public AbstractOdeSolver
{

public:
	double RightHandSide(double y, double t);
	void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
