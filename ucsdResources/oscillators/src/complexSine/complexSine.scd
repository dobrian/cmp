(
var pts, cubicInterpolator, sineTable, phasor, sr, tablesize, samp, linearInterpolator, harms;

sr = 8000;
tablesize = 256;
samp = 0;
harms = Array.series(20,1);

phasor = {|freq, currentVal = 0|
  var inc = freq/sr;
  currentVal = (currentVal + inc).mod(1.0);
};

// sineTable = Signal.sineFill(tablesize, [1]);
sineTable = Array.fill(tablesize, {0});


tablesize.do{|i|
  var samp;

  samp = i/tablesize; // increment from 0 to 1
  samp = samp * 2pi; // scale
  // sineTable[i] = sineTable[i] + (sin(samp));
  sineTable[i] = cos(samp) - sin(samp);
};

sineTable = sineTable.normalize;

// tablesize.do{|i|
//   var samp;
//
//   samp = i/tablesize; // increment from 0 to 1
//   samp = samp * 2pi; // scale
//
//   samp.postln;
//   sineTable[i] = sin(samp);
// };


// 1024.collect{|i|
//   var idx, pts;
//   // i = 32+i;
//   samp = phasor.(100,samp); // make a phasor
//   idx = samp*tablesize; // scale
//
// };

sineTable.plot;

)



(
var freqAngle, real, imag, sinZ, cosZ, freq, array, sr, sampInt;

sr = 8000;
sampInt = 1/sr;
array = Array.fill(sr*5, {0});
freq = 2; // Hz

sinZ = 0.0;
cosZ = 1.0;


freqAngle = 2pi * freq; // scale


array.size.do{|samp|
  var val;
  samp = samp * sampInt;
  freqAngle = 2pi * samp;
  real = cos(freqAngle*samp);
  imag = sin(2pi * (freq*samp));

  val = (real*sinZ) - (imag*cosZ);
  cosZ = (real*cosZ) + (imag*sinZ);
  sinZ = val;
  if(sinZ > 1.0) {sinZ = 1.0};
  array[samp] = val;
};


array.plot;


)







(
var angularFreq, phaseOffset, sr, time;

time = 1; // time to accure into an array
sr = 8000;
angularFreq = 2pi; // advancement of the 'spoke' in radians per second
phaseOffset = 0;

a = (time*sr).collect{|i|
  t = i/sr;
  [cos((angularFreq*t) + phaseOffset), sin((angularFreq*t) + phaseOffset)];
}.flop;

a.plot;
)




a.plot
