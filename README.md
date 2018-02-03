## ODEsolver [![Build Status](https://travis-ci.org/Fmancino/ODEsolver.svg?branch=master)](https://travis-ci.org/Fmancino/ODEsolver)

Library for solving differential equations of the type dy/dt=f(y,t).
It can handle non-linear differential equation of first order.

To access the functionality of the library it is sufficient to include the header file “ODEsolver.hpp”.

There is three different ways of inputting the right hand side function f(y,t), which are all implemented as subclasses of the abstract class "righthandside":

1. As a pointer to a Generic User defined function, through the use of the "GenericFunction" class. The user can specify f(y,t) and its gradient.
2. As a generic polynomial function of maximum grade 4, with the use of "Polynomial" class. The function must be of the form: a+b*y+c*y^2+d*y^3+e*y^4
3. As a function including a sine and a cosine of the form: a*sin(c*y)+b*cos(d*y). This is done with the "SinCos" class.


Six different solvers can then be used, all programmed as derived classes from the "AbstractOdeSolver" class:

1. "ForwardEulerSolver": Solves the differential equation using forward Euler method.
2. "BackwardEulerSolver":  Solves the differential equation using backward Euler method.
3. "TwostepSolver": Solves the differential equation using two step Adam Bashforth method.
4. "ThreestepSolver": Solves the differential equation using three step Adam Bashforth method.
5. "FourstepSolver": Solves the differential equation using four step Adam Bashforth method.
6. "RungeKutta4Solver": Solves the differential equation using fourth order Runge-Kutta method.

To understand how to use the library, three test files are provided:

1. "Test_extinction.cpp": Test all the different solvers, and the "Polynomial" input.
2. "Test_logistic_regression.cpp": Test three solvers, and the "GenericFunction" input.
3. "Test_SinCos.cpp": Test two solvers, and the "SinCos" input method.

The results will be printed on .dat files, and can be plotted using the software preferred by the user.
 Matlab files plotting the results from the test files are in the documentation.


The library was developed by Francesco Mancino as a project for the course "Programming concepts in scientific computing" at EPFL.

 Contact: francescomancino1@gmail.com
