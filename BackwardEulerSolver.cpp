
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include "Righthandside.hpp"
#include "BackwardEulerSolver.hpp"

BackwardEulerSolver::BackwardEulerSolver()
{}

BackwardEulerSolver::~BackwardEulerSolver()
{}


void BackwardEulerSolver::SolveEquation(Righthandside* f,std::ostream& stream)
{
	double h, T0, T_final ;
	int n_steps, n_iterations=0;
	double y_prev,y_next, y_newton, diff;
	double t_prev,t_next;

	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps;

	y_prev=GetInitialValue();
	t_prev=T0;

	stream << t_prev << " " << y_prev << "\n";
    diff=1.0;
	for (int i=1; i <=n_steps; i++)
	{
		y_newton=y_prev + h * f->value(y_prev,t_prev);  // initial guess with "euler forward"
		t_next=t_prev+h;
		while (diff>0.01 && n_iterations<10000)
		{
		y_next=y_newton-(y_newton-y_prev-h*f->value(y_newton,t_next))/(1-h*f->gradient(y_newton,t_next));
		//std::cout << y_next << std::endl;
		diff=abs(y_next-y_newton);
		y_newton=y_next;
		n_iterations += 1;
		if (n_iterations==10000)
				{
			std::cout << "ERROR: max number of iterations for Newtons method reached at time: " << t_prev  << std::endl;
			return;
				}
		}
		n_iterations=0;
		diff=1.0;
		stream << t_next << " " << y_next << "\n";
		y_prev=y_next;
		t_prev=t_next;
}
}
