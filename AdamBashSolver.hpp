#ifndef TWOSTEPSOLVERHEADERDEF
#define TWOSTEPSOLVERHEADERDEF

#include <string>
#include "AbstractOdeSolver.hpp"
#include "Righthandside.hpp"

class AdamBashSolver: public AbstractOdeSolver
{
	public:
	void SolveEquation(Righthandside f,std::ostream& stream);
};

#endif
