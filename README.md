# BH++
BH++ is an Euler-Cromer integrator written in C++ to numerically calculate the geodesic equations for a scalar black hole. 

Table of contents
=================

  * [Requirements](#Requirements)
  * [Build](#Build)
  * [Usage](#usage)
  * [Tests](#tests)
  
  
## Requirements
```shell
git (optional)
make
g++
```
## Build
```shell
$ git clone https://github.com/arnauq/BHpp.git
$ cd BHpp
$ make
```
## Usage
```console
Usage: bhg [command flags]

USAGE: 

   ./bhg  [-g] [-C] [-V] [-n <int>] [-T <double>] [-t <double>] [-p
          <double>] [-v <double>] [-r <double>] [-E <double>] [-L <double>]
          [-M <double>] [-f <string>] [--] [--version] [-h]


Where: 

   -g,  --photon
     If flagged, the incoming particle is a photon.
 Default: False

   -C,  --Cons
     If flagged, return a file containing the Energy and Angular Momentum
     at each iteration.
     Default: False

   -V,  --Veff
     If flagged, return a file containing the effective potential as a
     function of radius.
     Default: False

   -n <int>,  --steps <int>
     Number of time steps
 Default: 10000

   -T <double>,  --t1 <double>
     Final time in seconds.
 Default: 1000

   -t <double>,  --t0 <double>
     Initial time in seconds.
 Default: 0

   -p <double>,  --initialphi <double>
     Initial angle
 Default: 0

   -v <double>,  --initialv <double>
     Initial radial velocity
 Default: 0

   -r <double>,  --initialr <double>
     Initial radius in units of Schwarzschild radius.
 Default: 10

   -E <double>,  --energy <double>
     Energy of the incoming particle
 Default: c^2

   -L <double>,  --angmom <double>
     Angular momentum of the incoming particle
 Default: 0

   -M <double>,  --mass <double>
     Black Hole mass in solar units.
 Default: 1

   -f <string>,  --file <string>
     File where to save the geodesic data. 
 Default: Geodesic.out

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.
```

## Tests
Photon geodesics

![Photons](https://raw.githubusercontent.com/arnauq/BHpp/master/photons.png)

Particle geodesics

![Particles](https://raw.githubusercontent.com/arnauq/BHpp/master/massive.png)

Solar System

![SolarSystem](https://raw.githubusercontent.com/arnauq/BHpp/master/SolarSystem.png)
