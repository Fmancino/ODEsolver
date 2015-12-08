/* Test_logistic_extinction.cpp
 *
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: The Logistic equation with extinction threshold is used to test the functionality of the different solvers
 *			   and the polynomial class of functions.
 *	 		   The equation is usually be written like this: dy/dt=-r(1-y/T)(1-y/K)y which is a polynomial of grade 3: dy/dt=-r/(TK)*y^3+(r/T+r/K)*y^2-ry
 *			   T is the extinction limit for a population (under which the population will go extinct), K is the maximum number of individual that can be sustained and r the growt rate.
 *			   This equation is very good for testing the functionalities because the solution is well known: for a starting point under T the solution will converge to 0,
 *			   for a starting point over T the solution will converge to K and for the starting point T the solution will stay at T.
 *
 *			   This is a good opportunity to see the functionalities of the library.
 */


#include <iostream>
#include <fstream>
#include "ODESolver.hpp"
#include <cmath>

using namespace std;


int main() {

	//Declaring the parameters for the Logistic equation
	double T=1.0, K=2.0 , r=1.0;

	// Declaring the parameters for the solver
	double initialTime = 0.0;
	double finalTime = 10.0;
	double initialValue = 5;
	int numbersteps = 1000;

	// Creating the Right hand side equation, using the Polynomial class.
	Righthandside * poly;
	poly= new Polynomial<double> (0,-r,(r/T+r/K),-r/(T*K));
    cout << poly->value(3,2) << endl;

    //Pointer to the the base class of the family three of solvers.
    AbstractOdeSolver* pSolver = 0;


    //---- Create e new Forward Euler solver:  --------------------------------------------------------------------------------
	pSolver = new ForwardEulerSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Preparing a file in which the solutions can be saved:
	std::ofstream eulerSolutionFile("solution_ForwardEuler.dat");

	//Running the solver, if the solution file is open.
	if (eulerSolutionFile.is_open())
	{
		pSolver->SolveEquation(poly,eulerSolutionFile);
		eulerSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_ForwardEuler.dat. Aborting." << std::endl;
	return 1;
	}


	//---- Create e new Two steps Adam Bashforth solver:  --------------------------------------------------------------------------------
	pSolver = new TwoStepSolver;


	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream twostepSolutionFile("solution_twostep.dat");

	//Running the solver, if the solution file is open.
	if (twostepSolutionFile.is_open())
	{
			pSolver->SolveEquation(poly,twostepSolutionFile);
						twostepSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_twostep.dat. Aborting." << std::endl;
	return 1;
	}

	//---- Create e new Three steps Adam Bashforth solver:  --------------------------------------------------------------------------------
	pSolver = new ThreeStepSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream ThreeStepSolutionFile("solution_ThreeStep.dat");

	//Running the solver, if the solution file is open.
	if (ThreeStepSolutionFile.is_open())
	{
	pSolver->SolveEquation(poly,ThreeStepSolutionFile);
	ThreeStepSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_ThreeStep.dat. Aborting." << std::endl;
	return 1;
	}


	//---- Create e new Four steps Adam Bashforth solver:  --------------------------------------------------------------------------------
	pSolver = new FourStepSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream FourStepSolutionFile("solution_FourStep.dat");

	//Running the solver, if the solution file is open.
	if (FourStepSolutionFile.is_open())
	{
	pSolver->SolveEquation(poly,FourStepSolutionFile);
	FourStepSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_FourStep.dat. Aborting." << std::endl;
	return 1;
	}

	//---- Create e new Backward Euler solver:  --------------------------------------------------------------------------------
	pSolver = new BackwardEulerSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream BackwardEulerSolutionFile("solution_BackwardEuler.dat");

	//Running the solver, if the solution file is open.
	if (BackwardEulerSolutionFile.is_open())
	{
	pSolver->SolveEquation(poly,BackwardEulerSolutionFile);
	BackwardEulerSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_BackwardEuler.dat. Aborting." << std::endl;
	return 1;
	}

	std::cout << "Program executed correctly." << std::endl;

	return 0;




}
