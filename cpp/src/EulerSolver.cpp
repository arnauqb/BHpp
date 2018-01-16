#include <iostream>
#include <cmath>
#include <array>
#include "EulerSolver.h"
using namespace std;


/* Class implementation of an Euler solver for the geodesics equations in a Schwarzschild spacetime*/

EulerSolver::EulerSolver(double Epsilon, double energy, double angular_momentum)
{
	epsilon = Epsilon;
	E = energy;
	L = angular_momentum;
	print();
}
void EulerSolver::print()
{
	cout << "Initializing Euler Solver with E = " << E << ", L = " << L << ", and epsilon = " << epsilon << "..." << endl;  

}

double EulerSolver::V(double r)
{
	return epsilon / 2. - epsilon/r + pow(L,2.) / (2 * pow(r,2.)) - pow(L,2)/pow(r,3); 
}

double EulerSolver::drdtau( double r)
{
	return - sqrt( pow(E,2.) - 2 * pow(V(r),2.) );
}
double EulerSolver::dphidtau (double r)
{
	return L / pow(r,2.);
}
double EulerSolver::dtdtau (double r)
{
	return E / (1. - 2 / r);
}

array EulerSolver::solve(int nsteps, double r0, double phi0, double tau0, double tau1)
{
	double Results[nsteps][3];
	Results[0][0] = r0;
	Results[0][1] = phi0;
	Results[0][2] = tau0;
	double deltatau = (tau1-tau0) / (float) nsteps;
	for (int i=1; i < nsteps; i++)
	{
		Results[i][0] = Results[i-1][0] + drdtau(Results[i-1][0]) * deltatau;
		Results[i][1] = Results[i-1][1] + dphidtau(Results[i-1][1]) * deltatau;
		Results[i][2] = Results[i-1][2] + drdtau(Results[i-1][2]) * deltatau;

	}

}



