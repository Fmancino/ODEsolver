#include <cassert>
#include <cmath>
#include <fstream>
#include "ForwardEulerSolver.hpp"
#include "Righthandside.hpp"

void ForwardEulerSolver::SolveEquation(Righthandside f,std::ostream& stream)
{
	double h, T0, T_final, n_steps ;
	double y_prev,y_next;
	double t_prev,t_next;
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps;

	y_prev=GetInitialValue();
	t_prev=T0;
	stream << t_prev << " " << y_prev << "\n";

	for (int i=1; i <=n_steps; i++)
	{
		y_next = y_prev + h * f.value(y_prev,t_prev);
		t_next=t_prev+h;
		stream << t_next << " " << y_next << "\n";
		y_prev = y_next;
		t_prev = t_next;
	}
}
