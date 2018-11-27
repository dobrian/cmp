declare name "Non-bandlimited Sawtooth";
declare copyright "(c) Jacob Sundstrom";

import("stdfaust.lib");

phaseInc(f) = f/ma.SR;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
ramp(f) = (phasor(f)* -2) + 1;

freq = hslider("freq[unit: Hz][scale: exp]", 100, 10, 10000, 10) : si.smoo;
gain = hslider("gain[style:dB]", -6, -90, 0, 1) : si.smoo : ba.db2linear;

process = ramp(freq) * gain;
