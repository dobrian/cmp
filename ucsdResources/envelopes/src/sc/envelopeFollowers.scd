(
var inc = 0.01;
z = 0;
p = Pbrown(0.001,0.05, 0.005, inf).asStream;
b = Pbrown(0.0, 1.0, 0.01, inf).asStream;
a = 16384.collect{|i|
	z = z+inc;
	if(z>1) {z=0; inc = p.next};
	sin(2pi*z);
};
a = a.collect{|x|
	x*b.next;
};
a = a.normalize;

a.plot;
);
~newSignal = (~signal.normalize*1.9999);
~newSignal = ~newSignal - (~newSignal.sum/~newSignal.size);
~newSignal.plot

f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/signal.dat", "w");
~newSignal.do{|x| f.write(x.asString ++ "\n");};
f.close;

// use the mean
(
a = Array.fill(128, {0.0});
z = 0; // position in the array
m = {|x|
	// rectify
	if(x<0) {x = -1*x};

	// add to the array
	// a.shift(1, x);
	a[z] = x;
	z = (z+1)%a.size; // increment

	// get the average
	a.sum/a.size;
};
c = ~newSignal.collect{|i|
	m.(i);
};
f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/mean_128.dat", "w");
c.do{|x| f.write(x.asString ++ "\n")};
f.close;
[~newSignal,c].plot;
)

// rms
(
a = Array.fill(1024, {0.0});
r = {|x|
	var avg;
	// square it
	x = x*x;

	// add it to an array and get the mean
	a = a.shift(1, x);
	avg = a.sum/a.size;

	// get the square root
	sqrt(avg);
};
c = ~newSignal.collect{|x| r.(x)};
f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/rms_1024.dat", "w");
c.do{|x| f.write(x.asString ++ "\n")};
f.close;
[~newSignal,c].plot;

)

// attack and release
(
z = 0; // peak
r = {|x, attack = 1, release = 1|
	var attackMultiplier, releaseMultiplier, sr;
	sr = 22050; // samplerate

	x = x.abs;

	attackMultiplier = 0.01**(1/(attack*sr));
	releaseMultiplier = 0.01**(1/(release*sr));

	if(x>z) {
		z = (attackMultiplier * (z*x)) + x;
	} {
		z = (releaseMultiplier * (z*x)) + x;
	};
	z; // return
};
c = ~newSignal.collect{|x| r.(x, 0.1, 0.1)};
[~newSignal,c].plot;
)

a = Signal.sineFill(256, [1], [0])
p = Pbrown(0.0, 1.0, 0.1, inf).asStream;
b = 100.collect{a*p.next}.flat;
b.plot
b = b.normalize


[b,c].plot
