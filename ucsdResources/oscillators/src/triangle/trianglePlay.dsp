declare name "Non-bandlimted Triangle";
declare copyright "(c) Jacob Sundstrom";

import("stdfaust.lib");

phaseInc(f) = f/ma.SR;
phasor(f) = phaseInc(f) : (+,1.0:fmod) ~ _ ;
trunc(n) = n - ma.frac(n);
// triangle(f) = (abs(phasor(f)-0.5) * 4) - 1;
triangle(f) = phasor(f) : (abs(_-0.5) * 4) - 1;

// triangle(f) = (4 * abs(phasor(f) - trunc(phasor(f)+0.5))) - 1;
// triangle(f) = phasor(f) <: abs(_ - floor(_+0.5)) :> (_*4) - 1;

freq = hslider("freq[unit: Hz][scale: exp]", 100, 10, 10000, 10) : si.smoo;
gain = hslider("gain[style:dB]", -6, -90, 0, 1) : si.smoo : ba.db2linear;

process = triangle(freq) * gain;
// process = triangle(100);
