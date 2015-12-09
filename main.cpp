#include <iostream>
#include <fstream>
#include "ODESolver.hpp"
#include <cmath>

using namespace std;

double fRhs(double y, double t)  // Right hand side
{
	return pow(y,2)+exp(-t);
}

double gradient(double y, double t) // Derivative of the right hand side
{
	return 2*y;
}

int main() {

	Righthandside *f;
	f=new GenericFunction (fRhs,gradient);
	cout << f->gradient(3,2) << endl;

	double radius=0.01;
	double initialTime = 0.0;
	double finalTime = 2/radius;
	double initialValue = radius;

	Righthandside * poly;
	poly= new Polynomial<int> (0,0,1,-1);
    cout << poly->value(3,2) << endl;
	AbstractOdeSolver* pSolver = 0;

	int numberstepsAdam = 100;
		pSolver = new ForwardEulerSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);

		std::ofstream eulerSolutionFile("solution_ForwardEuler.dat");
		if (eulerSolutionFile.is_open()) {
				pSolver->SolveEquation(poly,eulerSolutionFile);
				eulerSolutionFile.close();
			}


		pSolver = new TwoStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream twostepSolutionFile("solution_twostep.dat");
				if (twostepSolutionFile.is_open()) {
						pSolver->SolveEquation(poly,twostepSolutionFile);
						twostepSolutionFile.close();
					}

		pSolver = new ThreeStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream ThreeStepSolutionFile("solution_ThreeStep.dat");
		if (ThreeStepSolutionFile.is_open()) {
			pSolver->SolveEquation(poly,ThreeStepSolutionFile);
			ThreeStepSolutionFile.close();
			}

		pSolver = new FourStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream FourStepSolutionFile("solution_FourStep.dat");
		if (FourStepSolutionFile.is_open()) {
			pSolver->SolveEquation(poly,FourStepSolutionFile);
			FourStepSolutionFile.close();
			}

		int numberstepsBack = 1000;
		pSolver = new BackwardEulerSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsBack);
		std::ofstream BackwardEulerSolutionFile("solution_BackwardEuler.dat");
		if (BackwardEulerSolutionFile.is_open()) {
			pSolver->SolveEquation(poly,BackwardEulerSolutionFile);
			BackwardEulerSolutionFile.close();
			}





}

