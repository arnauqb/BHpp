#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include "BlackHole.hpp"
using namespace std;


/* Class implementation of an Euler solver for the geodesics equations in a Schwarzschild spacetime*/

BlackHole::BlackHole( double Mass)
{
	M = Mass*Ms;
	info();
}
void BlackHole::info()
{
	cout << "Created Black Hole with mass M =  " << M << endl;
}

double BlackHole::V(double r)
{
	return epsilon*pow(c,2.) /2. - G * M * epsilon / r + pow(L,2.) / ( 2 * pow(r,2.) ) - G * M * pow(L,2.) / ( pow(c,2.) * pow(r,3.) );
}

double BlackHole::drdtau( double r)
{
	return - G * M * epsilon / pow(r,2.) + pow(L,2.) / pow(r,3.) - 3 * G * M * pow(L,2.) / ( pow(c,2.) * pow(r,4.));
}
double BlackHole::dphidtau (double r)
{
	return L / pow(r,2.);
}
double BlackHole::dtdtau (double r)
{
	return E / (1. - 2. * G * M / ( pow(c,2) * r)) ;
}

void BlackHole::geodesic(int nsteps, double r0, double vr0, double phi0, double tau0, double tau1, double energy, double ang_momentum, int particle_type, string file)
{
	L = ang_momentum;
	E = energy;
	epsilon = particle_type;
	ofstream out;
	out.open(file);
	double rg = G*M/pow(c,2.);
	r0 = 10*rg;
	double deltatau = (tau1-tau0) / (float) nsteps;
	double Results[nsteps][5];
	cout << "Results will be save at Geodesic.out" << endl;
	Results[0][0] = tau0;
	Results[0][1] = r0;
	Results[0][2] = vr0;
	Results[0][3] = phi0;
	Results[0][4] = tau0;
	out << Results[0][0] << "\t" << Results[0][1] << "\t" << Results[0][2] << "\t" << Results[0][3] << "\t" << Results[0][4] << endl;
	for (int i=1; i < nsteps; i++)
	{
		Results[i][0] = tau0 + i*deltatau;
		Results[i][2] = Results[i-1][2] + drdtau(Results[i-1][1]) * deltatau;
		Results[i][1] = Results[i-1][1] + Results[i][2] * deltatau;
		if(Results[i][1] < 2.*rg)
		{
			cout << "Fallen in the black hole! " << endl;
			break;
		}
		Results[i][3] = Results[i-1][3] + dphidtau(Results[i-1][1]) * deltatau;
		Results[i][4] = Results[i-1][4] + dtdtau(Results[i-1][1]) * deltatau;
		out << Results[i][0] << "\t" << Results[i][1] << "\t" << Results[i][2] << "\t" << Results[i][3] << "\t" << Results[i][4] << endl;
	}
	out.close();
}

void BlackHole::PlotV(double angmomentum, double particle_type)
{
	epsilon = particle_type;
	L = angmomentum;
	ofstream out;
	out.open("Veff.out");
	out << "Radius" << "Veff(r)" << endl;
	float r = 2.;
	for (int i=0; i < 1000; i++)
	{
		r += (50.-r)/1000;	
		out << r << V(r) << endl;
	}
	out.close();

}



