

/*!
 * AbstracOdeSolver.cpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Abstract Base class for the family of methods for solving ODE of the form dy/dt = f(y, t).
 *             The possible methods are defined as derived classes from this class.
 */

/// \brief Abstract Base class for the family of methods for solving ODE of the form dy/dt = f(y, t).


#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF
#include "Righthandside.hpp"
#include <fstream>


class AbstractOdeSolver
{
    private:
    double stepNumber;   // Number of steps taken by the solver.
    double initialTime; // Time at which the solution starts.
    double finalTime; // Time at which the solution ends.
    double initialValue; // Initial value of the solution.
    public:

    AbstractOdeSolver();// Constructor
    virtual ~AbstractOdeSolver(); // Destructor

    void SetNumberSteps(int n); ///< Sets the number of steps taken by the ODE solver   .
    void SetTimeInterval(double t0, double t1); ///<Sets the time interval of the solution
    void SetInitialValue(double y0); ///< Sets the initial value of the solution


    // Different methods to get the values of the private variables.
    int GetNumberSteps();
    double GetInitialTime();
    double GetFinalTime();
    double GetInitialValue();

    /// Virtual function the solves the ODE with initial conditions, Time interval, and number of steps specified in the methods of "AbstactOdeSolver".
    /// The first input is the right hand side of the ODE, also a class, and the second input is the file in which the solution will be saved.
    virtual void SolveEquation(Righthandside* f, std::ostream& stream) = 0;
};
#endif
