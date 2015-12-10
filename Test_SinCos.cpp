/** Test_SinCos.cpp
 *
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Testing the functionality of the SinCos class of functions, and clarifing how to use it.
 *             The solver that will be used is mainly four step Adam BashForth. One of the solution will be tried with Backward Euler to see if the derivative is correct.
 */


#include <iostream>
#include <fstream>
#include "ODESolver.hpp" // Including the library of the ODE solver.
#include <cmath>

using namespace std;


int main() {


	// Declaring the parameters for the solver
	double initialTime = 0.0;
	double finalTime = 10.0;
	double initialValue = 3;
	int numbersteps = 1000;

	//-----Simple Sine--------

	// Creating the Right hand side equation, using the SinCos class.
	Righthandside * SineCosine;
	SineCosine= new SinCos<int> (1); // this is a simple sine function f(y,t)=Sin(y)


    //Pointer to the the base class of the family three of solvers.
    AbstractOdeSolver* pSolver = 0;

	//Create e new Four steps Adam Bashforth solver:
	pSolver = new FourStepSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream SineSolutionFile("solution_Simple_Sinus.dat");

	//Running the solver, if the solution file is open.
	if (SineSolutionFile.is_open())
	{
	pSolver->SolveEquation(SineCosine,SineSolutionFile);
	SineSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_Simple_Sinus.dat. Aborting." << std::endl;
	return 1;
	}

	// ---------- Simple Cosine--------------

	// Creating the Right hand side equation, using the SinCos class.
	SineCosine= new SinCos<int> (0,1); // this is a simple cosine function f(y,t)=Cos(y)

	// Opening a file in which the solutions can be saved:
	std::ofstream CosSolutionFile("solution_Simple_Cos.dat");

	//Running the solver, if the solution file is open.
	if (CosSolutionFile.is_open())
	{
	pSolver->SolveEquation(SineCosine,CosSolutionFile);
	CosSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_Simple_Cos.dat. Aborting." << std::endl;
	return 1;
	}

	// ---------- Sin+Cos--------------

	// Creating the Right hand side equation, using the SinCos class.
	SineCosine= new SinCos<double> (2,0.5,0.5,2); // this is a function: f(y,t)=2*Sin(0.5*y)+0.5*Cos(2*y)


	// Opening a file in which the solutions can be saved:
	std::ofstream SinCosSolutionFile("solution_SinCos.dat");

	//Running the solver, if the solution file is open.
	if (SinCosSolutionFile.is_open())
	{
	pSolver->SolveEquation(SineCosine,SinCosSolutionFile);
	SinCosSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_SinCos.dat. Aborting." << std::endl;
	return 1;
	}


	// ---------- Sin+Cos-------------- With backward Euler.

	//Create e new Backward Euler solver:
	pSolver = new BackwardEulerSolver;

	// Setting its initial conditions:
	pSolver->SetInitialValue(initialValue);
	pSolver->SetTimeInterval(initialTime, finalTime);
	pSolver->SetNumberSteps(numbersteps);

	// Opening a file in which the solutions can be saved:
	std::ofstream SinCosBSolutionFile("solution_SinCos_Backward.dat");

	//Running the solver, if the solution file is open.
	if (SinCosBSolutionFile.is_open())
	{
	pSolver->SolveEquation(SineCosine,SinCosBSolutionFile);
	SinCosBSolutionFile.close();
	}
	else
	{
	std::cout << "Couldn't open solution_SinCos_Backward.dat. Aborting." << std::endl;
	return 1;
	}



	std::cout << "Program executed correctly." << std::endl;


	return 0;




}
