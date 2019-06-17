// compressor
var comp = IdentityDictionary.new(know: true), sound = IdentityDictionary.new(know: true), out;

// compressor
comp.add(\rmsSize -> 64);
comp.add(\thresh -> 0.2);
comp.add(\att -> 0.003);
comp.add(\rel -> 0.03);
comp.add(\del -> 150);
comp.add(\gain -> 1);
comp.add(\ratio -> 2);

// sound
sound.add(\sf -> SoundFile.openRead("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord.wav"));
sound.add(\sig -> FloatArray.newClear(sound.at(\sf).numFrames));
sound.at(\sf).readData(sound.at(\sig));
sound.add(\sr -> sound.at(\sf).sampleRate);

// rms function
comp.rms = {|dict, input, array|
	var avg, tmp;
	x = input*input; // square it
	tmp = array.shift(1, x); // add it to the array
	avg = tmp.sum/tmp.size; // avg
	[sqrt(avg), tmp]; // get the square root
};

comp.rmsComp = {|comp, sound|
	var chunk, fac, gain, attCoeff, relCoeff;
	chunk = Array.fill(comp.rmsSize, {rrand(0.5,0.95)}); // buffer for RMS
	gain = 1; // placeholder
	attCoeff = 1 - exp(-1/(sound.sr*comp.att)); // coefficent for the attack
	relCoeff = 1 - exp(-1/(sound.sr*comp.rel)); // coefficent for the release
	fac = 1 - (1/comp.ratio); // get the compression factor

	sound.sig.collect{|x|
		var amp, diff;
		# amp, chunk = comp.rms(x, chunk); // get the rms
		diff = (amp - comp.thresh).clip(0,1); // get the difference
		if(diff>0) {
			// attack
			gain = gain + (attCoeff*((1 - (diff*fac))-gain)); // one pole filter
		} {
			// release
			gain = gain + (relCoeff*(1-gain)); // one pole filter
		};

		// gain;
		x*gain*comp.gain; // calcuate the output
	};
};

comp.rmsCompTest = {|comp, sound|
	var chunk, fac, gain, att, rel, gainFilter, attCoeff, relCoeff;
	chunk = Array.fill(comp.rmsSize, {0}); // buffer for RMS
	gain = 1; // placeholder
	gainFilter = SinglePoleLP(sr: sound.sr); // filter for the gain
	attCoeff = 1 - exp(-1/(sound.sr*comp.att)); // coefficent for the attack
	relCoeff = 1 - exp(-1/(sound.sr*comp.rel)); // coefficent for the release
	fac = 1 - (1/comp.ratio); // get the compression factor

	sound.sig.collect{|x|
		var amp, diff;
		# amp, chunk = comp.rms(x, chunk); // get the rms
		diff = (amp - comp.thresh).clip(0,1); // get the difference
		if(diff>0) {
			// attack
			gainFilter.coeff = attCoeff; // set the coefficent
			gain = gainFilter.compute(1-(diff*fac)); // calculate
		} {
			// release
			gainFilter.coeff = relCoeff; // set the coefficent
			gain = gainFilter.compute(1); // calculate
		};

		gain;
		// x*gain*comp.gain; // calcuate the output
	};
};

comp.peakComp = {|comp, sound|
	var chunk, fac, gain, attCoeff, relCoeff;
	gain = 1; // placeholder
	attCoeff = 1 - exp(-1/(sound.sr*comp.att)); // coefficent for the attack
	relCoeff = 1 - exp(-1/(sound.sr*comp.rel)); // coefficent for the release
	fac = 1 - (1/comp.ratio); // get the compression factor

	sound.sig.collect{|x|
		var amp, diff;
		diff = (x - comp.thresh).clip(0,1); // get the difference
		if(diff>0) {
			// attack
			gain = gain + (attCoeff*((1-(diff*fac))-gain)); // one pole filter
		} {
			// release
			gain = gain + (relCoeff*(1-gain)); // one pole filter
		};

		// gain;
		x*gain*comp.gain; // calcuate the output
	};
};

// out = comp.rmsComp(sound);
out = comp.rmsCompTest(sound);
// out = comp.peakComp(sound);
[out, sound.sig].plot;

// exp(-1/(44100*0.03)) // coefficient in a one pole filter for a time of 0.03
// a = SinglePoleLP.new
a = SinglePoleLP(1 - exp(-1/(44100*0.03)), 44100);
a.coeff
