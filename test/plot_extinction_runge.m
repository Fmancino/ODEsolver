dfclear
load solution_Runge.dat


plot (solution_Runge(:,1),solution_Runge(:,2),'r')
hold on
%axis([0,10,0,5])
xlabel ('time')
ylabel ('y(t)')
title('Plot of the logistic equation whith extinction treshold.')