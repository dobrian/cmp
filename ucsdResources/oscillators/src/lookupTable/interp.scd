(
var pts, cubicInterpolator, sineTable, phasor, sr, tablesize, samp, linearInterpolator;

sr = 8000;
tablesize = 16;
samp = 0;

phasor = {|freq, currentVal = 0|
  var inc = freq/sr;
  currentVal = (currentVal + inc).mod(1.0);
};

sineTable = Signal.sineFill(tablesize, [1]);

cubicInterpolator = {|pts, x|
  var a, b, c, d, p0, p1, p2, p3;
  x = x.frac;
  p0 = pts[0];
  p1 = pts[1];
  p2 = pts[2];
  p3 = pts[3];

  a = (-0.5*p0) + (1.5*p1) - (1.5*p2) + (0.5*p3);
  b = p0 - (2.5*p1) + (2*p2) - (0.5*p3);
  c = (-0.5*p0) + (0.5*p2);
  d = p1;

  (a*(x**3)) + (b*(x**2)) + (c*x) + d; // return
};

linearInterpolator = {|idx|
  var frac, diff;

  frac = idx.frac;
  idx = idx.asInteger;
  while(
    {idx > tablesize},
    {
      idx = idx-tablesize;
    }
  );

  if (idx == (tablesize-1)) {
    diff = sineTable[0] - sineTable[idx];
  } {
    diff = sineTable[idx+1] - sineTable[idx];
  };

  sineTable[idx] + (diff*frac);
};

x = 1024.collect{|i|
  var idx, pts;
  // i = 32+i;
  samp = phasor.(100,samp); // make a phasor
  idx = samp*tablesize; // scale
  pts = [idx-1, idx, idx+1, idx+2].mod(tablesize).asInteger; // get the values and wrap
  pts = pts.collect{|i| sineTable[i]}; // get the actual values

  sineTable[idx.asInteger]; // phase truncation
  // linearInterpolator.(idx);
  // cubicInterpolator.(pts, idx);
};
samp = 0;

y = 1024.collect{|i|
  var idx, pts;
  // i = 32+i;
  samp = phasor.(100,samp); // make a phasor
  idx = samp*tablesize; // scale
  pts = [idx-1, idx, idx+1, idx+2].mod(tablesize).asInteger; // get the values and wrap
  pts = pts.collect{|i| sineTable[i]}; // get the actual values

  // sineTable[idx.asInteger]; // phase truncation
  linearInterpolator.(idx);
  // cubicInterpolator.(pts, idx);
};
samp = 0;

z = 1024.collect{|i|
  var idx, pts;
  // i = 32+i;
  samp = phasor.(100,samp); // make a phasor
  idx = samp*tablesize; // scale
  pts = [idx.asInteger-1, idx.asInteger, idx.asInteger+1, idx.asInteger+2].mod(tablesize); // get the values and wrap
  pts = pts.collect{|i| sineTable[i]}; // get the actual values

  // sineTable[idx.asInteger]; // phase truncation
  // linearInterpolator.(idx);
  cubicInterpolator.(pts, idx);
};

// [x,y,z].plot;

f = File.new("~/Documents/jacob/jobs/cmp/ucsdResources/oscillators/src/lookupTable/sineCubic.dat".standardizePath, "w");
z.do{|val|
  f.write(val.asString ++ "\n");
};
f.close;

f = File.new("~/Documents/jacob/jobs/cmp/ucsdResources/oscillators/src/lookupTable/sineLinear.dat".standardizePath, "w");
y.do{|val|
  f.write(val.asString ++ "\n");
};
f.close;

f = File.new("~/Documents/jacob/jobs/cmp/ucsdResources/oscillators/src/lookupTable/sineTrunc.dat".standardizePath, "w");
x.do{|val|
  f.write(val.asString ++ "\n");
};
f.close;

// linearInterpolator.(1.8).postln;


// 1024.collect{|i|
//   var val;
//   samp = phasor.(100, samp);
// }.plot;


)

t = Signal.sineFill(16, [1]);
t.plot
