import("stdfaust.lib");

phaseInc(f) = f/128;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
process = phasor(1);
