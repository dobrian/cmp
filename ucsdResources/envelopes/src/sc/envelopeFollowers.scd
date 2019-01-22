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
a = Buffer.readChannel(s, "/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/78888__oasyntax__170-funky-drummer.wav", channels: [0])
a = a.normalize
a.loadToFloatArray(action: {|array| ~newSignal = array});


~newSignal = 16384.collect{|i| rand2(1.0)*b.next}; // noise
~newSignal.plot
~newSignal = ~newSignal.collect{|val|
	val*b.next;
};
~newSignal = ~newSignal.normalize

f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/funkyDrummer.dat", "w");
~newSignal.do{|x| f.write(x.asString ++ "\n");};
f.close;


~newSignal = File.readAllString("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/signal.dat").split(Char.nl).collect{|str| str.asFloat};

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
f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/funkyDrummer/mean_128.dat", "w");
c.do{|x| f.write(x.asString ++ "\n")};
f.close;
[~newSignal,c].plot;
)

// rms
(
for(4, 8, {|i|
	i = 2.pow(i).asInteger;
	a = Array.fill(i, {0.0});
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
	f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/funkyDrummer/rms_%.dat".format(i), "w");
	c.do{|x| f.write(x.asString ++ "\n")};
	f.close;
	// [~newSignal,c].plot;
});

)

4 5 6 7 8

// attack and release
(
z = 0; // peak
r = {|x, attack = 1, release = 1|
	var attackMultiplier, releaseMultiplier, sr;
	sr = 8096; // samplerate

	x = x.abs;

	attackMultiplier = 0.01**(1/(attack*sr));
	releaseMultiplier = 0.01**(1/(release*sr));

	if(x>z) {
		z = (attackMultiplier * (z-x)) + x;
	} {
		z = (releaseMultiplier * (z-x)) + x;
	};
	z; // return
};
c = ~newSignal.collect{|x| r.(x, 0.1, 0.1)};
// f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/attackRelease_16384.dat", "w");
// c.do{|x| f.write(x.asString ++ "\n")};
// f.close;
[~newSignal,c].plot;
)

// other one Tom sent
(
var att, dec;
z = 0; // peak
r = {|x, attackF = 100, releaseF = 100|
	var attackMultiplier, releaseMultiplier, sr;
	sr = 8192; // samplerate

	// rectify
	if(x<0) {x = -1*x};

	attackMultiplier = exp((-6.283185307179586 * attackF)/sr);
	releaseMultiplier = exp((-6.283185307179586 * releaseF)/sr);

	if(x>z) {
		z = (attackMultiplier * (z-x)) + x;
	} {
		z = (releaseMultiplier * (z-x)) + x;
	};
	z; // return
};

att = 100;
dec = 20;
c = ~newSignal.collect{|x| r.(x, att, dec)};


f = File.open("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/envFollowers/funkyDrummer/attackRelease_%-%.dat".format(att, dec), "w");
c.do{|x| f.write(x.asString ++ "\n")};
f.close;
[~newSignal,c].plot;
)

a = Signal.sineFill(256, [1], [0])
p = Pbrown(0.0, 1.0, 0.1, inf).asStream;
b = 100.collect{a*p.next}.flat;
b.plot
b = b.normalize

exp(1)

[b,c].plot
