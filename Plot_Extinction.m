%Plotting results for the logistc equation whith extinction threshold.
%The data is taken from the execution of "Test_logistic_extincton.cpp".

clc;
close all;


load solution_ForwardEuler.dat
load solution_BackwardEuler.dat
load solution_twostep.dat
load solution_threestep.dat
load solution_fourstep.dat
load solution_BackwardEulerSecant.dat
load solution_Runge.dat

figure
plot (solution_ForwardEuler(:,1),solution_ForwardEuler(:,2),solution_twostep(:,1),solution_twostep(:,2),...
    solution_threestep(:,1),solution_threestep(:,2),solution_fourstep(:,1),solution_fourstep(:,2),solution_BackwardEuler(:,1),solution_BackwardEuler(:,2),...
solution_Runge(:,1),solution_Runge(:,2),solution_BackwardEulerSecant(:,1),solution_BackwardEulerSecant(:,2))
legend('ForwardEuler','Twostep','Threestep','Fourstep','Runge-Kutta','BackwardEuler','BackwardEulerSecant')
axis([0,10,0,5])
xlabel ('time')
ylabel ('y(t)')
title('Plot of the logistic equation whith extinction treshold.')
%ylim([0,1.5])