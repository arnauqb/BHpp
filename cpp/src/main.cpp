#include <iostream>
#include "BlackHole.h"
using namespace std;

int main (void)
{
	BlackHole BH(1.);
	BH.geodesic(100, 10, 0, 1, 10, 1, 2, 1);
	return 0;
}
