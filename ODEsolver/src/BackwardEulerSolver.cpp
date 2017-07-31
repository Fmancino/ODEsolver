/*
 * BackwardEulersolver.cpp
 *
 * Created on: Dic, 2015
 *
 *     Author: Francesco Mancino
 *
 *Description: Class that implements Backward Eulers method to solve a ODE of the form: dy/dt=f(y,t).
 * It is derived from the abstract class AbstractOdeSolver.
 * To Solve the equation arising due to the fact that Backward Eulers method is implicit,
 * Newtons method is used if the gradient is specified and the secant method is used it the gradient is not specified.
 */

#include <iostream>
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

	// Initializing the program.
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps;  // Stepsize h

	y_prev=GetInitialValue();
	t_prev=T0;

	stream << t_prev << " " << y_prev << "\n"; //Writing to file the starting values for t and y.

	if (f->GetGradientInfo() == true) //Checking if we have a specified gradient to apply Newtons method
	{
    diff=1.0; // Difference between the values obtained in every iteration of Newtons Method. To make the Algoritm start it has to be initialized with a value bigger than 0.01.
	for (int i=1; i <=n_steps; i++)
	{
		y_newton=y_prev + h * f->value(y_prev,t_prev);  // Initial guess with "Euler forward" method.
		t_next=t_prev + h; //Update of the time

		while (diff>0.001 && n_iterations<10000)
		{
		y_next = y_newton - (y_newton - y_prev - h * f->value(y_newton,t_next)) / (1 - h * f->gradient(y_newton,t_next)); // Iteration of Newtons method
		diff = std::abs (y_next - y_newton); // Difference between the values obtained in every iteration of Newtons Method, used as a convergence criterion.
		y_newton=y_next;
		n_iterations += 1;
		if (n_iterations==10000)
				{
			std::cout << "<Backwardeulersolver> ERROR: Max number of iterations for Newtons method reached at time: " << t_prev  << ". The Backward Euler solver will stop." << std::endl;
			return;
				}
		}

		if (isinf(y_next))  // Stops the solver if it reaches infinity.
				{
					std::cout << "<Backwardeulersolver> ERROR:  Function Reached infinity at time " << t_next << ", stopping iterations for the Backward Euler solver." << std::endl;
					return;
				}

		if (isnan(y_next)) // Stops the solver if it returns NaN.
				{
					std::cout << "<Backwardeulersolver> ERROR:Function Returns NaN at time " << t_next << ", stopping iterations for the Backward Euler solver."<< std::endl;
					return;
				}


		n_iterations=0;
		diff=1.0;
		stream << t_next << " " << y_next << "\n";
		y_prev=y_next;
		t_prev=t_next;
	}
	}
	else //Apply Secant method when gradient is not specified.
	{
		std::cout << "<Backwardeulersolver> WARNING: Gradient is not specified, the results are going to be estimated using the secant method. "  << std::endl;
		double y_newton1,y_newton2;
		{
		    diff=1.0; // Difference between the values obtained in every iteration of Newtons Method. To make the Algoritm start it has to be initialized with a value bigger than 0.01.
			for (int i=1; i <=n_steps; i++)
			{
				y_newton1=y_prev + 3/4 * h * f->value(y_prev,t_prev);
				y_newton2=y_prev + 5/4 * h * f->value(y_prev,t_prev);
				t_next=t_prev+h; //Update of the time

				if (y_newton1==y_newton2) // f->value(y_prev,t_prev)==0
					y_newton1=y_newton2+0.005; //introduce "little" offset, just slightly bigger than the convergence criterion
				while (diff>0.001 && n_iterations<10000)
				{
				// Iteration of secant method:
				y_next=(y_newton2 * (y_newton1 - y_prev - h * f->value(y_newton1,t_next)) - y_newton1 * (y_newton2 - y_prev - h * f->value(y_newton2,t_next))) / ((y_newton1 - y_prev - h * f->value(y_newton1,t_next)) - (y_newton2 - y_prev - h * f->value(y_newton2,t_next)));
				diff= std::abs (y_next - y_newton1); // Difference between the values obtained in every iteration of Newtons Method, used as a convergence criterion.

				y_newton2=y_newton1;
				y_newton1=y_next;

				n_iterations += 1;
				if (n_iterations==10000)
						{
					std::cout << "<Backwardeulersolver> ERROR: Max number of iterations for Newtons method reached at time: " << t_prev  << ". The Backward Euler solver (secant) will stop." << std::endl;
					return;
						}
				}

				if (isinf(y_next))  // Stops the solver if it reaches infinity.
						{
							std::cout << "<Backwardeulersolver> ERROR:  Function Reached infinity at time " << t_next << ", stopping iterations for the Backward Euler solver (secant)." << std::endl;
							return;
						}

				if (isnan(y_next)) // Stops the solver if it returns NaN.
						{
							std::cout << "<Backwardeulersolver> ERROR:Function Returns NaN at time " << t_next << ", stopping iterations for the Backward Euler solver (secant)."<< diff << std::endl;
							return;
						}

				n_iterations=0;
				diff=1.0;
				stream << t_next << " " << y_next << "\n";
				y_prev=y_next;
				t_prev=t_next;
			}
		}
	}
}
