#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include "BlackHole.h"
using namespace std;


/* Class implementation of an Euler solver for the geodesics equations in a Schwarzschild spacetime*/

BlackHole::BlackHole( double Mass )
{
	M = Mass;
	info();
}
void BlackHole::info()
{
	cout << "Created Black Hole with mass M =  " << M << endl;
}

double BlackHole::V(double r)
{
	return epsilon / 2. - epsilon/r + pow(L,2.) / (2. * pow(r,2.)) - pow(L,2.)/pow(r,3.); 
}

double BlackHole::drdtau( double r)
{
	return - sqrt( pow(E,2.) - 2. * V(r) );
}
double BlackHole::dphidtau (double r)
{
	return L / pow(r,2.);
}
double BlackHole::dtdtau (double r)
{
	return E / (1. - 2. / r);
}

void BlackHole::geodesic(int nsteps, double r0, double phi0, double tau0, double tau1, double energy, double ang_momentum, int particle_type)
{
	E = energy;
	L = ang_momentum;
	epsilon = particle_type;
	ofstream out;
	out.open("Geodesic.out");
	cout << "Results will be save at Geodesic.out" << endl;
	double Results[nsteps][4];
	Results[0][0] = tau0;
	Results[0][1] = r0;
	Results[0][2] = phi0;
	Results[0][3] = tau0;
	out << Results[0][0] << "\t" << Results[0][1] << "\t" << Results[0][2] << "\t" << Results[0][3] << endl;
	double deltatau = (tau1-tau0) / (float) nsteps;
	for (int i=1; i < nsteps; i++)
	{
		Results[i][0] = tau0 + i*deltatau;
		Results[i][1] = Results[i-1][1] + drdtau(Results[i-1][1]) * deltatau;
		Results[i][2] = Results[i-1][2] + dphidtau(Results[i-1][1]) * deltatau;
		Results[i][3] = Results[i-1][3] + dtdtau(Results[i-1][1]) * deltatau;
		out << Results[i][0] << "\t" << Results[i][1] << "\t" << Results[i][2] << "\t" << Results[i][3]<< endl;
	}

}



