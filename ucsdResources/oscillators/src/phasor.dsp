import("stdfaust.lib");

phasor(f)   = f/128 : (+,1.0:fmod) ~ _ ;
process = phasor(1);
