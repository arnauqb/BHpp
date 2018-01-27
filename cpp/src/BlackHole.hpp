#ifndef BLACKHOLE_H
#define BLACKHOLE_H
#include <array>
using namespace std;
class BlackHole{
	private:
		/* auxiliary variables for differential equation solving */
		double G = 6.67408e-11;
		double Ms = 1.9884754153381438e30;
		double c = 299792458.;
		static const double tolerance;
		double epsilon = 1;
		int nsteps = 100;
		double drdtau(double r);
		double dphidtau(double r);
		double dtdtau(double r);

	public:
		/* Constructor takes initial energy E, intial angular momentum L, and particle type epsilon */
		double M;
		double E;
		double L;
		BlackHole(double M);
		bool geodesic(int nsteps, double r0, double vr0, double phi0,  double tau0, double tau1, double energy, double ang_momentum, int particle_type, string file);
		void info();
		double V(double r);
		void PlotV(double angmomentum, double particle_type);

};
#endif	
