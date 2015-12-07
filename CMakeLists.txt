cmake_minimum_required(VERSION 2.6)
project(projectode)

add_executable(main main.cpp Righthandside.cpp AbstractOdeSolver.cpp ForwardEulerSolver.cpp TwoStepSolver.cpp ThreeStepSolver.cpp FourStepSolver.cpp BackwardEulerSolver.cpp GenericFunction.cpp)