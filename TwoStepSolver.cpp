#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include "Righthandside.hpp"
#include  "TwoStepSolver.hpp"

TwoStepSolver::TwoStepSolver()
{}

TwoStepSolver::~TwoStepSolver()
{}

void TwoStepSolver::SolveEquation(Righthandside* f,std::ostream& stream)
{
	double h, T0, T_final;
	int  n_steps, Nsteps ;
	double y_prev1, y_prev2,  y_next;
	double t_prev1, t_prev2, t_next;
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps;

	y_prev1=GetInitialValue();
	t_prev1=T0;
	stream << t_prev1 << " " << y_prev1 << "\n";

	y_prev2=y_prev1 + h * f->value(y_prev1,t_prev1);
	t_prev2=t_prev1+h;
	stream << t_prev2 << " " << y_prev2 << "\n";

	for (int i=2; i <=n_steps; i++)
	{
		y_next = y_prev2 + h * (f->value(y_prev2,t_prev2)*3/2 - f->value(y_prev1,t_prev1)/2);
		t_next=t_prev2+h;
		stream << t_next << " " << y_next << "\n";
		y_prev1 = y_prev2;
		t_prev1 = t_prev2;
		y_prev2=y_next;
		t_prev2=t_next;
	}
}
