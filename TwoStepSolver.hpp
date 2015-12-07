#ifndef TWOSTEPSOLVERHEADERDEF
#define TWOSTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class TwoStepSolver: public AbstractOdeSolver
{

	public:
	TwoStepSolver();
	virtual ~TwoStepSolver();
	virtual void SolveEquation(Righthandside* f,std::ostream& stream);
};

#endif
