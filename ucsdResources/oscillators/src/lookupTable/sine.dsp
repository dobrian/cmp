import("stdfaust.lib");

ml = library("music.lib");
pi = 4.0*atan(1.0);
sr = 1024;
tablesize = 1 << 10; // 1024 table size
// tablesize = 16;

phaseInc(f) = f/sr;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ; // a phasor
counter = ba.countup(tablesize, 0); // count up

table(index) = rdtable(tablesize, sinwaveform, index); // the table of the sine

linearInterp(index) = table(int(index)) + ((table(int(index)) - table(int(index+1) % (tablesize-1))) * ma.frac(index));

sinwaveform = float(counter)*(2.0*ma.PI)/float(tablesize) : sin; // function to fill the table
index = phasor(1) * (tablesize-1); // make the index


// process = table(int(index)); // phase truncation
process = linearInterp(index); // linear interpolation
