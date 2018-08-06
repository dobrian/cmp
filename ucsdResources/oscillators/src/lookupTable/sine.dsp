import("stdfaust.lib");

ml = library("music.lib");
pi = 4.0*atan(1.0);
sr = 8000;
tablesize = 1 << 10; // 1024 table size
// tablesize = 16;

phaseInc(f) = f/8000;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
counter = ba.countup(tablesize, 0);

table(index) = rdtable(tablesize, sinwaveform, index);

linearInterp(index) = table(int(index)) + ( ( table(int(index)) - table(int(index+1) % (tablesize-1))  ) * ma.frac(index) );


// sine(f) = rdtable(tablesize, sinwaveform, int(phasor(f)*tablesize) );
sinwaveform = float(counter)*(2.0*ma.PI)/float(tablesize) : sin;

// process = sine(100);
index = phasor(100) * (tablesize-1);
// process = linearInterp(index);
process = table(int(index)) + (ma.frac(index) * (table(int(index+1) % (tablesize-1)) - table(int(index)) ));

// process = table(int(index));

// process = ((table(int(index)) - table(int(index+1) % (tablesize-1))  ) * ma.frac(index));
// process = table(int(idx)) - table(int(idx+1 % (tablesize-1))) * ma.frac(idx);


 // process = float(counter)*(2.0*ma.PI)/float(tablesize) : sin;
// process = float(counter)*(2.0*pi)/float(tablesize) : sin;
// process = int(phasor(1)*tablesize);
