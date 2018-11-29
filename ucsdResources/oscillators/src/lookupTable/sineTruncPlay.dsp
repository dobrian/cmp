declare name "Sinewave Lookup - Truncation";
declare copyright "(c) Jacob Sundstrom";

import("stdfaust.lib");

ml = library("music.lib");
pi = 4.0*atan(1.0);
sr = ma.SR;
tablesize = 1 << 10; // 1024 table size
// tablesize = 16;

phaseInc(f) = f/sr;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ; // a phasor
counter = ba.countup(tablesize, 0); // count up

table(index) = rdtable(tablesize, sinwaveform, index); // the table of the sine

linearInterp(index) = table(int(index)) + ((table(int(index)) - table(int(index+1) % (tablesize-1))) * ma.frac(index));
trunc(index) = table(int(index));

sinwaveform = float(counter)*(2.0*ma.PI)/float(tablesize) : sin; // function to fill the table

freq = hslider("freq[unit: Hz][scale: exp]", 100, 10, 10000, 10) : si.smoo;
gain = hslider("gain[style:dB]", -6, -90, 0, 1) : si.smoo : ba.db2linear;

index = phasor(freq) * (tablesize-1); // make the index


// process = table(int(index)); // phase truncation
process = trunc(index) * gain; // linear interpolation
