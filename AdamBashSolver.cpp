#include "AdamBashSolver.hpp"

#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include "Righthandside.hpp"

void AdamBashSolver::SolveEquation(Righthandside f,std::ostream& stream)
{
	double h, T0, T_final;
	int  n_steps, Nsteps ;
	double y_prev1, y_prev2,  y_next;
	double t_prev1, t_prev2, t_next;
	T0 = GetInitialTime();
	T_final = GetFinalTime();
	n_steps =  GetNumberSteps();
	h=(T_final-T0)/n_steps;

	y_prev1=GetInitialValue();
	t_prev1=T0;
	stream << t_prev1 << " " << y_prev1 << "\n";

	y_prev2=y_prev1 + h * f.value(y_prev1,t_prev1);
	t_prev2=t_prev1+h;
	stream << t_prev2 << " " << y_prev2 << "\n";

	Nsteps = GetNumAdamSteps();

	if (Nsteps==2)
	{
	for (int i=2; i <=n_steps; i++)
	{
		y_next = y_prev2 + h * (f.value(y_prev2,t_prev2)*3/2 - f.value(y_prev1,t_prev1)/2);
		t_next=t_prev2+h;
		stream << t_next << " " << y_next << "\n";
		y_prev1 = y_prev2;
		t_prev1 = t_prev2;
		y_prev2=y_next;
		t_prev2=t_next;
	}
	}
	else if (Nsteps==3)
	{
		double y_prev3, t_prev3;
		y_prev3 = y_prev2 + h * (f.value(y_prev2,t_prev2)*3/2 - f.value(y_prev1,t_prev1)/2);
		t_prev3=t_prev2+h;
		stream << t_prev3 << " " << y_prev3 << "\n";
		for (int i=3; i <=n_steps; i++)
		{
			y_next = y_prev3 + h * (f.value(y_prev3,t_prev3)*23/12-f.value(y_prev2,t_prev2)*4/3 + f.value(y_prev1,t_prev1)*5/12);
			t_next=t_prev2+h;
			stream << t_next << " " << y_next << "\n";
			y_prev1 = y_prev2;
			t_prev1 = t_prev2;
			y_prev2 = y_prev3;
			t_prev2 = t_prev3;
			y_prev3=y_next;
			t_prev3=t_next;
		}
	}
	else if (Nsteps==4)
		{
			double y_prev3, t_prev3;
			y_prev3 = y_prev2 + h * (f.value(y_prev2,t_prev2)*3/2 - f.value(y_prev1,t_prev1)/2);
			t_prev3=t_prev2+h;
			stream << t_prev3 << " " << y_prev3 << "\n";
			double y_prev4, t_prev4;
			y_prev4 = y_prev3 + h * (f.value(y_prev3,t_prev3)*23/12-f.value(y_prev2,t_prev2)*4/3 + f.value(y_prev1,t_prev1)*5/12);
			t_prev4 = t_prev4 + h;
			stream << t_prev4 << " " << y_prev4 << "\n";
			for (int i=4; i <=n_steps; i++)
			{
				y_next = y_prev4 + h * (f.value(y_prev4,t_prev4)*55/24-f.value(y_prev3,t_prev3)*59/24+f.value(y_prev2,t_prev2)*37/24- f.value(y_prev1,t_prev1)*3/8);
				t_next=t_prev2+h;
				stream << t_next << " " << y_next << "\n";
				y_prev1 = y_prev2;
				t_prev1 = t_prev2;
				y_prev2 = y_prev3;
				t_prev2 = t_prev3;
				y_prev3 = y_prev4;
				t_prev3 = t_prev4;
				y_prev4=y_next;
				t_prev4=t_next;
			}
		}
	else
	{
	 std::cout << "specify correct number of steps for the Adams–Bashforth method" << std::endl;
	}
}

void AdamBashSolver::SetNumAdamSteps(int N)
{
	NumAdamSteps=N;
}

int AdamBashSolver::GetNumAdamSteps()
{
	return NumAdamSteps;
}

