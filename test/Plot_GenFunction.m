%Plotting the results from "Test_GenericFunction.cpp"

clc;
close all;


load solution_Runge_Gen.dat
load solution_BackwardEulerSecantGen.dat
load solution_BackwardGen.dat


figure
plot (solution_Runge_Gen(:,1),solution_Runge_Gen(:,2),solution_BackwardGen(:,1),solution_BackwardGen(:,2),solution_BackwardEulerSecantGen(:,1),solution_BackwardEulerSecantGen(:,2))
legend('Runge-Kutta','BackwardEuler','BackwardEulerSecant')
legend('Funge-Kutta','Backward Euler','Backward Euler secant')
xlabel ('time')
ylabel ('y(t)')
title('Plot of the results from "Test_GenericFunction.cpp".')
%axis([0,10,0,5])

