/*
 * TrheeStepSolver.cpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: Class that implements Three Step Adam Bashworts Method to solve a ODE of the form: dy/dt = f(y, t).
 *             It is derived from the abstract class AbstractOdeSolver.
 */


#include <iostream>
#include <cmath>
#include <fstream>
#include "Righthandside.hpp"
#include "ThreeStepSolver.hpp"

ThreeStepSolver::ThreeStepSolver() // Default contructor
{}

ThreeStepSolver::~ThreeStepSolver() // Destructor
{}


void ThreeStepSolver::SolveEquation(Righthandside* f, std::ostream& stream)
{
    // Declaring the variables

    double h, T0, T_final;
    int  n_steps, Nsteps;
    double y_prev1, y_prev2,  y_next, y_prev3;
    double t_prev1, t_prev2, t_next, t_prev3;

    // Initializing the program by declaring initial conditions, time limits and stepsize
    T0 = GetInitialTime();
    T_final = GetFinalTime();
    n_steps =  GetNumberSteps();
    h = (T_final-T0)/n_steps; // Stepsize

    y_prev1 = GetInitialValue();
    t_prev1 = T0;

    stream << t_prev1 << " " << y_prev1 << "\n"; // Printing initial values to file

    y_prev2 = y_prev1 + h * f->value(y_prev1, t_prev1);
    t_prev2 = t_prev1+h;
    stream << t_prev2 << " " << y_prev2 << "\n"; // One iteration of Euler forward to find a second initial value

    y_prev3 = y_prev2 + h * (f->value(y_prev2, t_prev2) * 3/2 - f->value(y_prev1, t_prev1) / 2);
    t_prev3 = t_prev2+h;
    stream << t_prev3 << " " << y_prev3 << "\n"; // One iteration of Two steps Adam Bashworts to find a third initial value

    // Implementing Three Steps Adam Bashword:
    for (int i = 3; i <= n_steps; i++)
    {
        // One iteration of Three Steps Adam Bashword:
        y_next = y_prev3 + h * (f->value(y_prev3, t_prev3) * 23/12 - f->value(y_prev2, t_prev2) * 4/3 + f->value(y_prev1, t_prev1) * 5/12);
        t_next = t_prev3+h;

        stream << t_next << " " << y_next << "\n"; // Printing values to file

        if (isinf(y_next))  // Stops the solver if it reaches infinity.
        {
            std::cout << "<ThreeStepSolver> WARNING: Function Reached infinity at time " << t_next << ", stopping iterations for the four step Adam Bashworts solver." << std::endl;
            return;
        }

        if (isnan(y_next)) // Stops the solver if it returns NaN.
        {
            std::cout << "<ThreeStepSolver> WARNING: Function Returns NaN at time " << t_next << ", stopping iterations for the four step Adam Bashworts solver." << std::endl;
            return;
        }

        y_prev1 = y_prev2;
        t_prev1 = t_prev2;
        y_prev2 = y_prev3;
        t_prev2 = t_prev3;
        y_prev3 = y_next;
        t_prev3 = t_next; // Updating values for the next iteration
    }
}
