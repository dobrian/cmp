var trem, size, sound, sr, linFreq, opY1L, cutoff, filters, writeFile;

sr = 44100; // samplerate
cutoff = 100; // cutoff in Hx
opY1L = 0.0; // val to save

filters = ();

sound = ();
sound.impulse = [1].extend(2.pow(20).asInteger, 0); // impulse
sound.sf = SoundFile.openRead("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/envelopes/src/amplitude/tremolo/chord.wav");
sound.sig = FloatArray.newClear(sound.sf.numFrames);
sound.sf.readData(sound.sig);

// sound.sig.plot;
// linFreq = (10.pow((cutoff * 3.0) + 1.30103))/sr;
// linFreq = cutoff/sr;

// c = exp(-1.0 * 2pi * linFreq);
// linFreq.postln;
// c.postln;


filters.onePoleLP = {|dict, sound, cutoff, sr|
	var output, coeff, out;
	out = 0;
	coeff = exp((-1*2pi*cutoff)/sr); // coefficient
	coeff.postln;
	output = sound.collect{|samp, i|
		out = (samp * (1-coeff)) + (out * coeff);
	};
	output = output.normalize(-1.0, 1.0); // return the output
};

filters.foAllPass = {|dict, sound, cutoff, sr|
	var output, tf, in1, coeff, out;
	out = 0;
	in1 = 0;
	tf = tan(pi * (cutoff/sr));
	coeff = (tf - 1.0)/(tf + 1.0);
	output = sound.collect{|samp, i|
		out = coeff * samp + in1 - coeff * out;
		in1 = samp;
		out;
	};
	output = output.normalize(-1.0, 1.0); // return the output
};

filters.foLowPass = {|dict, sound, cutoff, sr|
	var output, tf, in1, coeff, out;
	out = 0;
	in1 = 0;
	tf = tan(pi * (cutoff/sr));
	coeff = (tf - 1.0)/(tf + 1.0);
	output = sound.collect{|samp, i|
		// out = (coeff * samp) + in1 - (coeff * out);
		out = (coeff * (samp - in1)) + in1;
		in1 = samp;
		(samp + out) * 0.5; // return
	};
	output = output.normalize(-1.0, 1.0); // return the output
};

filters.foHiPass = {|dict, sound, cutoff, sr|
	var output, tf, in1, coeff, out;
	out = 0;
	in1 = 0;
	tf = tan(pi * (cutoff/sr));
	coeff = (tf - 1.0)/(tf + 1.0);
	output = sound.collect{|samp, i|
		out = (coeff * samp) + in1 - (coeff * out);
		// out = (coeff * (samp - in1)) + in1;
		in1 = samp;
		(samp - out) * 0.5; // return
	};
	output = output.normalize(-1.0, 1.0); // return the output
};

// sound.output = sound.sig.collect{|samp, i|
// 	var out;
// 	out = (samp + (opY1L - samp)) * c;
// 	opY1L = out;
// 	out.postln;
// 	out;
// };

sound.output = filters.foHiPass(sound.impulse, cutoff, sr); // should be phase shift of 90 degrees

f = SoundFile.openWrite("/home/roger/Documents/jacob/jobs/cmp/ucsdResources/filters/src/foAllPass.wav", "WAV", numChannels: 1, sampleRate: 44100);
f.writeData(sound.output.asFloatArray);
f.close;

r = {
	var size = 4096, real, imag, cosTable, complex, freqArray, phaseArray, plotArray;
	real = Signal.newFrom(sound.output[0..size-1]);
	imag = Signal.newClear(size);
	cosTable = Signal.fftCosTable(size);
	complex = fft(real, imag, cosTable);
	plotArray = {
		var max, array;
		max = complex.magnitude[1..2047].maxItem;
		~complex = complex;
		complex.magnitude[1..2047].collect{|val|
			// 20 * log10(val/max); // get it in dB
			val;
		};
	}.value;
	// plotArray.normalize(0.000001, 1).ampdb.plot;
	freqArray = plotArray.normalize(0.000001, 1).ampdb;
	phaseArray = complex.phase[1..2047];
	freqArray.plot;


	f = File.open("../plots/foHP_%Hz.dat".format(cutoff).resolveRelative, "w");
	// freqArray.do{|bin, i| f.write((((i)/2048)*(sr/2)).asString ++ " " ++ bin.asString ++ "\n")};
	plotArray.size.do{|bin, i| f.write((((i)/2048)*(sr/2)).asString ++ " " ++ freqArray[i].asString ++ " " ++ phaseArray[i] ++ " \n")};
	// plotArray.do{|bin, i| f.write(bin.asString ++ "\n")};
	f.close;

}.value;


// [sound.sig, sound.output].plot;


// exp(300)
