#ifndef BLACKHOLE_H
#define BLACKHOLE_H
#include <array>
using namespace std;
class BlackHole{
	private:
		/* auxiliary variables for differential equation solving */
		static const double tolerance;
		double E;
		double L;
		double epsilon;
		int nsteps = 100;
		double drdtau(double r);
		double dphidtau(double r);
		double dtdtau(double r);

	public:
		/* Constructor takes initial energy E, intial angular momentum L, and particle type epsilon */
		double M;
		BlackHole(double M);
		void geodesic(int nsteps, double r0, double phi0,  double tau0, double tau1, double energy, double ang_momentum, int particle_type);
		void info();
		double V(double r);

};
#endif	
