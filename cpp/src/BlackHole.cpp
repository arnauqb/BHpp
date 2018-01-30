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
double BlackHole::EnergyConservation ( double r)
{
	return sqrt( pow(drdtau(r),2.) + 2*V(r)); 
}
double BlackHole::LConservation( double r)
{
	return dphidtau(r) * pow(r,2);
}
bool BlackHole::geodesic(int nsteps, double r0, double vr0, double phi0, double tau0, double tau1, double energy, double ang_momentum, int particle_type, string file, bool conserved)
{
	L = ang_momentum;
	E = energy;
	epsilon = particle_type;
	ofstream out;
	ofstream outE;
	out.open(file);
	if(conserved)
	{
		outE.open("ConservedQuantities.out");
		cout << "Energy and Angular Momentum Conservation will be saved at ConservedQuantities.out" << endl;
	}
	double rg = G*M/pow(c,2.);
	r0 = r0*2*rg;
	double h = (tau1-tau0) / (float) nsteps;
	double Results[5];
	cout << "Results will be save at " << file << endl;
	Results[0] = tau0;
	Results[1] = r0;
	Results[2] = vr0;
	Results[3] = phi0;
	Results[4] = tau0;
	out << Results[0] << "\t" << Results[1] << "\t" << Results[2] << "\t" << Results[3] << "\t" << Results[4] << endl;
	for (int i=1; i < nsteps; i++)
	{
		Results[0] += i*h;
		Results[2] += drdtau(Results[1]) * h;
		Results[3] += dphidtau(Results[1]) * h;
		Results[4] += dtdtau(Results[1]) * h;
		Results[1] += Results[2] * h;
		if(Results[1] < 2.*rg)
		{
			cout << "Fallen in the black hole! " << endl;
			return true;
		}
		out << Results[0] << "\t" << Results[1] << "\t" << Results[2] << "\t" << Results[3] << "\t" << Results[4] << endl;
		if(conserved)
		{
			outE << i << "\t" << EnergyConservation( Results[1] ) << "\t" << LConservation(Results[1]) <<  endl;
		}
	}
	out.close();
	if(conserved) outE.close();
	return false;
}

void BlackHole::PlotV(double angmomentum, int particle_type, double r0)
{
	epsilon = particle_type;
	L = angmomentum;
	ofstream out;
	out.open("Veff.out");
	cout << "Effective Potential will be saved at Veff.out" << endl;
	double ri = 2*G*M/pow(c,2.);
	double rf = 5*r0*ri;
	double r=ri;
	for (int i=0; i < 1000; i++)
	{
		r += (rf-ri)/1000;	
		out << r << "\t" <<  V(r) << endl;
	}
	out.close();

}



