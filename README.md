## A simple analysis code for muon track analysis from TIFR 1 m x 1 m stack 

# Detector parameters:
 * Size: 1 m x 1 m
 * Strips: 32 on each plane
 * No. of RPCs: 12

In short, the code takes as input, the data from the stack and calculates quantities like:

 * Angular distribution (both zenith and azimuth)
 * Tracking efficiency
 * Strip hit multiplicity

Instructions to run:

* After initializing ROOT by sourcing the right `thisroot.sh` file,
* compile the code `main.cpp` using 
    * g++  `root-config --glibs --cflags` ino_analysis.cpp main.cpp
    * Run the programme using `./a.out`
    * The file analyzes the input file `INORUN_20161230_161712.ire` (can be changed in `main.cpp`)
    * In the analysis, a straight line is fit to muon track from which the slope and intercepts of the 2 projections are estimated. From the slopes and the intercepts, the angle of arrival is then computed.
    * The output is stored in `out.fit` (can be changed in `ino_analysis.cpp`)
    * The angle is stored as a branch in the output file: angle.zen and angle.azi
    * Please write to deepaksamuel@cuk.ac.in in case of any questions.


