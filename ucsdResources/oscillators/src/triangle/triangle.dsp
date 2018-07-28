import("stdfaust.lib");

phaseInc(f) = f/8000;
phasor(f) = phaseInc(f) : (+,1.0:fmod) ~ _ ;
trunc(n) = n - ma.frac(n);
// triangle(f) = (abs(phasor(f)-0.5) * 4) - 1;
triangle(f) = phasor(f) : (abs(_-0.5) * 4) - 1;

// triangle(f) = (4 * abs(phasor(f) - trunc(phasor(f)+0.5))) - 1;
// triangle(f) = phasor(f) <: abs(_ - floor(_+0.5)) :> (_*4) - 1;

process = triangle(100) : an.rfft_analyzer_magsq(16);
// process = triangle(100);
