%Plotting the results from "Test_SinCos" 

clc;
close all;


load solution_Simple_Cos.dat
load solution_Simple_Sinus.dat
load solution_Sincos.dat
load solution_SinCos_Backward.dat

figure
plot (solution_Simple_Cos(:,1),solution_Simple_Cos(:,2),solution_Simple_Sinus(:,1),solution_Simple_Sinus(:,2),solution_Sincos(:,1),solution_Sincos(:,2),solution_SinCos_Backward(:,1),solution_SinCos_Backward(:,2))
legend('Cos','Sin','SinCos','SinCosBackward')
xlabel ('time')
ylabel ('y(t)')
title('Plot of the results from "Test_SinCos".')
axis([0,10,0,10])