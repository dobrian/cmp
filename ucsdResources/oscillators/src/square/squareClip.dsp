import("stdfaust.lib");

phaseInc(f) = f/8000;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
ramp(f) = (phasor(f)*2)-1;
clip(v, minima, maxima) = max(minima, min(maxima, v));
square(f) = clip(ramp(f)*9999999, -1, 1);

process = square(100) : an.rfft_analyzer_magsq(16);
