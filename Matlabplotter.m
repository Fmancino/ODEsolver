clc;
close all;


load solution_ForwardEuler.dat
load solution_BackwardEuler.dat
load solution_twostep.dat
load solution_threestep.dat
load solution_fourstep.dat

figure
plot (solution_ForwardEuler(:,1),solution_ForwardEuler(:,2),solution_BackwardEuler(:,1),solution_BackwardEuler(:,2),solution_twostep(:,1),solution_twostep(:,2),...
    solution_threestep(:,1),solution_threestep(:,2),solution_fourstep(:,1),solution_fourstep(:,2))
legend('ForwardEuler','BackwardEuler','Twostep','Threestep','Fourstep')
axis([0,10,-10,10])