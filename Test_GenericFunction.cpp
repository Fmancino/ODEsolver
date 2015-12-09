/**  Test_genericfunction.cpp
 *
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: We will test the funtionality of the "GenericFunction" class.
 * 			   To do that a simple logistic function will be used, with the addiction of a time dependent component (which will go to zero as time goes to infinity: for the population model, it could represent a resource that finishes).
 * 			   The expected result is a fast growing rate in the beginning, and then a slow descent towards the stable value 1.
 * 			   Due to the time dependent part this function cannot be modelled with the polynomial class, therefore it has to be introduced in the program with the "GenericFunction" class.
 * 			   The result will be calculated using the runge-kutta solver, the backward-euler solver and the backward euler solver without specifying the gradient.
 * 			   The result behaves as expected for all three solvers, thus suggesting that there are no major mistakes.
 *
*/


#include <iostream>
#include <fstream>
#include "ODESolver.hpp"
#include <cmath>

using namespace std;

double fRhs(double y, double t)  // Right hand side of the differential equation: f(y,t). It will be passed as a pointer.
{
	return -pow(y,2)+y+exp(-0.5*t)*(1+t);
}

double gradient(double y, double t) // Derivative of the right hand side.
{
	return -2*y+1;
}

int main() {

	Righthandside *f;
	f=new GenericFunction (fRhs,gradient);

	double initialTime = 0.0;
	double finalTime = 20;
	double initialValue = 0.1;
	double numbersteps = 10000;

	//Initializint the Solver:
    AbstractOdeSolver* pSolver = 0;

	//---- Create e new Fourth order Runge Kutta solver:  --------------------------------------------------------------------------------
	pSolver = new RungeKutta4Solver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream RungeSolutionFile("solution_Runge_Gen.dat");

	//Running the solver, if the solution file is open.
	if (RungeSolutionFile.is_open())
	{
	pSolver->SolveEquation(f,RungeSolutionFile);
	RungeSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_Runge_Gen.dat. Aborting." << std::endl;
	return 1;
	}

	//---- Create e new Backward Euler solver:  --------------------------------------------------------------------------------
	pSolver = new BackwardEulerSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream BackwardEulerSolutionFile("solution_BackwardGen.dat");

	//Running the solver, if the solution file is open.
	if (BackwardEulerSolutionFile.is_open())
	{
	pSolver->SolveEquation(f,BackwardEulerSolutionFile);
	BackwardEulerSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_BackwardGen.dat. Aborting." << std::endl;
	return 1;
	}

	//---- Testing the functionality of the secant method---------------------------

	//Creating the same function using the generic function class, but without specifing the gradient.
	Righthandside *g;
	g=new GenericFunction (fRhs);



	// Opening a file in which the solutions can be saved:
	std::ofstream BackwardSecantSolutionFile("solution_BackwardEulerSecantGen.dat");

	//Running the solver, if the solution file is open.
	if (BackwardSecantSolutionFile.is_open())
	{
	pSolver->SolveEquation(g,BackwardSecantSolutionFile);
	BackwardSecantSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_SecantGen.dat. Aborting." << std::endl;
	return 1;
	}

	std::cout << "Program executed correctly. " << std::endl;

	return 0;



	return 0;
}


