/*
 * RungeKutta4Solver.cpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Class that implements 4th order Runge-Kutta method to solve a ODE of the form: dy/dt=f(y,t).
 * 			   It is derived from the abstract class AbstractOdeSolver.
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include "RungeKutta4Solver.hpp"
#include "Righthandside.hpp"

RungeKutta4Solver::RungeKutta4Solver()
{}

RungeKutta4Solver::~RungeKutta4Solver()
{}

void RungeKutta4Solver::SolveEquation(Righthandside* f,std::ostream& stream)
{
	double h, T0, T_final, n_steps ;
	double y_prev,y_next;
	double t_prev,t_next;

	// Initializing the values for the solver
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0) / n_steps; // Stepsize

	y_prev=GetInitialValue();
	t_prev=T0;

	stream << t_prev << " " << y_prev << "\n"; //Printing to file the initial values.

	for (int i = 1; i <= n_steps; ++i) {
		//Runge kutta factors
		double k1 = h * f->value(y_prev, t_prev);
		double k2 = h * f->value(y_prev + 0.5 * k1, t_prev + 0.5 * h);
		double k3 = h * f->value(y_prev + 0.5 * k2, t_prev + 0.5 * h);
		double k4 = h * f->value(y_prev + k3, t_prev + h);

		//One iteration of the runge kutta method
		y_next = y_prev + 1.0/6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
		t_next = t_prev + h;

		stream << t_next << " " << y_next << "\n";

		if (isinf(y_next))  // Stops the solver if it reaches infinity.
		{
			std::cout << "<RungeKutta4Solver> WARNING: Function Reached infinity at time " << t_next << ", stopping iterations for the Runge-Kutta solver." << std::endl;
			return;
		}

		if (isnan(y_next)) // Stops the solver if it returns NaN.
		{
			std::cout << "<RungeKutta4Solver> WARNING:Function Returns NaN at time " << t_next << ", stopping iterations for the Runge-Kutta solver." << std::endl;
			return;
		}


		y_prev = y_next;
		t_prev = t_next; // Updating the values for the next iteration.
	}
}
