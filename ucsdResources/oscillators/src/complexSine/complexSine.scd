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

harms.do{|harmonic|

  tablesize.do{|i|
    var samp;

    samp = (i*harmonic)/tablesize; // increment from 0 to 1
    samp = samp * 2pi; // scale
    sineTable[i] = sineTable[i] + (sin(samp) * 1/harmonic);
  };
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
