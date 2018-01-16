#ifndef COSMOLOGY_H
#define COSMOLOGY_H
class EulerSolver{
	private:
		/* auxiliary variables for differential equation solving */
		static const double tolerance;
		double E;
		double L;
		double epsilon;

	public:
		/* Constructor takes initial energy E, intial angular momentum L, and particle type epsilon */
		EulerSolver(double E, double L, double epsilon);

		void print();
		
		double V(double r);

		double drdtau(double r);
		double dphidtau(double r);
		double dtdtau(double r);

		double solve(int nsteps, double r0, double phi0,  double tau0, double tau1);

};
#endif	
