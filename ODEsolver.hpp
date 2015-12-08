/*
 * ODESolver.hpp
 * Created on: Dic, 2015
 *     Author: Francesco Mancino
 *Description: This header groups toghether all the needed header files to use this ODE library,
 *			   it's the only header the user needs to include to access all the functionalities.
 */


#include "Righthandside.hpp"
#include "AbstractOdeSolver.hpp"
#include "ForwardEulerSolver.hpp"
#include "TwoStepSolver.hpp"
#include "ThreeStepSolver.hpp"
#include "FourStepSolver.hpp"
#include "BackwardEulerSolver.hpp"
#include "GenericFunction.hpp"
#include "Polynomial.hpp"
#include "SinCos.hpp"
