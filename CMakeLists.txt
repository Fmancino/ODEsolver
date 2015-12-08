cmake_minimum_required(VERSION 2.6)
project(projectode)

add_executable(main main.cpp Righthandside.cpp AbstractOdeSolver.cpp ForwardEulerSolver.cpp TwoStepSolver.cpp ThreeStepSolver.cpp FourStepSolver.cpp BackwardEulerSolver.cpp GenericFunction.cpp)
add_executable(Extinction Test_logistic_extinction.cpp Righthandside.cpp AbstractOdeSolver.cpp ForwardEulerSolver.cpp TwoStepSolver.cpp ThreeStepSolver.cpp FourStepSolver.cpp BackwardEulerSolver.cpp GenericFunction.cpp)
add_executable(SinCos Test_SinCos.cpp Righthandside.cpp AbstractOdeSolver.cpp ForwardEulerSolver.cpp TwoStepSolver.cpp ThreeStepSolver.cpp FourStepSolver.cpp BackwardEulerSolver.cpp GenericFunction.cpp)