#include <iostream>
#include <fstream>
#include "Righthandside.hpp"
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "TwoStepSolver.hpp"
#include "ThreeStepSolver.hpp"
#include "FourStepSolver.hpp"
#include "BackwardEulerSolver.hpp"
#include <cmath>

using namespace std;

double fRhs(double y, double t)
{
	return sin(y);
}

double gradient(double y, double t)
{
	return cos(y);
}

int main() {

	Righthandside f(fRhs);
	cout << f.value(3,2) << endl;

	double initialTime = 0.0;
	double finalTime = 3.0;
	double initialValue = 0.9;



	AbstractOdeSolver* pSolver = 0;

	int numberstepsEuler = 100;
		pSolver = new ForwardEulerSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsEuler);

		std::ofstream eulerSolutionFile("solution_euler.dat");
		if (eulerSolutionFile.is_open()) {
				pSolver->SolveEquation(f,eulerSolutionFile);
				eulerSolutionFile.close();
			}

		int numberstepsAdam = 1000;
		pSolver = new TwoStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream twostepSolutionFile("solution_twostep.dat");
				if (twostepSolutionFile.is_open()) {
						pSolver->SolveEquation(f,twostepSolutionFile);
						twostepSolutionFile.close();
					}

		pSolver = new ThreeStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream ThreeStepSolutionFile("solution_ThreeStep.dat");
		if (ThreeStepSolutionFile.is_open()) {
			pSolver->SolveEquation(f,ThreeStepSolutionFile);
			ThreeStepSolutionFile.close();
			}

		pSolver = new FourStepSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream FourStepSolutionFile("solution_FourStep.dat");
		if (FourStepSolutionFile.is_open()) {
			pSolver->SolveEquation(f,FourStepSolutionFile);
			FourStepSolutionFile.close();
			}

		Righthandside g(fRhs,gradient);

		pSolver = new BackwardEulerSolver;
		pSolver->SetInitialValue(initialValue);
		pSolver->SetTimeInterval(initialTime, finalTime);
		pSolver->SetNumberSteps(numberstepsAdam);
		std::ofstream BackwardEulerSolutionFile("solution_BackwardEuler.dat");
		if (BackwardEulerSolutionFile.is_open()) {
			pSolver->SolveEquation(g,BackwardEulerSolutionFile);
			BackwardEulerSolutionFile.close();
			}





}
