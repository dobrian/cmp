import("stdfaust.lib");

phaseInc(f) = f/8000;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
sawtooth(f) = (phasor(f) * -2) + 1;
process = sawtooth(100) : an.rfft_analyzer_magsq(64);
