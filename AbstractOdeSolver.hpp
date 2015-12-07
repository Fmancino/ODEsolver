#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF
#include "RightHandSide.hpp"
#include <fstream>

// Abstract class containing the common methods for all the different ODE solvers.
// The ODE to be solved is of the form: dy/dt=f(y,t).

class AbstractOdeSolver
{
	private:
	double stepNumber;   // Number of steps taken by the solver.
	double initialTime; // Time at which the solution starts.
	double finalTime; //Time at which the solution ends.
	double initialValue; //Initial value of the solution.
	public:

	AbstractOdeSolver();  //Constructor
	virtual ~AbstractOdeSolver();  //Destructor

	void SetNumberSteps(int n); // Sets the number of steps taken by the ODE solver
	void SetTimeInterval(double t0, double t1); //Sets the time interval of the solution.
	void SetInitialValue(double y0); // Sets the initial value of the solution


	// Different methods to get the values of the private variables.
	int GetNumberSteps();
	double GetInitialTime();
	double GetFinalTime();
	double GetInitialValue();

	// Virtual function the solves the ODE, for initial conditions and Time interval specified in the methods above.
	// This function will be defined in the Derived classes, where every method is applied.
	// The first input is the right hand side of the ODE, and the second input is the file in which the solution will be saved.
	virtual void SolveEquation(Righthandside* f,std::ostream& stream) = 0;
};
#endif
