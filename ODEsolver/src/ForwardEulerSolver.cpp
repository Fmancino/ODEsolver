/**
 * ForwardEulersolver.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Forward Eulers method to solve a ODE of the form: dy/dt=f(y,t).
 * It is derived from the abstract class AbstractOdeSolver.
 */

#include <cmath>
#include <fstream>
#include <iostream>
#include "ForwardEulerSolver.hpp"
#include "Righthandside.hpp"

ForwardEulerSolver::ForwardEulerSolver() //Constructor
{}

ForwardEulerSolver::~ForwardEulerSolver() //Destructor
{}


void ForwardEulerSolver::SolveEquation(Righthandside* f,std::ostream& stream)
{
	double h, T0, T_final, n_steps ;
	double y_prev,y_next;
	double t_prev,t_next;

	// Initializing the values for the solver
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps; // Stepsize

	y_prev=GetInitialValue();
	t_prev=T0;

	stream << t_prev << " " << y_prev << "\n"; //Printing to file the initial values.

	for (int i=1; i <=n_steps; i++)
	{
		y_next = y_prev + h * f->value(y_prev,t_prev); //Approximation of the next value of the function with Eulers forward method.
		t_next=t_prev + h; // Updating the time

		stream << t_next << " " << y_next << "\n"; //Printing to file the function values.


		if (isinf(y_next))  // Stops the solver if it reaches infinity.
		{
			std::cout << "<ForwardEulerSolver> WARNING: Function Reached infinity at time " << t_next << ", stopping iterations for the forward Euler solver." << std::endl;
			return;
		}

		if (isnan(y_next)) // Stops the solver if it returns NaN.
		{
			std::cout << "<ForwardEulerSolver> WARNING:Function Returns NaN at time " << t_next << ", stopping iterations for the forward Euler solver." << std::endl;
			return;
		}


		y_prev = y_next;
		t_prev = t_next; // Updating the values for the next iteration.
	}
}
