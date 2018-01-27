#include <iostream>
#include <tclap/CmdLine.h>
#include "BlackHole.hpp"
#include <cmath>
using namespace std;

int main (int argc, char** argv)
{
	double c = 299792458.;
	TCLAP::CmdLine cmd ("Black Hole Geodesics calculator", ' ', "1.0");
  	TCLAP::ValueArg<string> file_tclap("f","file","File where to save the geodesic data. \n Default: Geodesic.out",false,"Geodesic.out","string",cmd);
	TCLAP::ValueArg<double> M_tclap("M","mass","Black Hole mass in solar units.\n Default: 1", false, 1.,"double",cmd);
	TCLAP::ValueArg<double> L_tclap("L","angmom","Angular momentum of the incoming particle\n Default: 0", false, 0., "double", cmd);
	TCLAP::ValueArg<double> E_tclap("E","energy","Energy of the incoming particle\n Default: c^2", false, pow(c,2.), "double", cmd);
	TCLAP::ValueArg<double> r0_tclap("r","initialr","Initial radius in units of Schwarzschild radius.\n Default: 10", false, 10., "double", cmd);
	TCLAP::ValueArg<double> vr0_tclap("v","initialv","Initial radial velocity\n Default: 0", false, 0., "double", cmd);
	TCLAP::ValueArg<double> phi0_tclap("p","initialphi","Initial angle\n Default: 0", false, 0., "double", cmd);
	TCLAP::ValueArg<double> tau0_tclap("t","t0","Initial time in seconds.\n Default: 0", false, 0., "double", cmd);
	TCLAP::ValueArg<double> tau1_tclap("T","t1","Final time in seconds.\n Default: 1000", false, 1000., "double", cmd);
	TCLAP::ValueArg<int> n_tclap("n","steps","Number of time steps\n Default: 10000", false, 10000, "int", cmd);
	TCLAP::SwitchArg PlotV_tclap("V","Veff","If flagged, return a file containing the effective potential as a function of radius.\n Default: False", cmd, false);
	TCLAP::SwitchArg photon_tclap("g","photon","If flagged, the incoming particle is a photon.\n Default: False", cmd, false);
	cmd.parse(argc,argv);

	double M = M_tclap.getValue();
	double E = E_tclap.getValue();
	double L = L_tclap.getValue();
	double r0 = r0_tclap.getValue();
	double vr0 = vr0_tclap.getValue();
	double phi0 = phi0_tclap.getValue();
	double tau0 = tau0_tclap.getValue();
	double tau1 = tau1_tclap.getValue();
	bool fallen = false;
	int n = n_tclap.getValue();
	bool PlotV = PlotV_tclap.getValue();
	bool photon = photon_tclap.getValue();
	int eps = 1;
	if (photon)
	{
		eps = 0;	
	}
	string file = file_tclap.getValue();
	BlackHole BH(M);
	fallen = BH.geodesic(n, r0, vr0, phi0, tau0, tau1, E, L, eps, file);
	if(PlotV)
	{
		BH.PlotV(L, eps);
	}
	if (fallen)
	{
		return 1;
	}
	return 0;
}
