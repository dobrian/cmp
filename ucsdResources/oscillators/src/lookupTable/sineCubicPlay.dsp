declare name "Sinewave Lookup - Cubic Interpolation";
declare copyright "(c) Jacob Sundstrom";

import("stdfaust.lib");

ml = library("music.lib");
pi = 4.0*atan(1.0);
sr = ma.SR;
tablesize = 1 << 10; // 1024 table size
// tablesize = 16;

makeInt(n) = n - ma.frac(n);

phaseInc(f) = f/sr;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ; // a phasor
counter = ba.countup(tablesize, 0); // count up

table(index) = rdtable(tablesize, sinwaveform, index); // the table of the sine

linearInterp(index) = table(int(index)) + ((table(int(index)) - table(int(index+1) % (tablesize-1))) * ma.frac(index));

p0(index) = table((index-1)%tablesize);
p1(index) = table(index);
p2(index) = table((index+1)%tablesize);
p3(index) = table((index+2)%tablesize);

a(index) = (-0.5*p0(index)) + (1.5*p1(index)) - (1.5*p2(index)) + (0.5*p3(index));
b(index) = p0(index) - (2.5*p1(index)) + (2*p2(index)) - (0.5*p3(index));
c(index) = (-0.5*p0(index)) + (0.5*p2(index));
d(index) = p1(index);

term1(index) = a(int(index)) * (ma.frac(index)^3);
term2(index) = b(int(index)) * (ma.frac(index)^2);
term3(index) = c(int(index)) * ma.frac(index);
term4(index) = d(int(index));

// cubicInterp(index) = (a(int(index))*((ma.frac(index)**3))) + (b(int(index))*(ma.frac(index)**2)) + (c(int(index))*ma.frac(index)) + d(int(index)); // return
cubicInterp(index) = term1(index) + term2(index) + term3(index) + term4(index);


sinwaveform = float(counter)*(2.0*ma.PI)/float(tablesize) : sin; // function to fill the table

freq = hslider("freq[unit: Hz][scale: exp]", 100, 10, 10000, 10) : si.smoo;
gain = hslider("gain[style:dB]", -6, -90, 0, 1) : si.smoo : ba.db2linear;
index = phasor(freq) * (tablesize-1); // make the index


// process = table(int(index)); // phase truncation
// process = linearInterp(index); // linear interpolation
process = cubicInterp(index) * gain; // linear interpolation
// process = int(index); // linear interpolation
