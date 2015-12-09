/*
 * ODESolver.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: This header groups toghether all the needed header files to use this ODE library,
 *			   it's the only header the user needs to include to access all the functionalities.
 *			   Underneath there is also a description of the library for code documentation.
 */


#include "Righthandside.hpp"
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "TwoStepSolver.hpp"
#include "ThreeStepSolver.hpp"
#include "FourStepSolver.hpp"
#include "BackwardEulerSolver.hpp"
#include "RungeKutta4Solver.hpp"
#include "GenericFunction.hpp"
#include "Polynomial.hpp"
#include "SinCos.hpp"

/** \mainpage
 ** Library for solving differential equations of the type dy/dt=f(y,t). It can handle non-linear differential equation of first order. <br>
 *  It has three different ways of inputting the righandside function f(y,t), which are all implemented as subclasses of the abstract class "righthandside":
 *
 * 1)As a pointer to a Generic User defined function, though the use of the "GenericFunction" class. The user can specify f(y,t) and its gradient. <br>
 * 2)As a generic polynomial function of maximum grade 4, with the use of "Polynomial" class. The function must be of the form: a+b*y+c*y^2+d*y^3+e*y^4 <br>
 * 3)As a function including a sine and a cosine of the form: a*sin(c*y)+b*cos(d*y). This is done with the "SinCos" class. <br>
 *
 * Six different solvers can be used, all programmed as derived classes from the "AbstractOdeSolver" class:
 *
 * 1)"ForwardEulerSolver": Solves the differential equation using forward Euler method <br>
 * 2)"BackwardEulerSolver":  Solves the differential equation using backward Euler method <br>
 * 3)"TwostepSolver": Solves the differential equation using two step Adam Bashforth method <br>
 * 4)"ThreestepSolver": Solves the differential equation using three step Adam Bashforth method <br>
 * 5)"FourstepSolver": Solves the differential equation using four step Adam Bashforth method <br>
 * 6)"RungeKutta4Solver": Solves the differential equation using fourth order Runge-Kutta method <br>
 *
 *
 * The library was developed by Francesco Mancino as a project for the course "Programming concepts in scientific computing" at EPFL.
 *
 * Contact: francesco.mancino@EPFL.ch
 *
 */
