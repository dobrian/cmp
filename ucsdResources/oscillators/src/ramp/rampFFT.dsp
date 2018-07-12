import("stdfaust.lib");

phaseInc(f) = f/8000;
phasor(f)   = phaseInc(f) : (+,1.0:fmod) ~ _ ;
ramp(f) = (phasor(f)*2)-1;

process = ramp(100) : an.rfft_analyzer_magsq(64);

/*
  Plotting:

  gnuplot
  set boxwidth 0.2
  set style fill solid
  plot "rampFFT.dat" with boxes
*/
